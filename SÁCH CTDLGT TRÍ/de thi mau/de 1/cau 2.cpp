/*Câu II đề số 1 
*/
#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node *next;
};
typedef struct node NODE;

struct list
{
	NODE *phead;
	NODE *ptail;
};
typedef struct list LIST;

void khoi_tao_danh_sach(LIST &l)
{
	l.phead=l.ptail=NULL;
}
NODE *tao_node (int x)
{
	NODE *p=new NODE;
	p->data=x;
	p->next=NULL;
	return p;
}

void chen_vao_cuoi_list(LIST &l, int k)
{
    NODE *p = tao_node(k);
    // Nếu danh sách rỗng
    if (l.ptail == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void duyet_danh_sach(LIST &l)
{
	NODE *p=l.phead;
	while(p!=NULL)
	{
		cout << p->data << " ";
		p=p->next;
	}
}
void tim_so_nguyen_dau_tien_danh_sach(LIST l)
{
	if(l.phead == NULL)
	{
		cout <<"Danh sach khong co so dau tien .";
	}
	else 
	{
		cout << l.phead->data <<endl;
	}
}

bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

void tao_danh_sach_ll_chi_chua_cac_so_nguyen_to_tu_danh_sach_l(LIST &l,LIST &ll)
{
	khoi_tao_danh_sach(ll);
	NODE *p=l.phead;
	while(p!=NULL)
	{
		if(isPrime(p->data))
		{
			chen_vao_cuoi_list(ll,p->data);
		}
		p=p->next;
	}
	
}
void xoa_cac_so_co_gia_tri_lon_nhat(LIST &l)
{
    NODE *p = l.phead;
     NODE *prev = NULL;
    // Tìm giá trị lớn nhất trong danh sách
    int max = l.phead->data;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
//luc nay p la phan tu lon nhat roi
   p = l.phead;//duyet them 1 lan nua?
    while (p != NULL) {
        if (p->data == max) {
            if (prev == NULL) {
                // Nếu nút cần xóa là nút đầu tiên
                NODE *temp = p;
                l.phead = p->next;
                p = p->next;
                delete temp;
            } else {
                // Nếu nút cần xóa không phải là nút đầu tiên
                prev->next = p->next;
              
                delete p;
               p = prev->next;
            }
        } else {
            prev = p;
            p = p->next;
        }
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
	cout <<"\nSo nguyen dau tien trong danh sach la : ";
	 tim_so_nguyen_dau_tien_danh_sach(l);
	 
	 LIST ll;
	 tao_danh_sach_ll_chi_chua_cac_so_nguyen_to_tu_danh_sach_l(l,ll);
	 cout <<"Danh sach ll chi chua cac so nguyen to la : ";
	 duyet_danh_sach(ll);
	 cout <<endl;
	 xoa_cac_so_co_gia_tri_lon_nhat(l);
	 	duyet_danh_sach(l);
	return 0;
	
}