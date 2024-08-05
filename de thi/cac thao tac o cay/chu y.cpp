#include <iostream>
#include <cmath>
#include<limits.h>
using namespace std;


//DINH NGHIA CAU TRUC 1 NODE
struct node {
    int data;
    node *pleft;
    node *pright;
};



typedef struct node NODE;//DAT TEN GOI CHO NODE
typedef NODE *TREE;//KHOI TAY CAU TRUC CAY


//KHOI TAO CAY
void khoi_tao_cay(TREE &t) {
    t = NULL;
}


//THEM NODE VAO CAY(VAN BAO DAM BST)
void them_node_vao_cay(TREE &t, int x) {
    if (t == NULL) {
        NODE *p = new NODE;
        p->data = x;
        p->pleft = NULL;
        p->pright = NULL;
        t = p;
    } else {
        if (t->data > x) {
            them_node_vao_cay(t->pleft, x);
        } else if (t->data < x) {
            them_node_vao_cay(t->pright, x);
        }
    }
}

//Tim kiem va tri ve gia tri cua mot khoa
//Viết giải thuật để tìm 1 đối tượng(nút) có khoá bằng k trong cây nhị phân tìm kiếm
NODE* tim_kiem_phan_tu_trong_cay(TREE t, int x) {
    if (t == NULL) return NULL;
    if (t->data > x) {
        return tim_kiem_phan_tu_trong_cay(t->pleft, x);
    } else if (t->data < x) {
        return tim_kiem_phan_tu_trong_cay(t->pright, x);
    } else {
        return t;
    }
}



//tim duong di co do dai bang k
void tim_duong_di_dai_k(TREE t, int k, int path[], int path_len) {
    if (t == NULL) return;

    // Th m node hi?n t?i v o du?ng di
    path[path_len] = t->data;
    path_len++;

    // N?u d? d i du?ng di b?ng k, in du?ng di
    if (path_len == k) {
        for (int i = 0; i < k; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        //  ? quy t m ki?m c c du?ng di trong c y con tr i v  c y con ph?i
        tim_duong_di_dai_k(t->pleft, k, path, path_len);
        tim_duong_di_dai_k(t->pright, k, path, path_len);
    }
}





void tim_tat_ca_duong_di_dai_k(TREE t, int k) {
    int path[1000]; // M?ng tinh d? luu du?ng di, gi? s? t?i da 1000 node
    tim_duong_di_dai_k(t, k, path, 0);
}




//Them nhieu phan tu vao cay
void them_cac_node_vao_cay(TREE &t) {
    int n;
    cout << "Nhap so phan tu can them: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> x;
        them_node_vao_cay(t, x);
    }
}




bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}



//dem node co gia tri chan le ,nguyen to
void dem_node_thoa_man_la_so_chan_le_nguyen_to(TREE t, int &dem_chan, int &dem_le, int &dem_nguyento) {
    if (t == NULL) {
        return;
    }
    
    if (isPrime(t->data)) {
        dem_nguyento++;
    }
    if (t->data % 2 == 0) {
        dem_chan++;
    } else {
        dem_le++;
    }
    
    dem_node_thoa_man_la_so_chan_le_nguyen_to(t->pleft, dem_chan, dem_le, dem_nguyento);
    dem_node_thoa_man_la_so_chan_le_nguyen_to(t->pright, dem_chan, dem_le, dem_nguyento);
}


//tinh tong cac gia tri trong
//Viết giải thuật tính tổng số đối tượng trong cây nhị phân tìm kiếm
int tong_gia_tri_cac_nut_cay(TREE t)
{
	if(t==NULL)
	{
	
	return 0;
}
	
		int tong=t->data;
	tong+=tong_gia_tri_cac_nut_cay(t->pleft);
	tong+=tong_gia_tri_cac_nut_cay(t->pright);
	
	return tong;
}




//tinh hieu cac gia tri trong cay
int hieu_gia_tri_cac_nut_cay(TREE t) {
    if (t == NULL) {
        return 0;
    }
    int hieu = t->data;
    hieu -= hieu_gia_tri_cac_nut_cay(t->pleft);
    hieu -= hieu_gia_tri_cac_nut_cay(t->pright);
    return hieu;
}



