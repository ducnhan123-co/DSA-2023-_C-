#include <iostream>
#include <cmath>
using namespace std;

/* Tạo cấu trúc dữ liệu cho danh sách liên kết đơn */
struct Node {
    int x; // hệ số
    int i; // số mũ
    Node *pNext;
};

struct SingleList {
    Node *pHead;
    Node *pTail;
};

/* Khởi tạo cho pHead và pTail */
void Initialize(SingleList *&list) {
    list = new SingleList;
    list->pHead = list->pTail = NULL;
}

/* Tạo Node */
Node *CreateNode(int x, int i) {
    Node *pNode = new Node;
    if (pNode == NULL) {
        cout << "Lỗi cấp phát bộ nhớ";
        exit(0);
    }
    pNode->i = i;
    pNode->x = x;
    pNode->pNext = NULL;
    return pNode;
}

/* Chèn vào cuối danh sách liên kết */
void InsertLast(SingleList *&list, int x, int i) {
    Node *pNode = CreateNode(x, i);
    if (list->pTail == NULL)
        list->pHead = list->pTail = pNode;
    else {
        list->pTail->pNext = pNode;
        list->pTail = pNode;   
    }
}

/* Hàm in danh sách liên kết */
void PrintList(SingleList *list) {
    Node *pTmp = list->pHead;
    while (pTmp != NULL) {
        if (pTmp->pNext != NULL)
            cout << pTmp->x << "x^" << pTmp->i << " + ";
        else
            cout << pTmp->x << "x^" << pTmp->i;
        pTmp = pTmp->pNext;
    }
    cout << endl;
}

/* Hàm tính tổng */
double SumOfList(SingleList *list) {
    double sum = 0;
    for (Node *pTmp = list->pHead; pTmp != NULL; pTmp = pTmp->pNext) {
        double value = pow(pTmp->x, pTmp->i);
        sum += value;
    }
    return sum;
}

/* Hàm cộng hai đa thức */
SingleList* AddPolynomials(SingleList *list1, SingleList *list2) {
    SingleList *result;
    Initialize(result);
    Node *p1 = list1->pHead;
    Node *p2 = list2->pHead;

    while (p1 != NULL && p2 != NULL) {
        if (p1->i > p2->i) {
            InsertLast(result, p1->x, p1->i);
            p1 = p1->pNext;
        } else if (p1->i < p2->i) {
            InsertLast(result, p2->x, p2->i);
            p2 = p2->pNext;
        } else {
            InsertLast(result, p1->x + p2->x, p1->i);
            p1 = p1->pNext;
            p2 = p2->pNext;
        }
    }

    while (p1 != NULL) {
        InsertLast(result, p1->x, p1->i);
        p1 = p1->pNext;
    }

    while (p2 != NULL) {
        InsertLast(result, p2->x, p2->i);
        p2 = p2->pNext;
    }

    return result;
}

int main(int argc, char** argv) {
    SingleList *list1, *list2;
    Initialize(list1);
    Initialize(list2);

    // Nhập đa thức thứ nhất
    int n1, x1, i1;
    cout << "Nhap so bac cua da thuc thu nhat: ";
    cin >> n1;
    for (int i = 0; i <= n1; ++i) {
        cout << "Nhap he so va so mu cua bac " << i << ": ";
        cin >> x1 >> i1;
        InsertLast(list1, x1, i1);
    }

    // Nhập đa thức thứ hai
    int n2, x2, i2;
    cout << "Nhap so bac cua da thuc thu hai: ";
    cin >> n2;
    for (int i = 0; i <= n2; ++i) {
        cout << "Nhap he so va so mu cua bac " << i << ": ";
        cin >> x2 >> i2;
        InsertLast(list2, x2, i2);
    }

    cout << "Da thuc thu nhat: ";
    PrintList(list1);

    cout << "Da thuc thu hai: ";
    PrintList(list2);

    SingleList *result = AddPolynomials(list1, list2);
    cout << "Tong hai da thuc: ";
    PrintList(result);

    return 0;
}
