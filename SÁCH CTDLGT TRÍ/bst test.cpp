#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
int demNode(Node* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + demNode(root->left) + demNode(root->right);
}
// Các hàm kiểm tra tính chất của cây BST
bool issubtreelesser(Node *root, int value)
{
	if(root == NULL) return true;
	if(root->data < value && issubtreelesser(root->left, value) && issubtreelesser(root->right, value))
		return true;
	else 
		return false;
}

bool issubtreegreater(Node *root, int value)
{
	if(root == NULL) return true;
	if(root->data > value && issubtreegreater(root->left, value) && issubtreegreater(root->right, value))
		return true;
	else 
		return false;
}

bool isbinarysearchtree(Node *root)
{
    if(root == NULL) return true;
    if(issubtreelesser(root->left, root->data) && issubtreegreater(root->right, root->data) && 
       isbinarysearchtree(root->left) && isbinarysearchtree(root->right))
        return true;
    else 
        return false;
}

bool isbinarysearchtreeuntil(Node *root,int minvalue,int maxvalue)
{
	if(root == NULL) return true;
	if (root->data>minvalue && root->data<maxvalue && isbinarysearchtreeuntil(root->left,minvalue,root->data) && isbinarysearchtreeuntil(root->right,root->data,maxvalue) )
	return true;
	else return false;
}

bool ibstuntil(Node *root)
{
	return isbinarysearchtreeuntil(root,INT_MIN,INT_MAX);
}


// Hàm tạo một node mới
Node* createNode(int data)
{
    Node* newNode = new Node();
    if(!newNode)
    {
        cerr << "Memory error!" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm chèn một node mới vào cây BST
Node* insertNode(Node* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if(data <= root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}
int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int isbalanced(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1; // Không cân bằng, trả về -1
    }
    
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node *root) {
    return height(root) != -1;
}

bool laCayNhiPhanHoanChinh(Node* tree, int index, int soLuongNode) {
    // Nếu cây rỗng, coi như là cây nhị phân hoàn chỉnh
    if (tree == NULL) {
        return true;
    }
    // Nếu chỉ số vượt quá số lượng node, không phải là cây nhị phân hoàn chỉnh
    if (index >= soLuongNode) {
        return false;
    }
    // Kiểm tra cả hai phần tử con của node hiện tại
    return laCayNhiPhanHoanChinh(tree->left, 2 * index + 1, soLuongNode) &&
           laCayNhiPhanHoanChinh(tree->right, 2 * index + 2, soLuongNode);
}

// Hàm chính để kiểm tra xem cây nhị phân có phải là cây nhị phân hoàn chỉnh không
bool laCayNhiPhanHoanChinh(Node* tree) {
    // Đếm số lượng node trong cây
    int soLuongNode = demNode(tree);
    // Sử dụng hàm hỗ trợ để kiểm tra cây nhị phân hoàn chỉnh từ node gốc (index = 0)
    return laCayNhiPhanHoanChinh(tree, 0, soLuongNode);
}
int main()
{
    // Tạo cây nhị phân tìm kiếm
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    // Kiểm tra xem cây có phải là một cây tìm kiếm nhị phân không
    if(isbinarysearchtree(root))
        cout << "Cay la mot cay tim kiem nhi phan." << endl;
    else
        cout << "Cay khong phai la mot cay tim kiem nhi phan." << endl;
        
          // Kiểm tra xem cây có phải là một cây nhị phân hoàn chỉnh không
    if(laCayNhiPhanHoanChinh(root))
        cout << "Cay la mot cay nhi phan hoan chinh." << endl;
    else
        cout << "Cay khong phai la mot cay nhi phan hoan chinh." << endl;

    return 0;
}
Node* deleteTail(Node* head) {
    // If the list is empty, return NULL
    if (head == nullptr) {
        return nullptr;
    }
    // If the list has only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}
