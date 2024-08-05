/* 4-13 Cho một cây nhị phân biểu diễn 1 biểu thức toán học .biết rằng gốc của cây là proot,mỗi nút có thuộc tính key,chứa 1 phép tính (+,-,*,/) hay một giá trị nguyên (nút lá).hãy viết hàm tính giá trị biểu thức chứa trong cây*/
#include<iostream>
#include<limits.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<sstream> // Thêm thư viện này để sử dụng stringstream
using namespace std;

struct node
{
    string data;
    node *pLeft;
    node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void khoi_tao_cay(TREE &t)
{
    t=NULL;
}

void them_phan_tu_vao_cay(TREE &t, string x) {
    if (t == NULL) {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    } else {
        if (x > t->data) {
            them_phan_tu_vao_cay(t->pRight, x);
        } else if (x < t->data) {
            them_phan_tu_vao_cay(t->pLeft, x);
        } else {
            return;
        }
    }
}

void nhap_cay(TREE &t)
{
    string x;
    char tt;
    do
    {
        cout << "Nhap gia tri muon them vao cay: ";
        cin >> x;
        them_phan_tu_vao_cay(t, x);
        cout << "Ban co muon nhap tiep khong? (y/n): ";
        cin >> tt;
    } while (tt=='y' || tt=='Y');
}

bool is_toan_tu(string tt)
{
    return (tt == "+" || tt == "-" || tt == "*" || tt == "/");
}

int tinh_toan_bieu_thuc(TREE t) {
    if (t == NULL) {
        return 0;
    }

    if (t->pLeft == NULL && t->pRight == NULL) {
        int value;
        stringstream(t->data) >> value; // Chuyển đổi từ string sang int
        return value;
    }

    int tinh_left = tinh_toan_bieu_thuc(t->pLeft);
    int tinh_right = tinh_toan_bieu_thuc(t->pRight);

    if (is_toan_tu(t->data)) {
        if (t->data == "+") return tinh_left + tinh_right;
        else if (t->data == "-") return tinh_left - tinh_right;
        else if (t->data == "*") return tinh_left * tinh_right;
        else if (t->data == "/") return tinh_left / tinh_right;
    }

    return 0; // Trả về giá trị mặc định nếu không phải là toán tử hợp lệ
}

void xuat_cay(TREE t)
{
    if (t != NULL)
    {
        xuat_cay(t->pLeft);
        cout << t->data << " ";
        xuat_cay(t->pRight);
    }
}

int main()
{
    TREE t;
    khoi_tao_cay(t);
    nhap_cay(t);
    xuat_cay(t);
    int bieuthuc = tinh_toan_bieu_thuc(t);
    cout << "Ket qua bieu thuc la: " << bieuthuc << endl;

    return 0;
}
