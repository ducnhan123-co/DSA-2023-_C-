/* Viết hàm thực hiện các yêu cầu sau 
	a)Hãy đếm số nút của cây 
	b)Cho biết chiều cao cây AVL
	c)Kiểm tra xem T có phải cây nhị phân tìm kiếm không ?
	d)Kiểm tra xem T có phải cây nhị phân cân bằng hoàn toàn không ?
	e)Kiểm tra xem T có phải cây nhị phân cân bằng không ?
	f)Thêm một phần tử vào cây AVl
	g)huỷ một phần tử trên cây AVL
	
	*/


#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;

// Khai báo cấu trúc của một nút trong cây
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Định nghĩa kiểu cây dựa trên cấu trúc Node
typedef struct Node *Tree;

// Khởi tạo cây
void initializeTree(Tree &tree) {
    tree = NULL;
}

// Thêm một nút mới vào cây
void insertNode(Tree &tree, int value) {
    if (tree == NULL) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        tree = newNode;
    } else {
        if (tree->data == value) {
            return; // Giá trị đã tồn tại trong cây
        } else if (tree->data > value) {
            insertNode(tree->left, value); // Thêm vào cây con bên trái
        } else {
            insertNode(tree->right, value); // Thêm vào cây con bên phải
        }
    }
}

// Nhập giá trị để tạo cây
void inputTree(Tree &tree) {
    int value;
    char continueInput;
    do {
        cout << "Nhap gia tri muon them vao cay : ";
        cin >> value;
        insertNode(tree, value);
        cout << "Tiep tuc nhap? (y/n): ";
        cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');
}

// Xuất các giá trị của cây theo thứ tự tăng dần
void printTree(Tree tree) {
    if (tree != NULL) {
        printTree(tree->left);
        cout << tree->data << " ";
        printTree(tree->right);
    }
}

// Đếm số nút lá trong cây
int countLeafNodes(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }
    return countLeafNodes(tree->left) + countLeafNodes(tree->right);
}

// Tính chiều cao của cây AVL
int calculateHeight(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(tree->left);
    int rightHeight = calculateHeight(tree->right);
    return max(leftHeight, rightHeight) + 1;
}

// Kiểm tra xem cây có phải là cây nhị phân tìm kiếm không
bool isBinarySearchTree(Tree tree) {
    // TODO: Viết mã kiểm tra cây nhị phân tìm kiếm
}

// Kiểm tra xem cây có phải là cây nhị phân cân bằng hoàn toàn không
bool isCompleteBinaryTree(Tree tree) {
    // TODO: Viết mã kiểm tra cây nhị phân cân bằng hoàn toàn
}

// Kiểm tra xem cây có phải là cây nhị phân cân bằng không
bool isPerfectBinaryTree(Tree tree) {
    // TODO: Viết mã kiểm tra cây nhị phân cân bằng
}

// Thêm một phần tử vào cây AVL
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


// Xóa một phần tử khỏi cây AVL
void deleteFromAVL(Tree &tree, int value) {
    // TODO: Viết mã xóa một phần tử khỏi cây AVL
}

int main() {
    Tree tree;
    initializeTree(tree);
    
    // Nhập cây
    inputTree(tree);

    // In cây
    cout << "Cay da nhap: ";
    printTree(tree);
    cout << endl;

    // Đếm số nút lá
    int leafCount = countLeafNodes(tree);
    cout << "So nut trong cay: " << leafCount << endl;

    // Tính chiều cao của cây AVL
    int height = calculateHeight(tree);
    cout << "Chieu cao cau avl: " << height << endl;

    // TODO: Gọi các hàm kiểm tra loại cây khác

    return 0;
}