#include <iostream>

using namespace std;

// Định nghĩa cấu trúc cho một node trong đa thức
struct Node {
    double he_so;
    int so_mu;
    Node* tiep_theo;
};

// Hàm để thêm một node vào cuối danh sách
void themNode(Node*& da_thuc, double he_so, int so_mu) {
    Node* node_moi = new Node;
    node_moi->he_so = he_so;
    node_moi->so_mu = so_mu;
    node_moi->tiep_theo = nullptr;

    if (da_thuc == nullptr) {
        da_thuc = node_moi;
        return;
    }

    Node* hien_tai = da_thuc;
    while (hien_tai->tiep_theo != nullptr) {
        hien_tai = hien_tai->tiep_theo;
    }
    hien_tai->tiep_theo = node_moi;
}

// Hàm để cộng hai đa thức
Node* congDaThuc(Node* da_thuc1, Node* da_thuc2) {
    Node* ket_qua = nullptr;
    Node* hien_tai1 = da_thuc1;
    Node* hien_tai2 = da_thuc2;

    while (hien_tai1 != nullptr && hien_tai2 != nullptr) {
        if (hien_tai1->so_mu > hien_tai2->so_mu) {
            themNode(ket_qua, hien_tai1->he_so, hien_tai1->so_mu);
            hien_tai1 = hien_tai1->tiep_theo;
        } else if (hien_tai1->so_mu < hien_tai2->so_mu) {
            themNode(ket_qua, hien_tai2->he_so, hien_tai2->so_mu);
            hien_tai2 = hien_tai2->tiep_theo;
        } else {
            double tong_he_so = hien_tai1->he_so + hien_tai2->he_so;
            themNode(ket_qua, tong_he_so, hien_tai1->so_mu);
            hien_tai1 = hien_tai1->tiep_theo;
            hien_tai2 = hien_tai2->tiep_theo;
        }
    }

    while (hien_tai1 != nullptr) {
        themNode(ket_qua, hien_tai1->he_so, hien_tai1->so_mu);
        hien_tai1 = hien_tai1->tiep_theo;
    }
    while (hien_tai2 != nullptr) {
        themNode(ket_qua, hien_tai2->he_so, hien_tai2->so_mu);
        hien_tai2 = hien_tai2->tiep_theo;
    }

    return ket_qua;
}

// Hàm để in đa thức
void inDaThuc(Node* da_thuc) {
    if (da_thuc == nullptr) {
        cout << "0";
        return;
    }

    Node* hien_tai = da_thuc;
    while (hien_tai != nullptr) {
        cout << hien_tai->he_so << "x^" << hien_tai->so_mu;
        if (hien_tai->tiep_theo != nullptr) {
            cout << " + ";
        }
        hien_tai = hien_tai->tiep_theo;
    }
    cout << endl;
}

int main() {
    // Tạo và nhập các đa thức
    Node* da_thuc1 = nullptr;
    Node* da_thuc2 = nullptr;

    themNode(da_thuc1, 5, 3);
    themNode(da_thuc1, -2, 2);
    themNode(da_thuc1, 1, 0);

    themNode(da_thuc2, 2, 4);
    themNode(da_thuc2, 3, 2);
    themNode(da_thuc2, 6, 1);

    // In các đa thức trước khi cộng
    cout << "Da thuc 1: ";
    inDaThuc(da_thuc1);
    cout << "Da thuc 2: ";
    inDaThuc(da_thuc2);

    // Cộng hai đa thức
    Node* tong = congDaThuc(da_thuc1, da_thuc2);

    // In kết quả sau khi cộng
    cout << "Tong hai da thuc: ";
    inDaThuc(tong);

    return 0;
}