//tinh tich gia tri trong cay
int tich_gia_tri_cac_nut_cay(TREE t) {
    if (t == NULL) {
        return 1; // Trả về 1 thay vì 0 để phép nhân không bị ảnh hưởng
    }
    int tich = t->data;
    tich *= tich_gia_tri_cac_nut_cay(t->pleft);
    tich *= tich_gia_tri_cac_nut_cay(t->pright);
    return tich;
}





//chieu cao cua cay
int chieu_cao_cay_t(TREE t)
{
	if(t==NULL)
	return 0;
	
	return 1+max(chieu_cao_cay_t(t->pleft),chieu_cao_cay_t(t->pright));
	
}





//duyet cay theo LNR (tang dan)
void duyet_cay_LNR(TREE t) {
    if (t != NULL) {
        duyet_cay_LNR(t->pleft);
        cout << t->data << " ";
        duyet_cay_LNR(t->pright);
    }
}




//tim gia tri lon nhat cua cay BST(phai nhat ben phai)
int TimMax(TREE t)
{
	if(t->pright == NULL)
	{
		return t->data;
	}
	return TimMax(t->pright);
}





//tin gia tri nho nhat cua cay BST(trai nhat ben trai)
int TimMin(TREE t)
{
	if(t->pleft==NULL)
	{
		return t->data;
	}
	return TimMin(t->pleft);
}



//dem cac nut la va in ra
void dem_nut_la_va_in_ra(TREE t,int &dem_la)
{
	if(t!=NULL)
	{
		if(t->pleft==NULL && t->pright ==NULL)
		{
			dem_la++;
			cout<<t->data <<" ";
		}
		
		dem_nut_la_va_in_ra(t->pleft,dem_la);
		dem_nut_la_va_in_ra(t->pright,dem_la);
	}
}



//dem cac nut co 1 con va in ra
void dem_nut_co_1_con_va_in_ra(TREE t,int &dem_1_con)
{
	if(t!=NULL)
	{
		if((t->pleft != NULL && t->pright == NULL) || (t->pleft== NULL && t->pright !=NULL)) 
		{
			dem_1_con++;
			cout<<t->data<<" ";
		}
		
		dem_nut_co_1_con_va_in_ra(t->pleft,dem_1_con);
		dem_nut_co_1_con_va_in_ra(t->pright,dem_1_con);
	}
}




//Đếm nút có 2 con
//dem cac nut co 2 con va in ra
int dem_nut_co_2_con(TREE t)
{
	int dem=0;
	if(t!=NULL)
	{
		
		if(t->pleft != NULL && t->pright !=NULL )
		{
			dem=1;
		}
		dem+=dem_nut_co_2_con(t->pleft);
		dem+=dem_nut_co_2_con(t->pright);
	}
	return dem;
}



//tim muc cua node co khoa = k
int muc_cua_node_co_khoa_bang_k(TREE t, int k, int muc_hien_tai = 0)
{
    if (t == NULL)
    {
        return -1; // Trả về -1 nếu không tìm thấy khóa
    }
    if (k == t->data)
    {
        return muc_hien_tai; // Trả về mức hiện tại nếu tìm thấy khóa
    }
    else if (k > t->data)
    {
        return muc_cua_node_co_khoa_bang_k(t->pright, k, muc_hien_tai + 1);
    }
    else // (k < t->data)
    {
        return muc_cua_node_co_khoa_bang_k(t->pleft, k, muc_hien_tai + 1);
    }
}






// in các nút ở mức k
void in_cac_nut_o_muc_k(TREE t, int k, int muc_hien_tai = 1) {
    if (t == NULL) {
        return;
    }
    if (muc_hien_tai == k) {
        cout << t->data << " ";
    } else {
        in_cac_nut_o_muc_k(t->pleft, k, muc_hien_tai + 1);
        in_cac_nut_o_muc_k(t->pright, k, muc_hien_tai + 1);
    }
}




//in khoa cua nut tren duong di tu goc den k	
	void in_khoa_cua_nut_tren_duong_di_tu_goc_den_khoa_k(TREE t,int k)
	{
	
		if(t==NULL)
		{
			return;
		}
		cout << t->data <<" ";
		if(k==t->data)
		{
			return ;
		}
		else if(k>t->data)
		{
			in_khoa_cua_nut_tren_duong_di_tu_goc_den_khoa_k(t->pright,k);
		}
		else
		{
			in_khoa_cua_nut_tren_duong_di_tu_goc_den_khoa_k(t->pleft,k);
		}
		
	}



