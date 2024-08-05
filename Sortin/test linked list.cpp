#include <iostream>
#include<cmath>
#include<limits.h>
using namespace std;

// Cấu trúc của một node
struct node {
    int data;
    node* pnext;
};
typedef struct node NODE;

// Cấu trúc của một danh sách
struct List {
    NODE* phead;
    NODE* pTail;
};
typedef struct List LIST;

// Khởi tạo danh sách
void khoi_tao_list(LIST& l) {
    l.phead = NULL;
    l.pTail = NULL;
}

// Tạo một node mới
NODE* tao_node(int x) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Khong du bo nho de cap phat node moi!\n";
        return NULL;
    }
    p->data = x;
    p->pnext = NULL;
    return p;
}

// Thêm node vào cuối danh sách
void them_vao_cuoi(LIST& l, NODE* p) {
    if (l.phead == NULL) {
        l.phead = l.pTail = p;
    } else {
        l.pTail->pnext = p;
        l.pTail = p;
    }
}

// Hiển thị danh sách
void hien_thi_danh_sach(LIST l) {
    NODE* p = l.phead;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pnext;
    }
    cout << endl;
}

// Hàm tính độ dài danh sách liên kết đơn
int do_dai_list(LIST l) {
    if (l.phead == NULL) {
        return 0;
    }
    int len = 0;
    NODE* p = l.phead;
    while (p != NULL) {
        len++;
        p = p->pnext;
    }
    return len;
}

//hamf xoa 1 nut tai giá trị k
void xoa_tai_1_nut(LIST &l,int x)
{
	if(l.phead==NULL) return;
	
	if(l.phead->data==x)
	{
		NODE *temp=l.phead;
		l.phead=l.phead->pnext;
		if(l.phead==NULL)
		{
			l.pTail=NULL;
		}
		delete temp;
		return;	
	}
	
	NODE *p=l.phead;
	while(p->pnext!=NULL && p->pnext->data!=x)
	{
		p=p->pnext;
	}
	NODE *temp=p->pnext;
	p->pnext=temp->pnext;	
	if(temp==l.phead)
	{
		l.pTail=p;
	}
	delete temp;
		
}

void xoa_cac_nut_nho_hon_k(LIST &l,int k)
{
	if(l.phead==NULL) return;
	while(l.phead!=NULL && l.phead->data<k)
	{
		NODE *temp=l.phead;
		l.phead=l.phead->pnext;
		delete temp;
	}
	 if (l.phead == NULL) {
        l.pTail = NULL;
        return;
    }
    
    NODE *p=l.phead;
    while(p->pnext!=NULL)
    {
    	if(p->pnext->data<k)
    	{
    		NODE *temp=p->pnext;
    		p->pnext=temp->pnext;
    		delete temp;
		}
		else
		{
			p=p->pnext;
		}
	}
    
    
    
}



int main() {
    LIST l;
    khoi_tao_list(l);

    // Thêm một số phần tử vào danh sách
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> x;
        NODE* p = tao_node(x);
        them_vao_cuoi(l, p);
    }

    // Hiển thị danh sách
    cout << "Danh sach lien ket don: ";
    hien_thi_danh_sach(l);
	
xoa_cac_nut_nho_hon_k(l,20);
 	    hien_thi_danh_sach(l);

 	
 	
 return 0;

}
