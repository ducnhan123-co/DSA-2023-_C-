/*
Đề giữa kỳ ctdl gt Trí
Câu 3
a) Xem mỗi đối tượng như là một số nguyên dương(có giá trị là một số nguyên dương,hãy định nghĩa (khai báo) cấu trúc dữ liệu danh sách liên kết đơn LIST (trong c/c++) và viết giải thuật để chèn(thêm) một đối tượng có giá trị k vào cuối của DSLK nếu k là
số chính phương và ngược lại chèn vào đầu danh sách của DSLK nếu k không là số chính phương.
b) Viết một giải thuật để tìm trung bình cộng giá trị của tất cả các nút(đối tượng) trong DSLK LIST có giá trị là số chính phương và lớn hơn a,nhỏ hơn b,với a,b là 2 số nguyên dương cho trước và a<b.
c)giả sử các đối tượng trong DSLK LIST có giá trị đôi một khác nhau,hãy viết một giải thuật để tìm nút trong DSLK LIST mà lưu trữ đối tượng có giá trị lớn nhất,nhưng nhỏ hơn một giá trị k nguyên dương cho trước.
d)Giả sử các đối tượng trong DSLK LIST là các số nguyên khác nhàu,hãy viết một hàm để tìm nút lưu trữ đối tượng có giá trị chính phương nhỏ nhất trong DSLK LIST

*/
#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

struct node
{
    int data;
    node *pnext;
};
typedef struct node NODE;

struct list
{
    NODE *phead;
    NODE *ptail;
};
typedef struct list LIST;

void khoi_tao_danh_sach(LIST &t)
{
    t.phead = t.ptail = NULL;
}

NODE* tao_node(int x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pnext = NULL;
    return p;
}

void chen_vao_cuoi_list(LIST &t, int k)
{
    NODE *p = tao_node(k);
    // Nếu danh sách rỗng
    if (t.ptail == NULL)
    {
        t.phead = t.ptail = p;
    }
    else
    {
        t.ptail->pnext = p;
        t.ptail = p;
    }
}

void chen_vao_dau_list(LIST &t, int k)
{
    NODE *p = tao_node(k);
    // Nếu danh sách rỗng
    if (t.phead == NULL)
    {
        t.phead = t.ptail = p;
    }
    else
    {
        p->pnext = t.phead;
        t.phead = p;
    }
}

bool isSquare(int n)
{
    if (n < 0) return false;
    int r = sqrt(n);
    return r * r == n;
}

void insertNodechinhphuong(LIST &t, int k) {
    NODE *newNode = tao_node(k);
    if(t.phead==NULL)
    {
    	chen_vao_dau_list(t,k);//khi danh sach rong thi chen dau hay cuoi deu giong nhau
	}
    if (isSquare(k)) { // Nếu k là số chính phương
        chen_vao_cuoi_list(t, k);
    } else {
        chen_vao_dau_list(t, k);
    }
}
// Viết một giải thuật để tìm trung bình cộng giá trị của tất cả các nút(đối tượng) trong DSLK LIST có giá trị là số chính phương 
//và lớn hơn a,nhỏ hơn b,với a,b là 2 số nguyên dương cho trước và a<b.
float trung_binh_cong_node_chinh_phuong_doan_a_b(LIST &t,int a,int b)
{
	
	int dem_cp=0;
	int tong_cp=0;
	NODE *p=t.phead;
	while (p!=NULL)
	{
		if( p->data > a && p->data<b && isSquare(p->data) )
		{
			tong_cp+=p->data;
			dem_cp++;
		}
		p=p->pnext;
	}
	if(dem_cp==0)
	{
		return 0;
	}
	return (float)tong_cp/dem_cp;
	
}
//c)giả sử các đối tượng trong DSLK LIST có giá trị đôi một khác nhau,hãy viết một giải thuật để tìm nút trong DSLK LIST mà lưu trữ đối tượng có giá trị lớn nhất,
//nhưng nhỏ hơn một giá trị k nguyên dương cho trước.
NODE *tim_nut_max_nho_hon_nut_k(LIST &t, int k)
{
    NODE *maxnode = NULL;
    NODE *p = t.phead;
    
    while (p != NULL)
    {
        if (p->data < k && (maxnode == NULL || p->data > maxnode->data))
        {
            maxnode = p;
        }
        p = p->pnext;
    }
    return maxnode;
}
//Giả sử các đối tượng trong DSLK LIST là các số nguyên khác nhàu,hãy viết 
//một hàm để tìm nút lưu trữ đối tượng có giá trị chính phương nhỏ nhất trong DSLK LIST
NODE *tim_chinh_phuong_nho_nhat(LIST &t)
{
    NODE *minnode = NULL;
    int min_value = INT_MAX;
    NODE *p = t.phead;

    while (p != NULL)
    {
        if (isSquare(p->data) && p->data < min_value)
        {
            minnode = p;
            min_value = p->data;
        }
        p = p->pnext;
    }

    return minnode;
}

void xuat_danh_sach( LIST &t)
{
    NODE *p = t.phead; // Bắt đầu từ phần tử đầu danh sách
    while (p != NULL)
    {
        cout << p->data << " "; // In giá trị của phần tử hiện tại
        p = p->pnext; // Chuyển đến phần tử tiếp theo trong danh sách
    }
}

int main()
{
    LIST t;
    khoi_tao_danh_sach(t);
    chen_vao_cuoi_list(t, 5);
    chen_vao_cuoi_list(t, 4);
    chen_vao_cuoi_list(t, 2);
    chen_vao_cuoi_list(t, 100);

    insertNodechinhphuong(t, 15);
    insertNodechinhphuong(t, 9);
     insertNodechinhphuong(t, 16);
     insertNodechinhphuong(t, 14);
    xuat_danh_sach(t);
    cout <<endl;
    int a,b;
    cout <<"Nhap doan a : ";
    cin>>a;
    cin.ignore();
    cout <<"Nhap doan b : ";
    cin>>b;
    float tbc = trung_binh_cong_node_chinh_phuong_doan_a_b(t,a,b);
    cout <<tbc <<endl;
    
    
     int k = 38; // Giả sử k = 10
    NODE *maxNode = tim_nut_max_nho_hon_nut_k(t, k);

    // Kiểm tra kết quả
    if (maxNode != NULL) {
        cout << "Nut co gia tri lon nhat nho hon " << 38 << " la: " << maxNode->data << endl;
    } else {
        cout << "Khong co nut nao thoa man dieu kien." << endl;
    }
    
      NODE *nodemin = tim_chinh_phuong_nho_nhat(t);
    if (nodemin != NULL) {
        cout << "Nut co gia tri chinh phuong nho nhat: " << nodemin->data << endl;
    } else {
        cout << "Khong co gia tri nao." << endl;
    }
    return 0;
}
