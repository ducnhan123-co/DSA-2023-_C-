#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};

typedef struct node NODE;
typedef NODE *TREE;

void Khoi_Tao_Cay(TREE &t)
{
	t=NULL;
}
void Tao_Node(TREE &t,int x)
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
			Tao_Node(t->pLeft,x);
		}
		else if(t->data<x)
		{
			Tao_Node(t->pRight,x);
		}
	}
}

void Duyet_LNR(TREE t)
{
	if(t!=NULL)
	{
		Duyet_LNR(t->pLeft);
		cout<<t->data<<" ";
		Duyet_LNR(t->pRight);
	}
	
}
void liet_ke_cac_phan_tu_thoa_dieu_kien_khoang(TREE t,int x,int y)
{
	if(t!=NULL)
	{
		if(t->data >=x && t->data <=y)
		{
			cout <<t->data <<" ";
		}
		liet_ke_cac_phan_tu_thoa_dieu_kien_khoang(t->pLeft,x,y);
		liet_ke_cac_phan_tu_thoa_dieu_kien_khoang(t->pRight,x,y);
	}
}
int main()
{
	TREE t;
	Khoi_Tao_Cay(t);
	Tao_Node(t,8);
	Tao_Node(t,3);
	Tao_Node(t,1);
	Tao_Node(t,5);
	Tao_Node(t,20);
	Tao_Node(t,15);
	Tao_Node(t,30);
	Duyet_LNR(t);
	
	int x,y;
	cout<<"Nhap x : ";
	cin>>x;
	cout<<"Nhap y : ";
	cin>>y;
	liet_ke_cac_phan_tu_thoa_dieu_kien_khoang(t,x,y);
	return 0;
}