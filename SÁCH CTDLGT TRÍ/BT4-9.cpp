/* bài 4.9  Cho cây nhị phân tìm kiếm T,mỗi nút chứa một số nguyên.Hãy viết các hàm thực hiện các yêu cầu sau :
	a) số nút lá
	b) số nút có đúng 1 cây con
	c) số nút có đúng 2 cây con
	d) số nút có khoá nhỏ hơn x
	e) số nút có khoá nhỏ hơn x và lớn hơn y
	f) đếm xem trong cây T có bao nhiêu số chẵn,số lẻ ?
	g) kiểm tra giá trị k có trong cây T không ?
	h) đếm xem trong cây có bao nhiêu nút có giá trị âm? bao nhiêu nút có giá trị dương ?
	i) kiểm tra xem giá trị x có trong cây không ?
	j) tìm giá trị lớn nhất,giá trị nhỏ nhất cây.
	k) tìm phần tử dương nhỏ nhất của cây.
*/
#include<iostream>
#include<limits.h>
#include<cmath>
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
    t = NULL;
}

void them_node_vao_cay(TREE &t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (t->data == x)
        {
            return;
        }
        else if (t->data > x)
        {
            them_node_vao_cay(t->pLeft, x);
        }
        else if (t->data < x)
        {
            them_node_vao_cay(t->pRight, x);
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


void xuat_cay(TREE t)
{
    if (t != NULL)
    {
        xuat_cay(t->pLeft);
        cout << t->data << " ";
        xuat_cay(t->pRight);
    }
}
// câu a
void so_nut_la(TREE t,int &dem)
{
    
    if (t != NULL)
    {
        if (t->pLeft == NULL && t->pRight == NULL)
        {
            cout << t->data << " ";
            dem++;
        }
        so_nut_la(t->pLeft,dem);
        so_nut_la(t->pRight,dem);
    }
   // cout << "Cay co : " << dem << " nut la." << endl;
}
//cau b
void so_nut_co_1_cay_con(TREE t,int &dem1)
{
	if(t!=NULL)
	{
		if((t->pLeft ==NULL && t->pRight !=NULL)|| (t->pRight==NULL && t->pLeft !=NULL))
		{
			cout << t->data <<" ";
			dem1++;
		 }
		so_nut_co_1_cay_con(t->pLeft,dem1); 
				so_nut_co_1_cay_con(t->pRight,dem1); 
	}
}
//cau c
void so_nut_co_2_cay_con(TREE t, int &dem2)
{
    
    if (t != NULL)
    {
        if (t->pLeft != NULL && t->pRight != NULL)
        {
            cout << t->data << " ";
            dem2++;
        }
       so_nut_co_2_cay_con(t->pLeft,dem2);
       so_nut_co_2_cay_con(t->pRight,dem2);

    }
   // cout << "Cay co : " << dem << " nut la." << endl;
}
// cau d số nút có khoá nhỏ hơn x
void so_nut_co_khoa_nho_hon_x(TREE t,int &demx,int x)
{
	if(t!=NULL)
	{
		if(t->data<x) 
		{
			cout <<t->data<<" ";
			demx++;
		}
		so_nut_co_khoa_nho_hon_x(t->pLeft,demx,x);
		so_nut_co_khoa_nho_hon_x(t->pRight,demx,x);
	}
}
// câu e số nút có khoá nhỏ hơn x và lớn hơn y
void so_nut_co_khoa_nho_hon_x_lon_hon_y(TREE t,int &demxy,int xe,int ye)
{
	if(t!=NULL)
	{
		if(t->data<xe && t->data >ye) 
		{
			cout <<t->data<<" ";
			demxy++;
		}
		so_nut_co_khoa_nho_hon_x_lon_hon_y(t->pLeft,demxy,xe,ye);
        so_nut_co_khoa_nho_hon_x_lon_hon_y(t->pRight,demxy,xe,ye);
	}
}

// cau f đếm cây t có bao nhiêu chẵn ,bao nhiêu lẻ 
void dem_so_chan_so_le(TREE t,int &dem_chan,int &dem_le)
{
	if(t!=NULL)
	{
		if(t->data %2==0)
		{
		//	cout << t->data <<" ";
			dem_chan++;
		}
		else if(t->data %2 !=0)
		{
		//	cout << t->data<<" ";
			dem_le++;
		}
		dem_so_chan_so_le(t->pLeft,dem_chan,dem_le);
		dem_so_chan_so_le(t->pRight,dem_chan,dem_le);
	}
}

//g kieemr tra xem giá trị có trong cây t không 
NODE *tim_kiem_k (TREE t,int k)
{
	if(t !=NULL)
	{
		if(t->data==k) 
		{
			return t;
		}
		else if(t->data>k)
		{
			return tim_kiem_k(t->pLeft,k);
		}
		else if(t->data<k)
		{
			return tim_kiem_k(t->pRight,k);
		}
	}
	return NULL;// return null nua
}

//cau h
void dem_so_duong_so_am(TREE t,int &dem_duong,int &dem_am)
{
	if(t!=NULL)
	{
		if(t->data >0)
		{
		//	cout << t->data <<" ";
			dem_duong++;
		}
		else if(t->data<0)
		{
		//	cout << t->data<<" ";
			dem_am++;
		}
		dem_so_duong_so_am(t->pLeft,dem_duong,dem_am);
		dem_so_duong_so_am(t->pRight,dem_duong,dem_am);
	}
}

// cau i tìm giá trị lớn nhất ,giá trị nhỏ nhất của cây
void gia_tri_lon_nhat_cua_cay(TREE t,int &gia_tri_max)
{
	if(t!=NULL)
	{
		if(t->data>gia_tri_max)
		{
			gia_tri_max=t->data;
		}
		gia_tri_lon_nhat_cua_cay(t->pLeft,gia_tri_max);
		gia_tri_lon_nhat_cua_cay(t->pRight,gia_tri_max);
	}
}
//giá trị nhỏ nhất của cây
void gia_tri_nho_nhat_cua_cay(TREE t,int &gia_tri_min)
{
	if(t!=NULL)
	{
		if(t->data<gia_tri_min)
		{
			gia_tri_min=t->data;
		}
		gia_tri_nho_nhat_cua_cay(t->pLeft,gia_tri_min);
		gia_tri_nho_nhat_cua_cay(t->pRight,gia_tri_min);
	}
}
//hàm gộp cả 2 luôn
void tim_gia_tri_lon_nhat_va_nho_nhat(TREE t, int &gia_tri_max2, int &gia_tri_min2)
{
    if (t != NULL)
    {
        if (t->data > gia_tri_max2)
        {
            gia_tri_max2 = t->data;
        }
        if (t->data < gia_tri_min2)
        {
            gia_tri_min2 = t->data;
        }
        tim_gia_tri_lon_nhat_va_nho_nhat(t->pLeft, gia_tri_max2, gia_tri_min2);
        tim_gia_tri_lon_nhat_va_nho_nhat(t->pRight, gia_tri_max2, gia_tri_min2);
    }
}
// câu k phần tử dương nhỏ nhất 
void gia_tri_duong_nho_nhat_cua_cay(TREE t,int &gia_tri_min_duong)
{
	if(t!=NULL)
	{
		if (t->data > 0 && (t->data < gia_tri_min_duong || gia_tri_min_duong <= 0))
        {
            gia_tri_min_duong = t->data;
        }
		gia_tri_duong_nho_nhat_cua_cay(t->pLeft,gia_tri_min_duong);
		gia_tri_duong_nho_nhat_cua_cay(t->pRight,gia_tri_min_duong);
	}
}
int main()
{
    TREE t;
    khoi_tao_cay(t);
    nhap_cay(t);

//    cout << "Cay nhi phan da nhap: ";
  //  xuat_cay(t);
  int dem=0;
  so_nut_la(t,dem);
  cout <<"\nCay co : "<<dem <<" nut la."<<endl;

	int dem1=0;
	so_nut_co_1_cay_con(t,dem1);
	cout <<"\nCay co : " <<dem1 <<" nut co 1 cay con."<<endl;

     int dem2=0;
    so_nut_co_2_cay_con(t,dem2);
    cout <<"\nCay co : " <<dem2 <<" nut co 2 cay con."<<endl;

     int x;
     cout <<"Nhap gia tri x :";
     cin>>x;
     int demx=0;
     	so_nut_co_khoa_nho_hon_x(t,demx,x);
     cout <<"\nSo nut co khoa nho hon x la : "<<demx<<endl;

    int xe,ye;
    cout <<"Nhap gia tri xe : ";
    cin >>xe;
    cout <<"Nhap gia tri ye : ";
    cin >>ye;
    int demxy=0;
    so_nut_co_khoa_nho_hon_x_lon_hon_y(t,demxy,xe,ye);
    cout <<"\nSo nut co khoa nho hon x lon hon y la : "<<demxy<<endl;
    
    int dem_chan=0;
    int dem_le=0;
    dem_so_chan_so_le(t,dem_chan,dem_le);
    cout <<"\nCay co : "<< dem_chan <<" so chan va "<< dem_le << " so le ."<<endl;
    
    int k;
    cout <<"Nhap gia tri k can tim kiem : ";
    cin >>k;
     NODE *result=tim_kiem_k(t,k);
    if (result !=NULL)
    {
    	cout << "Gia tri k co trong cay "<<endl;
	}
	else cout <<"Gia tri k khong co trong cay "<<endl;
	
	int dem_duong=0;
	int dem_am=0;
	dem_so_duong_so_am(t,dem_duong,dem_am);
	cout <<"Cay co : "<< dem_duong <<" so duong va "<< dem_am <<" so am . "<<endl;

     int gia_tri_max=INT_MIN;
     gia_tri_lon_nhat_cua_cay(t,gia_tri_max);
     cout <<"Gia tri lon nhat cua cay la : "<< gia_tri_max <<endl;
     int gia_tri_min=INT_MAX;
     gia_tri_nho_nhat_cua_cay(t,gia_tri_min);
     cout <<"Gia tri nho nhat cua cay la : "<< gia_tri_min <<endl;
     
     int gia_tri_max2 = INT_MIN;
    int gia_tri_min2 = INT_MAX;
    tim_gia_tri_lon_nhat_va_nho_nhat(t, gia_tri_max2, gia_tri_min2);
    cout << "Gia tri lon nhat cua cay 2 la: " << gia_tri_max2 << endl;
    cout << "Gia tri nho nhat cua cay 2 la: " << gia_tri_min2 << endl;
    
     int gia_tri_min_duong=INT_MAX;
     gia_tri_duong_nho_nhat_cua_cay(t,gia_tri_min_duong);
     cout <<"Gia tri duong nho nhat cua cay la : "<< gia_tri_min_duong <<endl;
    return 0;
}