//in tat cac cac nut o muc k	
	void in_tat_ca_nut_o_muc_k(TREE t,int k,int muchientai=0)
	{
		if(t==NULL)
		{
			return;
		}
		if(muchientai==k)
		{
			cout<<t->data <<" ";
		}
		in_tat_ca_nut_o_muc_k(t->pleft,k,muchientai+1);
		in_tat_ca_nut_o_muc_k(t->pright,k,muchientai+1);
		
	}
	






	
//dem so nut k thoa man lon hon x nho hon y
	int dem_so_nut_k_thoa_man_lon_hon_x_nho_hon_y(TREE t,int x ,int y)
	{
		if(t==NULL)
		{
			return 0;
		}
		int dem=0;
		if(t->data > x && t->data < y)
		{
			dem=1;
		}
		dem +=dem_so_nut_k_thoa_man_lon_hon_x_nho_hon_y(t->pleft,x,y);
		dem +=dem_so_nut_k_thoa_man_lon_hon_x_nho_hon_y(t->pright,x,y);
		
		return dem;
	}
	
	
	
	
   //in muc cua nut co khoa nho nhat
	int muc_cua_nut_co_khoa_nho_nhat(TREE t, int &khoamin, int muchientai = 0) {
    if (t == NULL) 
	{
        return muchientai;
    }
    // Đệ quy xuống cây con bên trái
    int muc_trai = muc_cua_nut_co_khoa_nho_nhat(t->pleft, khoamin, muchientai + 1);
    // So sánh giá trị khoamin với giá trị của nút hiện tại
    khoamin = min(khoamin, t->data);
    return muc_trai;
    }
    
    
    
    
    
    
	//in nut cua nut co khoa lon nhat
    int muc_cua_nut_co_khoa_lon_nhat(TREE t, int &khoamax, int muchientai = 0) {
    if (t == NULL) {
        return muchientai;
    }
    // Đệ quy xuống cây con bên phải
    int muc_phai = muc_cua_nut_co_khoa_lon_nhat(t->pright, khoamax, muchientai + 1);
    // So sánh giá trị khoamax với giá trị của nút hiện tại
    khoamax = max(khoamax, t->data);
    return muc_phai;
    }






//in cac nut tu tang 0 den tang h-1
void in_cac_nut_tu_tang_0_den_tang_h_minus_1(TREE t, int heightnode) {
    if (t == NULL || heightnode == 0) {
        return;
    }
    if (heightnode == 1) {
        cout << t->data << " ";
    } else {
        in_cac_nut_tu_tang_0_den_tang_h_minus_1(t->pleft, heightnode - 1);
        in_cac_nut_tu_tang_0_den_tang_h_minus_1(t->pright, heightnode - 1);
    }
}
void in_cac_nut_tu_tang_0_den_tang_h_minus_1_h(TREE t, int h) {
    for (int i = 1; i < h; i++) {
        in_cac_nut_tu_tang_0_den_tang_h_minus_1(t, i);
        
    }
}





//Di tim node the mang de xoa (3 tt)
void DiTimNodeTheMang(TREE &X,TREE &Y)
{
	if(Y->pleft!=NULL)
	{
		DiTimNodeTheMang(X,Y->pleft);
	}
	else
	{
		X->data=Y->data;
		X=Y;
		Y=Y->pright;
	}
}



//Xoa cac nut (la,1 con ,2 con)
void xoa_node(TREE &t,int x)
{
	if(t==NULL)
	{
		return;
	}
	else if(t->data>x)
	{
		xoa_node(t->pleft,x);
	}
	else if(t->data<x)
	{
		xoa_node(t->pright,x);
	}
	else
	{
		NODE *X=t;
		if(t->pleft==NULL)
		{
			t=t->pright;
		}
		else if(t->pright==NULL)
		{
			t=t->pleft;
		}
		else 
		{
			DiTimNodeTheMang(X,t->pright);
		}
		delete X;
	}
	
	
}


//duyet cay RNL giam dan
void duyet_cay_RNL(TREE t)
{
	if(t!=NULL)
	{
		duyet_cay_RNL(t->pright);
		cout<< t->data <<" ";
		duyet_cay_RNL(t->pleft);
	}
}



//duyt cay giam dan nhung co gia tri lon hon k
void duyet_cay_giam_dan_lon_hon_k(TREE &t,int k)
{
	if(t==NULL) return;
	duyet_cay_giam_dan_lon_hon_k(t->pright,k);
	if(t->data > k)
	{
		cout<<t->data<<" ";
	}
	duyet_cay_giam_dan_lon_hon_k(t->pleft,k);
}



