#include <iostream>
#include <algorithm> // Sử dụng std::max
using namespace std;

struct node {
    int data;
    node* pleft;
    node* pright;
};

typedef struct node NODE;
typedef NODE* TREE;

void khoi_tao_cay(TREE& t) {
    t = nullptr;
}

void them_phan_tu_vao_cay(TREE& t, int x) {
    if (t == nullptr) {
        NODE* p = new NODE;
        p->data = x;
        p->pleft = nullptr;
        p->pright = nullptr;
        t = p;
    } else {
        if (t->data > x) {
            them_phan_tu_vao_cay(t->pleft, x);
        } else if (t->data < x) {
            them_phan_tu_vao_cay(t->pright, x);
        }
    }
}

void duyet_cay_LNR(TREE t) {
    if (t != nullptr) {
        duyet_cay_LNR(t->pleft);
        cout << t->data << " ";
        duyet_cay_LNR(t->pright);
    }
}

int TimMin(TREE t)
{
	if(t==NULL) return -1; // Trường hợp cây rỗng
	if(t->pleft==NULL)
	{
		return t->data;
	}
	return TimMin(t->pleft);
}

int muc_cua_node_khoa_nho_nhat(TREE t, int value, int muchientai = 0) {
    if (t == NULL) return -1; // Trường hợp cây rỗng

    if (t->data == value) {
        return muchientai; // Trả về mức hiện tại nếu tìm thấy giá trị
    } else if (t->data > value) {
        return muc_cua_node_khoa_nho_nhat(t->pleft, value, muchientai + 1);
    } else {
        return muc_cua_node_khoa_nho_nhat(t->pright, value, muchientai + 1);
    }
}

void in_duong_tu_nut_goc_den_x(TREE t, int x) {
    if (t == NULL) {
        return;
    }
    cout << t->data << " ";
    if (t->data > x) {
        in_duong_tu_nut_goc_den_x(t->pleft, x);
    }
    if (t->data < x) {
        in_duong_tu_nut_goc_den_x(t->pright, x);
    }
    

    
}

int main() {
    TREE t;
    khoi_tao_cay(t);
    them_phan_tu_vao_cay(t, 5);
    them_phan_tu_vao_cay(t, 4);
    them_phan_tu_vao_cay(t, 6);
    them_phan_tu_vao_cay(t, 3);
    them_phan_tu_vao_cay(t, 7);
        them_phan_tu_vao_cay(t, 9);
    cout << "Duyet cay LNR: ";
    duyet_cay_LNR(t);
    cout << endl;
    int min_value = TimMin(t);
    int mucresult = muc_cua_node_khoa_nho_nhat(t, min_value);
    cout << "Muc cua nut co khoa nho nhat : " << mucresult << endl;
 
    int x;
    cout << "Nhap x : ";
    cin >> x;
    in_duong_tu_nut_goc_den_x(t, x);   
    return 0;
}
