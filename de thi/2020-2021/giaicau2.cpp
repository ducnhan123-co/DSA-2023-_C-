#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
struct NODE {
    int data;
    NODE *next;
};

NODE *Create_Node(int x) {
    NODE *p = new NODE();
    p->data = x;
    p->next = nullptr;
    return p;
}

void them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(NODE *&head, int x, int i) {
    NODE *p = Create_Node(x);
    if (i == 0) {
        p->next = head;
        head = p;
        return;
    }
    NODE *current = head;
    for (int pos = 0; pos < i - 1; pos++) {
        current = current->next;
    }
    p->next = current->next;
    current->next = p;
}

int tim_va_tra_vi_tru_nut_x(NODE *head, int x) {
    if (head == nullptr) {
        return -1; // Trả về -1 nếu danh sách rỗng
    }

    int i = 0;
    NODE *current = head;
    while (current != nullptr) {
        if (current->data == x) {
            return i; // Trả về vị trí của nút có giá trị x
        }
        current = current->next;
        i++;
    }

    return -1; // Trả về -1 nếu không tìm thấy nút có giá trị x trong danh sách
}

//tính và trả về trung bình cộng các giá trị trong dslk
float trung_binh_cong_so_nguyen(NODE *head)
{
	if(head==nullptr) return 0;
	int dem=0;
	int tong=0;
	for(NODE *current = head;current !=NULL;current=current->next)
	{
		dem++;
		tong +=current->data;
	}
	if(dem==0) return 0;
	return (float)tong/dem;
}

int main() {
    NODE *head = nullptr;
    them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 10, 0);
    them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 20, 1);
    them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 30, 1);
    them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 40, 3);
 them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 5, 3);
  them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head,2, 3);
   them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 11, 3);
    them_nut_co_gia_tri_nguyen_x_vao_vi_tri_i(head, 11, 3);
    NODE *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    int x = 20; // Giá trị cần tìm
    int vitri = tim_va_tra_vi_tru_nut_x(head, x);
    if (vitri != -1) {
        cout << "Vi tri cua nut co gia tri " << x << " la: " << vitri << endl;
    } else {
        cout << "Khong tim thay nut co gia tri " << x << " trong danh sach." << endl;
    }


	float tbc=trung_binh_cong_so_nguyen(head);
	cout<<"Trung binh cong cac so nguyen la : "<<tbc <<endl;
    // Cleanup to avoid memory leaks
    while (head != nullptr) {
        NODE *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
