/*Cho cây nhị phân tìm kiếm T,mỗi nút chứa một số nguyên .Hãy viết các hàm thực hiện yêu cầu sau :
	a) đếm số lượng nút nằm ở mức thứ k
	b) in ra tất cả các nút ở mức thứ k của cây T
	c) in ra tất cả các nút theo thứ tự tầng 0 đến tầng h-1 của cây T(h là chiều cao của cây)
	*/
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
typedef NODE* TREE;

void khoi_tao_cay(TREE &t)
{
	t=NULL;
}

void them_phan_tu_vao_cay(TREE &t, int x) {
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

void Dem(TREE t, int k, int &count) {
    if (t != NULL) {
        if (k == 0) {
            cout << t->data << " ";
            count++;
            return;
        }
        Dem(t->pLeft, k - 1, count);
        Dem(t->pRight, k - 1, count);
    }
}
int chieu_cao_cua_cay(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	int height_left=chieu_cao_cua_cay(t->pLeft);
	int height_right=chieu_cao_cua_cay(t->pRight);
	
	return max(height_left,height_right)+1;
}

void in_node_thu_tu_tang_0_tang_h(TREE t, int height) {
    if (t == NULL || height < 0) {
        return;
    }

    if (height == 0) {
        cout << t->data << " ";
    }

    in_node_thu_tu_tang_0_tang_h(t->pLeft, height-1);
    in_node_thu_tu_tang_0_tang_h(t->pRight, height - 1);
}



void nhap_cay(TREE &t)
{
	int x;
	char tt;
	do
	{
		 cout << "Nhap gia tri muon them vao cay: ";
        cin >> x;
        them_phan_tu_vao_cay(t, x);
        cout << "Ban co muon nhap tiep khong? (y/n): ";
        cin >> tt;
	}while (tt=='y' || tt=='Y');
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
	
	int k;
	cout <<"Nhap muc thu k can dem :";
	cin>>k;
    int demk = 0;
    Dem(t, k, demk);
    cout <<"Co : " << demk << " nut o muc thu k "<<endl;
    	
    int height = chieu_cao_cua_cay(t);
    for (int i = 0; i < height; i++) {
        cout << "Node theo thu tu tang " << i << ": ";
        in_node_thu_tu_tang_0_tang_h(t, i);
        cout << endl;
    }
    return 0;	
}
