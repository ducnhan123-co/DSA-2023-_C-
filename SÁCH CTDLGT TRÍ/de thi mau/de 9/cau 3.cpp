#include <iostream>
#include <algorithm> // S? d?ng std::max
using namespace std;

struct node {
    int data;
    node* pleft;
    node* pright;
};

typedef struct node NODE;
typedef NODE* TREE;

void khoi_tao_cay(TREE& t) {
    t = nullptr;
}

void them_phan_tu_vao_cay(TREE& t, int x) {
    if (t == nullptr) {
        NODE* p = new NODE;
        p->data = x;
        p->pleft = nullptr;
        p->pright = nullptr;
        t = p;
    } else {
        if (t->data > x) {
            them_phan_tu_vao_cay(t->pleft, x);
        } else if (t->data < x) {
            them_phan_tu_vao_cay(t->pright, x);
        }
    }
}

void duyet_cay_LNR(TREE t) {
    if (t != nullptr) {
        duyet_cay_LNR(t->pleft);
        cout << t->data << " ";
        duyet_cay_LNR(t->pright);
    }
}
NODE* tim_kiem_node_co_khoa_x(TREE t,int x)
{
	if(t==nullptr) return nullptr;
	if(t->data > x)
	{
		tim_kiem_node_co_khoa_x(t->pleft,x);
	}
	else if(t->data < x)
	{
		tim_kiem_node_co_khoa_x(t->pright,x);
	}
	else
	{
	
	return t;
}
}

int dem_so_nut_khoa_lon_hon_x(TREE t,int x)
{
	if(t==nullptr) return 0;
	
	int dem=0;
	if(t->data>x)
	{
		dem=1;
	}
	dem+=dem_so_nut_khoa_lon_hon_x(t->pleft,x);
	dem+=dem_so_nut_khoa_lon_hon_x(t->pright,x);
	
	return dem;
}

int main() {
    TREE t;
    khoi_tao_cay(t);
    them_phan_tu_vao_cay(t, 5);
    them_phan_tu_vao_cay(t, 4);
    them_phan_tu_vao_cay(t, 6);
    them_phan_tu_vao_cay(t, 3);
    them_phan_tu_vao_cay(t, 7);
        them_phan_tu_vao_cay(t, 9);
    cout << "Duyet cay LNR: ";
    duyet_cay_LNR(t);
    cout << endl;
    
    int x;
    cout <<"Nhap khoa x can tim kiem : ";
    cin>>x;
    NODE *p=tim_kiem_node_co_khoa_x(t,x);
    if(p!=nullptr)
    {
    	cout<<"Node co trong cay gia tri la : "<< p->data;
	}
	else
	{
		cout<<"Node khong co trong cay "<<endl;
	}
	
	int x1;
	cout <<"\nNhap khoa x can dem khoa lon hon : ";
	cin>>x1;
	int demkhoa=dem_so_nut_khoa_lon_hon_x(t,x);
	cout <<"Co : "<< demkhoa <<" nut co khoa lon hon X "<<endl;
     return 0;
}
