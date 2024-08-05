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
	NODE *pTail;
};
typedef struct list LIST;

NODE *khoi_tao_node(int x)
{
	NODE *p = new NODE;
	if (p == NULL) {
		cout << "Khong du bo nho de cap phat." << endl;
		return NULL;
	}
	p->data = x;
	p->pnext = NULL;
	
	return p;
}

void khoi_tao_danh_sach(LIST &l)
{
	l.phead = NULL;
	l.pTail = NULL;
}

void chen_vao_cuoi(LIST &l, int k)
{
	NODE *p = khoi_tao_node(k);
	if (p == NULL) return;

	if (l.pTail == NULL) {
		l.phead = l.pTail = p;
	}
	else {
		l.pTail->pnext = p;
		l.pTail = p;
	}
}
void dao_nguoc_danh_sach_lien_ket(LIST &l)
{
	NODE *current = l.phead;
	NODE *prev=NULL;
	NODE *next=NULL;
	while(current !=NULL)
	{
		next=current->pnext;
		current->pnext=prev;
		prev=current;
		current=next;
		
	}
l.pTail=l.phead;
l.phead=prev;
	
	
}
void duyet_danh_sach(LIST l)
{
	NODE *p = l.phead;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pnext;
	}
}

int main()
{
	LIST l;
	khoi_tao_danh_sach(l);
	chen_vao_cuoi(l, 5);
	chen_vao_cuoi(l, 4);
	chen_vao_cuoi(l, 9);
	chen_vao_cuoi(l, 1);
	chen_vao_cuoi(l, 19);
	duyet_danh_sach(l);
	dao_nguoc_danh_sach_lien_ket(l);
	cout <<"\nDanh sach sau khi dao nguoc la : "<<endl;
		duyet_danh_sach(l);
	return 0;
}