//Tính độ lệch lớn nhất trong cây
int maxImbalance(TREE t) {
    if (t == NULL) // Nếu cây rỗng
        return 0;

    // Tính chiều cao của cây con bên trái và bên phải
    int leftHeight = chieu_cao_cay_t(t->pleft);
    int rightHeight = chieu_cao_cay_t(t->pright);

    // Tính độ lệch của nút hiện tại
    int imbalance = abs(leftHeight - rightHeight);

    // Tìm độ lệch lớn nhất trong cây con trái, cây con phải và cây gốc
    int maxLeftImbalance = maxImbalance(t->pleft);
    int maxRightImbalance = maxImbalance(t->pright);

    // Trả về độ lệch lớn nhất
    return max(imbalance, max(maxLeftImbalance, maxRightImbalance));
}



//kiem tra cay bst a co phai cay con bst b khong
bool isIdentical(TREE a, TREE b) {
    // Nếu cả hai cây đều rỗng, chúng giống nhau
    if (a == NULL && b == NULL)
        return true;

    // Nếu một trong hai cây là rỗng trong khi cây kia không, chúng không giống nhau
    if (a == NULL || b == NULL)
        return false;

    // So sánh giá trị của nút hiện tại ở cả hai cây
    if (a->data != b->data)
        return false;

    // So sánh cây con trái của nút hiện tại
    // và cây con phải của nút hiện tại của cả hai cây
    return isIdentical(a->pleft, b->pleft) && isIdentical(a->pright, b->pright);
}









bool isSubtree(TREE a, TREE b) {
    // Nếu cây con là rỗng, nó là một cây con của bất kỳ cây nào
    if (b == NULL)
        return true;

    // Nếu cây cha là rỗng, không có cây con nào có thể là một cây con của nó
    if (a == NULL)
        return false;

    // Nếu cây con là một phần của cây cha, trả về true
    if (isIdentical(a, b))
        return true;

    // Kiểm tra cây con với cây cha có phải là một cây con của cây cha trái hoặc cây cha phải
    return isSubtree(a->pleft, b) || isSubtree(a->pright, b);
}




bool IsBSTTree(TREE t, int& key, bool& firstTime) {
    bool isBST = true; // Giả sử cây p là cây BST

    // Nếu cây p không rỗng
    if (t!= NULL) {
        // Kiểm tra cây con trái của p là cây BST (L)
        isBST = IsBSTTree(t->pleft, key, firstTime);

        // Nếu cây con trái là cây BST
        if (isBST) {
            // Kiểm tra khóa của p với khóa key (N)
            if (firstTime) { // p không có khóa trước key
                firstTime = false; // Không là lần đầu
            } else if (key >= t->data) { // key >= khóa của p
                isBST = false; // Không là cây BST
            }
            key = t->data; // key là khóa của p
        }

        // Nếu p thỏa điều kiện là cây BST
        if (isBST) {
            // Kiểm tra cây con phải của p là cây BST (R)
            isBST = IsBSTTree(t->pright, key, firstTime);
        }
    }
    return isBST;
}






//so nut khac nut la cach khac
int sonutkhacla(TREE t)
{
	if(t!=NULL)
	{
		if(t->pleft!=NULL || t->pright!=NULL)
		return (sonutkhacla(t->pleft)+ sonutkhacla(t->pright)+1);
	}
//	return 0;
}//dem so nut trung gian
int sonuttrunggian(TREE t)
{
	return (sonutkhacla(t)-1);
//	return 0;
}






//b so nut co dung mot cay con
int sonut1con(TREE t)
{
	if(t!=NULL)
	{
		if((t->pleft!=NULL && t->pright==NULL) || (t->pleft==NULL && t->pright!=NULL))
		{
			return (sonut1con(t->pleft)+ sonut1con(t->pright)+1);
		}
		else return (sonut1con(t->pleft)+ sonut1con(t->pright));
	}
	return 0;
}





