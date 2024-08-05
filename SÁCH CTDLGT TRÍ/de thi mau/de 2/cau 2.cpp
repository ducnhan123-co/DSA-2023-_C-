#include<iostream>
using namespace std;

struct node
{
	int data;
	node *pnext;
};
typedef struct node NODE;

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void khoi_tao_danh_sach(LIST &l)
{
	l.pHead=l.pTail=NULL;
}
NODE *tao_node(int x)
{
	NODE *p=new NODE;
	p->data=x;
	p->pnext=NULL;
	return p;
}

void chen_vao_cuoi_list(LIST &l,int k)
{
	NODE *p=tao_node(k);
	if(l.pTail==NULL)
	{
		l.pHead=l.pTail=p;
	}
	else 
	{
		l.pTail->pnext=p;
		l.pTail=p;
	}
	
}

void dao_nguoc_cac_phan_tu_danh_sach(LIST &l) {
    NODE *prev = NULL;
    NODE *current = l.pHead;
    NODE *next = NULL;
    while (current != NULL) {
        next = current->pnext;
        current->pnext = prev;
        prev = current;
        current = next;
    }
    l.pHead = prev; // Cập nhật pHead để trỏ tới phần tử mới đầu tiên (phần tử cũ cuối cùng)
}
void dao_nguoc_cac_phan_tu_danh_sach(LIST &l)
{
	NODE *prev=NULL;
	NODE *current=l.pHead;
	NODE *next=NULL;
	while(current !=NULL)
	{
		next=current->pnext;
		current->pnext=NULL;
		prev=current;
		current=next;
	}
	l.phead=prev;
}
void duyet_danh_sach(LIST l)
{
	NODE *p=l.pHead;
	while(p!=NULL)
	{
		cout<<p->data << " ";
		p=p->pnext;
	}
}
int main()
{
	LIST l;
	khoi_tao_danh_sach(l);
	
	chen_vao_cuoi_list(l,100);
	chen_vao_cuoi_list(l,6);
	chen_vao_cuoi_list(l,7);
	chen_vao_cuoi_list(l,9);
	chen_vao_cuoi_list(l,100);
	chen_vao_cuoi_list(l,1);
	chen_vao_cuoi_list(l,100);
	chen_vao_cuoi_list(l,2);
	duyet_danh_sach(l);
	cout <<"\nDanh sach sau khi dao nguoc : "<<endl;
   	dao_nguoc_cac_phan_tu_danh_sach(l);
   		duyet_danh_sach(l);

	return 0;
}