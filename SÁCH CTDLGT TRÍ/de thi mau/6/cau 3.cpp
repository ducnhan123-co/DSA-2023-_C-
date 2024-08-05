#include <iostream>
#include <algorithm> // S? d?ng std::max
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

void in_tat_ca_cac_nut_o_muc_k(TREE t, int k, int muchientai = 0) {
    if (t == nullptr) {
        return;
    }
    if (muchientai == k) {
        cout << t->data << " ";
    } else {
        in_tat_ca_cac_nut_o_muc_k(t->pleft, k, muchientai + 1);
        in_tat_ca_cac_nut_o_muc_k(t->pright, k, muchientai + 1);
    }
}

int chieu_cao_cay(TREE t) {
    if (t == nullptr) {
        return 0;
    }
    return max(chieu_cao_cay(t->pleft), chieu_cao_cay(t->pright)) + 1;
}

void in_muc(TREE t, int muc) {
    if (t == nullptr) return;
    if (muc == 0) {
        cout << t->data << " ";
    } else {
        in_muc(t->pleft, muc - 1);
        in_muc(t->pright, muc - 1);
    }
}

void in_tat_ca_cac_nut(TREE t) {
    int height = chieu_cao_cay(t);
    for (int i = 0; i < height; ++i) {
        in_muc(t, i);

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
    
    cout << "Duyet cay LNR: ";
    duyet_cay_LNR(t);
    cout << endl;
    
    int k;
    cout << "Nhap muc k can in: ";
    cin >> k;
    cout << "Cac nut o muc " << k << ": ";
    in_tat_ca_cac_nut_o_muc_k(t, k);
    cout << endl;
    
    cout << "In tat ca cac nut tu tang 0 den tang h-1:" << endl;
    in_tat_ca_cac_nut(t);
    
    return 0;
}
