 /* bài 4.10  Cho cây nhị phân tìm kiếm T,mỗi nút chứa một số nguyên.Hãy viết các hàm thực hiện các yêu cầu sau :
 	a) chiều cao của cây
 	b) tìm độ lệch của cây
 	c) xoá phần tử có giá trị là x trong cây 
 	d) xoá các số nguyên tố ra khỏi cây
 	e) thêm một phần tử có giá trị x vào trong cây để cây vẫn là cây nhị phân tìm kiếm */

#include<iostream>
#include<limits.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};

typedef struct node NODE;
typedef NODE *TREE;
void khoi_tao_cay(TREE &t)
{
	t=NULL;
}

void them_node_vao_cay(TREE &t,int x)
{
	if(t==NULL)
	{
		NODE *p=new NODE;
		p->data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}
	else 
	{
	if(t->data>x)
	{
		them_node_vao_cay(t->pLeft,x);
	}
	else if(t->data<x)
	{
		them_node_vao_cay(t->pRight,x);
	}
	else if(t->data==x)
	{
		return;
	}
}
}
void nhap_cay(TREE &t)
{
    int x;
    char tiep_tuc;
    do
    {
        cout << "Nhap gia tri muon them vao cay: ";
        cin >> x;
        them_node_vao_cay(t, x);
        cout << "Ban co muon nhap tiep khong? (y/n): ";
        cin >> tiep_tuc;
    } while (tiep_tuc == 'y' || tiep_tuc == 'Y');
}
//cau a chiều cao của cây
int chieu_cao_cua_cay(TREE t)
{

	if(t==NULL)
	{
		return 0;
	}
	int chieu_cao_trai=chieu_cao_cua_cay(t->pLeft);
	int chieu_cao_phai=chieu_cao_cua_cay(t->pRight);
	
	return max(chieu_cao_trai,chieu_cao_phai)+1;
}
//câu b
int do_lech_cua_cay(TREE t)
{
	if(t==NULL) return 0;
	if(t!=NULL)
	{
		int chieu_cao_cay_trai=chieu_cao_cua_cay(t->pLeft);
		int chieu_cao_cay_phai=chieu_cao_cua_cay(t->pRight);
		
		int do_lech = abs(chieu_cao_cay_trai-chieu_cao_cay_phai);
		
		int do_lech_trai=do_lech_cua_cay(t->pLeft);
		int do_lech_phai=do_lech_cua_cay(t->pRight);
	
	return max(max(do_lech,do_lech_trai),do_lech_phai);	
	}
}

void di_tim_node_the_mang(TREE &X,TREE &Y)
{
	if (Y->pLeft !=NULL)
	{
		di_tim_node_the_mang(X,Y->pLeft);
	}
	else {
		X->data=Y->data;
		X=Y;
		Y=Y->pRight;
	}
}
// câu c xoá phần tử có giá trị là x trong cây 
void xoa_phan_tu_x(TREE &t, int x) {
    if(t == NULL) {
        return;
    } else {
        if(x > t->data) {
            xoa_phan_tu_x(t->pRight, x);
        } else if(x < t->data) {
            xoa_phan_tu_x(t->pLeft, x);
        } else { // x == t->data
            NODE *data = t;
            if(t->pLeft == NULL) {
                t = t->pRight;
            } else if(t->pRight == NULL) {
                t = t->pLeft;
            } else if(t->pLeft != NULL && t->pRight != NULL) {
                di_tim_node_the_mang(data, t->pRight);
            }
            delete data;
        }
    }
}
bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0) return false;
	}
	return true;
}
void xoa_so_nguyen_to(TREE &t) {
    if(t == NULL) {
        return;
    }
    if(isPrime(t->data)) {
        xoa_phan_tu_x(t, t->data);
    }
    xoa_so_nguyen_to(t->pLeft);
    xoa_so_nguyen_to(t->pRight);
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
	 int height=chieu_cao_cua_cay(t);
	 cout <<"\nChieu cao cua cay vua nhap la : "<< height <<endl;
	 
	 int do_lech_cua_cayT=do_lech_cua_cay(t);
	 cout <<"Do lech cua cay la : "<< do_lech_cua_cayT <<endl;
	 
	 int x;
	 cout <<"Nhap gia tri x can xoa :";
	 cin >>x;
	 xoa_phan_tu_x(t,x);
	 xuat_cay(t);
	 
	 xoa_so_nguyen_to(t);
	xuat_cay(t);
	return 0;
}