// kiem tra xem T co phai can bang hoan toan khong ...
int Max( int a,int b)
{
	return (a>b ? a : b);
}
//tim so nut cua cay(tat ca luon)
int sonut(TREE t)
{
	if(t!=NULL)
	{
		return (sonut(t->pleft)+ sonut(t->pright)+1);
	}
	return 0;
}
//kiem tra co can bang hoan toan khong
int canbanghoantoan(TREE t)
{
    if (t == NULL)
    {
        return 1; // C y r?ng du?c coi l  c n b?ng ho n to n
    }

    // Ki?m tra s? ch nh l?ch gi?a s? n t c?a c y con tr i v  c y con ph?i
    if (abs(sonut(t->pleft) - sonut(t->pright)) > 1)
    {
        return 0; // N?u ch nh l?ch l?n hon 1, c y kh ng c n b?ng ho n to n
    }

    //  ? quy ki?m tra c y con tr i v  c y con ph?i
    return (canbanghoantoan(t->pleft) * canbanghoantoan(t->pright));
}




//kiem tra co phai cay nhi phan tim kiem khong
bool isbstuntil(TREE t, int minvalue, int maxvalue)
{
    if (t == NULL)
        return true;

    if (t->data < minvalue || t->data > maxvalue)
        return false;

    return isbstuntil(t->pleft, minvalue, t->data) && isbstuntil(t->pright, t->data, maxvalue);
}

int caynhiphantimkiem(TREE t)
{
	return isbstuntil(t,INT_MIN,INT_MAX);	
}



bool laCayNhiPhanCanBang(TREE t) {
    if (t == NULL) {
        return true;
    }
    int chieuCaoBenTrai = chieuCaoCay(t->pleft);
    int chieuCaoBenPhai = chieuCaoCay(t->pright);
    if (abs(chieuCaoBenTrai - chieuCaoBenPhai) <= 1 &&
        laCayNhiPhanCanBang(t->pleft) &&
        laCayNhiPhanCanBang(t->pright)) {
        return true;
    }
    return false;
}


void timBaNutLonNhat(Tree t, int &max1, int &max2, int &max3) {
    if (t == NULL) {
        return;
    }

    // Duyệt cây theo thứ tự giảm dần (phải, gốc, trái)
    timBaNutLonNhat(t->pRight, max1, max2, max3);

    // Cập nhật giá trị lớn nhất
    if (t->data > max1) {
        max3 = max2;
        max2 = max1;
        max1 = root->data;
    } else if (t->data > max2) {
        max3 = max2;
        max2 = t->data;
    } else if (t->data > max3) {
        max3 = t->data;
    }

    timBaNutLonNhat(t->pleft, max1, max2, max3);
}
void tim_2_nut_lon_nhat(TREE t, int &max1, int &max2) {
    if (t == NULL) return;
    
    tim_2_nut_lon_nhat(t->pright, max1, max2);
    if (t->data > max1) {
        max2 = max1;
        max1 = t->data;
    } else if (t->data > max2) {
        max2 = t->data;
    }
    
    tim_2_nut_lon_nhat(t->pleft, max1, max2);
}

void print3LargestNodes(Tree t) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    // Tìm ba nút lớn nhất
    timBaNutLonNhat(t, max1, max2, max3);

    // In ra ba nút lớn nhất
    cout << "Ba nut lon nhat duoc la: " << max1 << ", " << max2 << ", " << max3 << endl;
}
void in2nut(TREE t)
{
	int max1=INT_MIN, max2=INT_MIN;max3=INT_MIN;
	tim_2_nut_lon_nhat(t,max1,max2);
	 cout << "hai nut lon nhat duoc la: " << max1 << ", " << max2 << ", " ;
}

