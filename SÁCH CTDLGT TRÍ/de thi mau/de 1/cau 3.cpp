#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t) {
    t = NULL;
}

void them_node_vao_cay(TREE &t, int x) {
    if (t == NULL) {
        NODE *p = new NODE;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    } else {
        if (x < t->data) {
            them_node_vao_cay(t->left, x);
        } else if (x > t->data) {
            them_node_vao_cay(t->right, x);
        }
    }
}

void duyet_LNR(TREE t) {
    if (t != NULL) {
        duyet_LNR(t->left);
        cout << t->data << " ";
        duyet_LNR(t->right);
    }
}

void duyet_RNL(TREE t) {
    if (t != NULL) {
        duyet_RNL(t->right);
        cout << t->data << " ";
        duyet_RNL(t->left);
    }
}

int tim_max(TREE t) {
    if (t == NULL) return INT_MIN;
    int max_left = tim_max(t->left);
    int max_right = tim_max(t->right);
    return max(t->data, max(max_left, max_right));
}

int tim_muc(TREE t, int x, int level) {
    if (t == NULL) return -1;
    if (t->data == x) return level;
    int left_level = tim_muc(t->left, x, level + 1);
    if (left_level != -1) return left_level;
    return tim_muc(t->right, x, level + 1);
}

int muc_nut_co_khoa_lon_nhat(TREE t) {
    int max_value = tim_max(t);
    return tim_muc(t, max_value, 0) + 1;
}

void tim_duong_di_do_dai_4(TREE t, int path[], int len) {
    if (t == NULL) return;

    // Thêm nút hiện tại vào đường đi
    path[len] = t->data;
    len++;

    // Nếu đường đi đạt đến độ dài mong muốn, in đường đi
    if (len == 4) {
        for (int i = 0; i < len; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        // Duyệt tiếp các con
        tim_duong_di_do_dai_4(t->left, path, len);
        tim_duong_di_do_dai_4(t->right, path, len);
    }
}

int main() {
    TREE t;
    KhoiTaoCay(t);

    them_node_vao_cay(t, 5);
    them_node_vao_cay(t, 4);
    them_node_vao_cay(t, 9);
    them_node_vao_cay(t, 3);
    them_node_vao_cay(t, 7);
    them_node_vao_cay(t, 10);

    duyet_RNL(t);
    cout << "\nMuc cua nut co khoa lon nhat: " << muc_nut_co_khoa_lon_nhat(t) << endl;
    cout << "Tat ca cac duong di co do dai 4: " << endl;

    int path[1100];
    tim_duong_di_do_dai_4(t, path, 0);

    return 0;
}
