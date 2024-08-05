#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
typedef struct node NODE;
typedef NODE *TREE;
void khoi_tao_cay(TREE &t)
{
	t=NULL;
}
void them_nut_vao_cay(TREE &t,int x)
{
	if(t==NULL)
	{
		NODE *p=new NODE;
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		t=p;
	}
	else
	{
		if(t->data>x)
		{
			them_nut_vao_cay(t->left,x);
		}
		else if(t->data<x)
		{
			them_nut_vao_cay(t->right,x);
		}
	}
}

void duyet_NRL(TREE t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		duyet_NRL(t->right);
		duyet_NRL(t->left);
	}
}

void dem_nut_la(TREE t,int &dem)
{
		
	if(t!=NULL)
	{
	
		if(t->left==NULL && t->right==NULL) 
		{
			dem++;
			cout<< t->data << " ";
		}
		dem_nut_la(t->left,dem);
		dem_nut_la(t->right,dem);
	}
}

int main()
{
	TREE t;
	khoi_tao_cay(t);
	them_nut_vao_cay(t,18);
	them_nut_vao_cay(t,10);
	them_nut_vao_cay(t,24);
	them_nut_vao_cay(t,5);
	them_nut_vao_cay(t,13);
	them_nut_vao_cay(t,7);
	them_nut_vao_cay(t,20);
	them_nut_vao_cay(t,29);
	them_nut_vao_cay(t,19);
	them_nut_vao_cay(t,22);
	them_nut_vao_cay(t,27);
	duyet_NRL(t);
	cout<<endl;
	int dem=0;
	dem_nut_la(t,dem);
	cout<<"\nCay co : "<< dem<<" nut la "<<endl;
	return 0;
}




#include<iostream>
#include<cmath>
using namespace std;

struct NodeTree
{
    int data;
    NodeTree *left;
    NodeTree *right;
};

void khoi_tao_cay(NodeTree *&t)
{
    t = NULL;
}

void them_nut_vao_cay(NodeTree *&t, int x)
{
    if (t == NULL)
    {
        NodeTree *p = new NodeTree;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
        {
            them_nut_vao_cay(t->left, x);
        }
        else if (t->data < x)
        {
            them_nut_vao_cay(t->right, x);
        }
    }
}

void duyet_NRL(NodeTree *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        duyet_NRL(t->right);
        duyet_NRL(t->left);
    }
}

void dem_nut_la(NodeTree *t, int &dem)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            dem++;
            cout << t->data << " ";
        }
        dem_nut_la(t->left, dem);
        dem_nut_la(t->right, dem);
    }
}

int main()
{
    NodeTree *t;
    khoi_tao_cay(t);
    them_nut_vao_cay(t, 18);
    them_nut_vao_cay(t, 10);
    them_nut_vao_cay(t, 24);
    them_nut_vao_cay(t, 5);
    them_nut_vao_cay(t, 13);
    them_nut_vao_cay(t, 7);
    them_nut_vao_cay(t, 20);
    them_nut_vao_cay(t, 29);
    them_nut_vao_cay(t, 19);
    them_nut_vao_cay(t, 22);
    them_nut_vao_cay(t, 27);
    duyet_NRL(t);
    cout << endl;
    int dem = 0;
    dem_nut_la(t, dem);
    cout << "\nCay co : " << dem << " nut la " << endl;
    return 0;
}