int main() {
    TREE t;
    khoi_tao_cay(t);
    
    them_cac_node_vao_cay(t);

    int x;
    cout << "Nhap x can tim kiem: ";
    cin >> x;
    NODE *result = tim_kiem_phan_tu_trong_cay(t, x);
    if (result != NULL) {
        cout << "Tim thay gia tri " << x << " trong cay." << endl;
    } else {
        cout << "Khong tim thay gia tri " << x << " trong cay." << endl;
    }

    duyet_cay_LNR(t);
    cout << endl;
    
    int dem_chan = 0, dem_le = 0, dem_nguyento = 0;
    dem_node_thoa_man_la_so_chan_le_nguyen_to(t, dem_chan, dem_le, dem_nguyento);
    cout << "Cay co: " << dem_chan << " so chan, " << dem_le << " so le, " << dem_nguyento << " so nguyen to." << endl;

int tong = tong_gia_tri_cac_nut_cay(t);
    cout << "Tong gia tri cac nut trong cay: " << tong << endl;
   int hieu = hieu_gia_tri_cac_nut_cay(t);
    cout << "hieu gia tri cac nut trong cay: " << hieu << endl;
   
     int tich = tich_gia_tri_cac_nut_cay(t);
    cout << "tich gia tri cac nut trong cay: " <<tich << endl;
  
  	int height=chieu_cao_cay_t(t);
  	cout <<"Chieu cao cua cay la : "<< height<<endl;
  	
  	int maxtree=TimMax(t);
  	cout <<"Gia tri lon nhat cua cay la : "<<maxtree<<endl;
  	
  	int mintree=TimMin(t);
  	cout <<"Gia tri nho nhat cua cay la : "<<mintree<<endl;
	
	int demla=0;
	dem_nut_la_va_in_ra(t,demla);  
	cout<<" = > Cay co : "<<demla<<" nut la "<<endl;
	
	int dem1con=0;
	dem_nut_co_1_con_va_in_ra(t,dem1con);
	cout <<" = > Cay co : "<< dem1con <<" nut co 1 con "<<endl;
   	
   	int dem2con=0;
   	dem_nut_co_2_con_va_in_ra(t,dem2con);
   	cout <<" = > Cay co : "<< dem2con <<" nut co 2 con "<<endl;
   
    int k;
    cout << "Nhap gia tri khoa can tim muc: ";
    cin >> k;
    int muc = muc_cua_node_co_khoa_bang_k(t, k);
    if (muc != -1)
    {
        cout << "Muc cua node co khoa " << k << " la: " << muc << endl;
    }
    else
    {
        cout << "Khong tim thay node co khoa " << k << endl;
    }
    
    int k1;
    cout << "Nhap gia tri khoa can tim duong di: ";
    cin >> k1;
    cout << "Cac khoa tren duong di tu goc den khoa " << k1 << " la: ";
    in_khoa_cua_nut_tren_duong_di_tu_goc_den_khoa_k(t, k1);
    cout << endl;
   
   	int k2;
   	 cout << "Nhap muc k: ";
    cin >> k2;
    cout << "Cac nut o muc " << k2 << " la: ";
    in_tat_ca_nut_o_muc_k(t, k2);
    cout << endl;
    
    int x1,y1;
    cout<<"Nhap x : ";
    cin>>x1;
    cout<<"Nhap y : ";
    cin>>y1;
    int demxy= dem_so_nut_k_thoa_man_lon_hon_x_nho_hon_y(t,x1,y1);
    cout <<"So nut k thoa man lon hon x nho hon y la : "<<demxy <<endl;
   
   	int khoamin=0;
   int muc_nho_nhat=muc_cua_nut_co_khoa_nho_nhat(t,khoamin);
    cout << "Muc cua nut co gia tri nho nhat trong cay la: " << muc_nho_nhat << endl;
   
   int khoamax=0;
   int muc_lon_nhat=muc_cua_nut_co_khoa_nho_nhat(t,khoamax);
   cout << "Muc cua nut co gia tri lon nhat trong cay la: " << muc_lon_nhat << endl;
   
int h=chieu_cao_cay_t(t);
cout <<"Chieu cao cay tu goc den h-1 la : ";
in_cac_nut_tu_tang_0_den_tang_h_minus_1_h(t,h);


int k3;
cout <<"\nNhap khoa can xoa : ";
cin >> k3;
xoa_node(t,k3);
cout <<"Cay sau khi xoa : ";
duyet_cay_LNR(t);

int k4;
    cout << "Nhap so nguyen k: ";
    cin >> k4;

    cout << "Cac khoa lon hon " << k4 << " theo thu tu giam dan la: ";
    duyet_cay_giam_dan_lon_hon_k(t, k4);
    cout << endl;
   
     cout << "Do lech lon nhat o cay la " << maxImbalance(t) << endl;
  /* int dem = 0;
    dem_so_nut_k_thoa_man_lon_hon_x_nho_hon_y(t, x, y, dem);
    cout << "So nut co gia tri lon hon " << x << " va nho hon " << y << " la: " << dem << endl;*/
    TREE A, B;
    khoi_tao_cay(A);
    khoi_tao_cay(B);
    
    // Thêm các nút vào cây A và B
    // Gọi hàm isSubtree để kiểm tra xem A có phải là một cây con của B không
    if (isSubtree(B, A))
        cout << "A la cay con cua B." << endl;
    else
        cout << "A khong la cay con cua B." << endl;
    return 0;
}
