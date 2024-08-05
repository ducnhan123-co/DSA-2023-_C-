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
typedef NODE* TREE;

void Khoi_Tao_Cay(TREE &t)
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
	}
}

void duyet_LNR(TREE t)
{
	if(t!=NULL)
	{
		duyet_LNR(t->pLeft);
		cout <<t->data<<" ";
		duyet_LNR(t->pRight);
	}
}
int tong_cay_con(TREE t)
{
	if(t==NULL) return 0;
	return t->data + tong_cay_con(t->pLeft) + tong_cay_con(t->pRight);
}
void tim_cay_con_t_co_tong_lon_nhat(TREE t,TREE &cay_con_max,int &max_tong)
{
	if(t==NULL) return;
	int tong=tong_cay_con(t);
	if(tong > max_tong);
	{
		max_tong=tong;
		cay_con_max=t;
	}
	 tim_cay_con_t_co_tong_lon_nhat(t->pLeft,cay_con_max,max_tong);
	 	 tim_cay_con_t_co_tong_lon_nhat(t->pRight,cay_con_max,max_tong);	
}
//tim nut la sau nhat
void tim_nut_la_sau_nhat(TREE t, int level, int &maxLevel, int &maxLeafValue)
{
    if (t == NULL)
        return;

    // Kiểm tra nếu nút hiện tại là nút lá
    if (t->pLeft == NULL && t->pRight == NULL)
    {
        if (level > maxLevel)
        {
            maxLevel = level;
            maxLeafValue = t->data;
        }
    }

    // Duyệt các con của nút hiện tại
    tim_nut_la_sau_nhat(t->pLeft, level + 1, maxLevel, maxLeafValue);
    tim_nut_la_sau_nhat(t->pRight, level + 1, maxLevel, maxLeafValue);
}

void tim_gia_tri_nut_la_o_muc_sau_nhat(TREE t)
{
    int maxLevel = -1;
    int maxLeafValue = INT_MIN;
    tim_nut_la_sau_nhat(t, 0, maxLevel, maxLeafValue);
    cout << "Gia tri nut la o muc sau nhat: " << maxLeafValue << endl;
}


int main() {
    TREE t;
   Khoi_Tao_Cay(t);

    them_node_vao_cay(t, 5);
    them_node_vao_cay(t, 4);
    them_node_vao_cay(t, 9);
    them_node_vao_cay(t, 3);
    them_node_vao_cay(t, 7);
    them_node_vao_cay(t, 10);
    them_node_vao_cay(t, 2);

   duyet_LNR(t);
    
    TREE cay_con_max = NULL;
	int max_tong = INT_MIN;
	tim_cay_con_t_co_tong_lon_nhat(t,cay_con_max,max_tong);
	cout << "Cay con co tong lon nhat: ";
	duyet_LNR(cay_con_max);
	cout << endl;
		cout << "Tong lon nhat: " << max_tong << endl;
	
	
	tim_gia_tri_nut_la_o_muc_sau_nhat(t);
    return 0;
}