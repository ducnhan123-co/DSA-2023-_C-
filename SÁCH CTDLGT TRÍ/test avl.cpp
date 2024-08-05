#include <iostream>
#include <climits> // Để sử dụng INT_MIN và INT_MAX
using namespace std;

// Định nghĩa cấu trúc Node cho cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Định nghĩa kiểu con trỏ Tree
typedef Node* Tree;

// Hàm chèn một giá trị mới vào cây nhị phân
void insertIntoBinaryTree(Tree &tree, int value) {
    if (tree == NULL) {
        Tree newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        tree = newNode;
    } else {
        if (value <= tree->data) {
            insertIntoBinaryTree(tree->left, value);
        } else {
            insertIntoBinaryTree(tree->right, value);
        }
    }
}

// Hàm kiểm tra cây có phải là cây nhị phân tìm kiếm không
bool isBinarySearchTreeUtil(Tree tree, int minValue, int maxValue) {
    if (tree == NULL) {
        return true;
    }
    if (tree->data < minValue || tree->data > maxValue) {
        return false;
    }
    return isBinarySearchTreeUtil(tree->left, minValue, tree->data - 1) &&
           isBinarySearchTreeUtil(tree->right, tree->data + 1, maxValue);
}

bool isBinarySearchTree(Tree tree) {
    return isBinarySearchTreeUtil(tree, INT_MIN, INT_MAX);
}

// Hàm kiểm tra cây có phải là cây nhị phân cân bằng hoàn toàn không
int countNodes(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

bool isCompleteBinaryTreeUtil(Tree tree, int index, int nodeCount) {
    if (tree == NULL) {
        return true;
    }
    if (index >= nodeCount) {
        return false;
    }
    return isCompleteBinaryTreeUtil(tree->left, 2 * index + 1, nodeCount) &&
           isCompleteBinaryTreeUtil(tree->right, 2 * index + 2, nodeCount);
}

bool isCompleteBinaryTree(Tree tree) {
    int nodeCount = countNodes(tree);
    return isCompleteBinaryTreeUtil(tree, 0, nodeCount);
}

// Hàm kiểm tra cây có phải là cây nhị phân cân bằng không
int countNonLeafNodes(Tree tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL)) {
        return 0;
    }
    return 1 + countNonLeafNodes(tree->left) + countNonLeafNodes(tree->right);
}

bool isPerfectBinaryTreeUtil(Tree tree, int index, int nodeCount) {
    if (tree == NULL) {
        return true;
    }
    if (index >= nodeCount) {
        return false;
    }
    return isPerfectBinaryTreeUtil(tree->left, 2 * index + 1, nodeCount) &&
           isPerfectBinaryTreeUtil(tree->right, 2 * index + 2, nodeCount);
}

bool isPerfectBinaryTree(Tree tree) {
    int nodeCount = countNonLeafNodes(tree) + 1;
    return isCompleteBinaryTree(tree) && isPerfectBinaryTreeUtil(tree, 0, nodeCount);
}

// Các hàm quản lý cây AVL (Thêm và Xóa)
int height(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    return max(height(tree->left), height(tree->right)) + 1;
}

int getBalance(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    return height(tree->left) - height(tree->right);
}

Tree rightRotate(Tree y) {
    Tree x = y->left;
    Tree T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Tree leftRotate(Tree x) {
    Tree y = x->right;
    Tree T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

Tree insertIntoAVLUtil(Tree tree, int value) {
    if (tree == NULL) {
        Tree newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < tree->data) {
        tree->left = insertIntoAVLUtil(tree->left, value);
    } else if (value > tree->data) {
        tree->right = insertIntoAVLUtil(tree->right, value);
    } else {
        return tree;
    }

    int balance = getBalance(tree);

    // Left Left Case
    if (balance > 1 && value < tree->left->data) {
        return rightRotate(tree);
    }

    // Right Right Case
    if (balance < -1 && value > tree->right->data) {
        return leftRotate(tree);
    }

    // Left Right Case
    if (balance > 1 && value > tree->left->data) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    // Right Left Case
    if (balance < -1 && value < tree->right->data) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

void insertIntoAVL(Tree &tree, int value) {
    tree = insertIntoAVLUtil(tree, value);
}

Tree minValueNode(Tree node) {
    Tree current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Tree deleteFromAVLUtil(Tree &tree, int value) {
    if (tree == NULL) {
        return tree;
    }

    if (value < tree->data) {
        tree->left = deleteFromAVLUtil(tree->left, value);
    } else if (value > tree->data) {
        tree->right = deleteFromAVLUtil(tree->right, value);
    } else {
        if (tree->left == NULL || tree->right == NULL) {
            Tree temp = tree->left ? tree->left : tree->right;
            if (temp == NULL) {
                temp = tree;
                tree = NULL;
            } else {
                *tree = *temp;
            }
            delete temp;
        } else {
            Tree temp = minValueNode(tree->right);
            tree->data = temp->data;
            tree->right = deleteFromAVLUtil(tree->right, temp->data);
        }
    }

    if (tree == NULL) {
        return tree;
    }

    int balance = getBalance(tree);

    // Left Left Case
    if (balance > 1 && getBalance(tree->left) >= 0) {
        return rightRotate(tree);
    }

    // Left Right Case
    if (balance > 1 && getBalance(tree->left) < 0) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    // Right Right Case
    if (balance < -1 && getBalance(tree->right) <= 0) {
        return leftRotate(tree);
    }

    // Right Left Case
    if (balance < -1 && getBalance(tree->right) > 0) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

void deleteFromAVL(Tree &tree, int value) {
    tree = deleteFromAVLUtil(tree, value);
}

// Hàm in-order traversal để in các giá trị của cây
void inorderTraversal(Tree tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        cout << tree->data << " ";
        inorderTraversal(tree->right);
    }
}

int main() {
    Tree tree = NULL;

    // Thêm các phần tử vào cây AVL
    insertIntoBinaryTree(tree, 9);
    insertIntoBinaryTree(tree, 5);
    insertIntoBinaryTree(tree, 10);
    insertIntoBinaryTree(tree, 0);
    insertIntoBinaryTree(tree, 6);
    insertIntoBinaryTree(tree, 11);
    insertIntoBinaryTree(tree, -1);
    insertIntoBinaryTree(tree, 1);
    insertIntoBinaryTree(tree, 2);

    // Kiểm tra các tính chất của cây
    cout << "Cay nhi phan tim kiem: " << (isBinarySearchTree(tree) ? "Dung" : "Sai") << endl;
    cout << "Cay nhi phan can bang hoan toan: " << (isCompleteBinaryTree(tree) ? "Dung" : "Sai") << endl;
    cout << "Cay nhi phan can bang: " << (isPerfectBinaryTree(tree) ? "Dung" : "Sai") << endl;

    // In các giá trị của cây bằng in-order traversal
    cout << "Cac gia tri cua cay (theo thu tu tang dan): ";
    inorderTraversal(tree);
    cout << endl;

    // Xóa một phần tử từ cây AVL và kiểm tra lại các tính chất
    deleteFromAVL(tree, 10);
    cout << "Sau khi xoa mot phan tu, cay nhi phan tim kiem: " << (isBinarySearchTree(tree) ? "Dung" : "Sai") << endl;
    cout << "Sau khi xoa mot phan tu, cay nhi phan can bang hoan toan: " << (isCompleteBinaryTree(tree) ? "Dung" : "Sai") << endl;
    cout << "Sau khi xoa mot phan tu, cay nhi phan can bang: " << (isPerfectBinaryTree(tree) ? "Dung" : "Sai") << endl;

    return 0;
}
