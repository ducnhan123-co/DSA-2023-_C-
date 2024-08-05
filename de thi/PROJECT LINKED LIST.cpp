#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

// Cấu trúc của một node
struct node {
    int data;
    node* pnext;
};
typedef struct node NODE;

// Cấu trúc của một danh sách
struct List {
    node* phead = NULL;
    node* pTail = NULL;
};
typedef struct List LIST;

// Khởi tạo danh sách
void khoi_tao_list(LIST& l) {
    l.phead = NULL;
    l.pTail = NULL;
}

// Khởi tạo một node
NODE* khoi_tao_node(int x) {
    NODE* p = new NODE;
    p->data = x;
    p->pnext = NULL;
    return p;
}
//giải thuật xác định độ dài danh sách liên kết đơn
int do_dai_list(LIST l)
{
	if(l.phead==NULL)
	{
		return 0;
	}
	int len=0;
	NODE *p=l.phead;
	while(p!=NULL)
	{
		len++;
	}
	return len;
}




//hàm tăng các gia trị chẵn lên 1 đơn vị
void tang_chan_len_1_donvi(LIST &l)
{
	if(l.phead==NULL) return;
	for(NODE *p=l.phead;p!=NULL;p=p->pnext)
	{
		if(p->data % 2==0)
		{
			p->data=p->data+1;
		}
	}	
}




//Viết một giải thuật để chèn một đối tượng có giá trị k vào cuối DSLK
// Thêm một node vào cuối danh sách
void them_vao_cuoi(LIST& l, int x) {
    NODE* p = khoi_tao_node(x);
    if (l.phead == NULL) {
        l.phead = l.pTail = p;
    } else {
        l.pTail->pnext = p;
        l.pTail = p;
    }
}

//Viết một giải thuật chèn một đối tượng có giá trị x vào đầu của DSLK
// Thêm node vào đầu danh sách
void them_vao_dau(LIST& l, int x) {
    NODE* p = khoi_tao_node(x);
    if (l.phead == NULL) {
        l.phead = l.pTail = p;
    } else {
        p->pnext = l.phead;
        l.phead = p;
    }
}



//Viết một giải thuật tính trung bình cộng tất cả các giá trị của đối tượng trong DSLK
float trung_binh_cong_tat_ca_gia_tri(LIST l)
{
	if(l.phead==NULL) return 0;
	int dem=0;
	int tong=0;
	NODE *p=l.phead;
	while (p!=NULL)
	{
		dem++;
		tong+=p->data;
		p=p->pnext;
	}
	return 1.0*tong/dem;
}







//giải thuật tìm nút trong DSLK mà lưu trữ đối tượng có khoá nhỏ nhất lơn hơn một giá trị k nguyên cho trước
NODE *tim_khoa_min_lon_hon_k(LIST l, int k) {
    if (l.phead == NULL) return NULL;

    NODE *result = NULL;
    int min = INT_MAX;

    for (NODE *p = l.phead; p != NULL; p = p->pnext) {
        if (p->data > k && p->data < min) {
            min = p->data;
            result = p;
        }
    }

    return result;
}








//giải thuật tìm nút chẵn lớn nhất
NODE *tim_nut_chan_lon_nhat(LIST l)
{
	if(l.phead==NULL) return NULL;
	NODE *result=NULL;
	int max=INT_MIN;
	for(NODE *p=l.phead;p!=NULL;p=p->pnext)
	{
		if((p->data)%2==0 && p->data>max)
		{
			max=p->data;
			result=p;
		}
	}
	return result;
}







// Hàm tìm nút có giá trị nhỏ thứ hai trong danh sách liên kết
NODE* nut_nho_thu_hai(LIST l) {
    if (l.phead == NULL) {
        cout << "Danh sach rong.\n";
        return NULL;
    }

    int min = INT_MAX;
    int min2 = INT_MAX;
    NODE* minNode = NULL;
    for (NODE* p = l.phead; p != NULL; p = p->pnext) {
        if (p->data < min) {
            min2 = min;
            min = p->data;
            minNode = p;
        } else if (p->data < min2 && p->data != min) {
            min2 = p->data;
        }
    }

    // Kiểm tra xem có tồn tại nút có giá trị nhỏ thứ hai hay không
    if (min2 == INT_MAX) {
        cout << "Khong co nut nao co gia tri nho thu hai.\n";
        return NULL;
    } else {
        return minNode;
    }
}






//dem so luong so nguyen to
void dem_so_luong_so_nguyen_to(LIST l)
{
	if(l.phead==NULL) return;
	int dem=0;
	for(NODE *p=l.phead;p!=NULL;p=p->pnext)
	{
		if(isPrime(p->data))
		{
			dem++;
		}
	}
	
	cout <<"Danh sach co : "<< dem <<" so nguyen to "<<endl;
}






//sap xep tang dan
void sap_xep_phan_tu_tang_dan(LIST &l)
{
	if(l.phead==NULL) return;
	for(NODE *p=l.phead;p->pnext!=NULL;p=p->pnext)
	{
		for(NODE *q=p->pnext;q!=NULL;q=q->pnext)
		{
			if(p->data>q->data)
			{
				swap(p->data,q->data);
			}
		}
	}
}




//hàm thêm một nút có giá trị nguyên x vào vị trí thứ i trong danh sách liên kết
void them_nut_khoax_vao_i(LIST &l,int x,int vitri)
{
	NODE *nodex=tao_node(x);
	if(vitri==0)
	{
		nodex->pnext=l.phead;
		l.phead=nodex;
		if(l.pTail==nullptr)//neeus không có phần tử nào
		{
			l.pTail=nodex;
		
		}
		return;
	}
	//lính
	NODE *p=l.phead;
	int count =0;
	while(p!=NULL && count < vitri-1)
	{
		p=p->pnext;
		count++;
	}
	
	if(p!=NULL)
	{
		nodex->pnext=p->pnext;
		p->pnext=nodex;
	}
	if(nodex->pnext==NULL)
	{
		l.pTail=nodex;
	}
}





// Hàm tìm và trả về vị trí của một nút có giá trị số nguyên x trong danh sách liên kết.
// Nếu x có trong danh sách, trả về vị trí của x; ngược lại, trả về -1.
int tim_vitri_nut_giatri_x(LIST l, int x) {
    int vitri = 0;
    NODE* p = l.phead;
    while (p != NULL) {
        vitri++;
        if (p->data == x) {
            return vitri;
        }
        p = p->pnext;
    }
    // Nếu không tìm thấy giá trị x trong danh sách, trả về -1
    return -1;
}







// Hàm in ra giá trị của các nút lớn hơn số thực k từ danh sách liên kết
void in_nut_lon_hon_k(LIST l, double k) {
    bool found = false;
    cout << "Cac nut co gia tri lon hon " << k << " la: ";
    for (NODE* p = l.phead; p != NULL; p = p->pnext) {
        if (p->data > k) {
            cout << p->data << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co nut nao lon hon " << k << " trong danh sach.";
    }
    cout << endl;
}








//hamf xoa 1 nut tai giá trị k🌟🌟🌟🌟🌟
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







//🌟🌟🌟🌟🌟xoa node nhỏ hơn k 🌟🌟🌟🌟🌟
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







// Tìm node theo giá trị
NODE* tim_node(LIST l, int value) {
    NODE* p = l.phead;
    while (p != NULL) {
        if (p->data == value) {
            return p;
        }
        p = p->pnext;
    }
    return NULL;
}






// Thêm vào node sau node có giá trị value
void them_vao_sau_node_bat_ky(LIST& l, int value, int add) {
    NODE* p = khoi_tao_node(add);
    NODE* current = l.phead;
    while (current != NULL) {
        if (current->data == value) {
            NODE* nextNode = current->pnext;
            current->pnext = p;
            p->pnext = nextNode;
            if (current == l.pTail) {
                l.pTail = p;
            }
            return;
        }
        current = current->pnext;
    }
}







// Thêm n phần tử từ mảng vào sau node có giá trị value
void them_n_phan_tu_vi_tri_bat_ky(LIST& l, int a[], int n, int value) {
    NODE* nut = tim_node(l, value);
    if (nut == NULL) {
        cout << "Khong tim thay node.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        NODE* p = khoi_tao_node(a[i]);
        p->pnext = nut->pnext;
        nut->pnext = p;
        nut = p;
    }

    if (nut->pnext == NULL) {
        l.pTail = nut;
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




//xoá phần tử đầu
void xoa_phan_tu_dau(LIST& l) {
    if (l.phead == NULL) {
        return;
    }
    NODE* p = l.phead;
    l.phead = l.phead->pnext;
    if (l.phead == NULL) {
        l.pTail = NULL;
    }
    delete p;
}





//xoá phần tử cuối
void xoa_phan_tu_cuoi(LIST& l) {
    if (l.phead == NULL) {
        return;
    }
    if (l.phead == l.pTail) {
        delete l.phead;
        l.phead = l.pTail = NULL;
        return;
    }
    NODE* q = l.phead;
    while (q->pnext != l.pTail) {//chay tới khi nào gặp ptail
        q = q->pnext;
    }
    //ra khỏi while là gặp ptail
    delete l.pTail;
    q->pnext = NULL;
    l.pTail = q;
}





//xoá phần tử sau node bất kỳ
void xoa_phan_tu_sau_node_bat_ky(LIST& l, int x) {
    if (l.phead == NULL) {
        return;
    }
    NODE* p = l.phead;
    while (p != NULL && p->data != x) {
        p = p->pnext;
    }
    if (p != NULL && p->pnext != NULL) {
        NODE* q = p->pnext;
        p->pnext = q->pnext;
        if (q == l.pTail) {
            l.pTail = p;
        }
        delete q;
    }
}





//xoá tất cả giá trị có gia trị bằng key
void xoa_tat_ca_phan_tu_co_gia_tri_bang_key(LIST& l, int x) {
    if (l.phead == NULL) {
        return;
    }
    while (l.phead != NULL && l.phead->data == x) {
        xoa_phan_tu_dau(l);
    }
    NODE* current = l.phead;
    while (current != NULL && current->pnext != NULL) {
        if (current->pnext->data == x) {
            NODE* temp = current->pnext;
            current->pnext = temp->pnext;
            if (temp == l.pTail) {
                l.pTail = current;
            }
            delete temp;
        } else {
            current = current->pnext;
        }
    }
}



void xoa_cac_nut_nho_hon_5(LIST &l)
{
	if(l.phead==NULL) return 0;
	
	if(l.phead->data < 5) 
	{
		l.phead=l.phead->pnext;
		delete l.phead;
	}
}



//xoá n phần tử tại vị trí bất kỳ
void xoa_n_phan_tu_tai_vi_tri_bat_ky(LIST& l, int start, int n) {
    if (l.phead == NULL) {
        return;
    }
    NODE* current = l.phead;
    NODE* prev = nullptr;
    int count = 0;
    while (current != NULL && count < start) {
        prev = current;
        current = current->pnext;
        count++;
    }
    for (int i = 0; current != NULL && i < n; i++) {
        NODE* nextNode = current->pnext;
        delete current;
        current = nextNode;
    }
    if (prev != nullptr) {
        prev->pnext = current;
    } else {
        l.phead = current;
    }
    if (current == nullptr) {
        l.pTail = prev;
    }
}




bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}





//xoá node theo 1 NODE
void xoanode(LIST& l, NODE* del) {
    if (l.phead == NULL || del == NULL) return;
    if (l.phead == del) {
        l.phead = del->pnext;
        if (l.phead == NULL) {
            l.pTail = NULL;
        }
        delete del;
        return;
    }
    NODE* temp = l.phead;
    while (temp != NULL && temp->pnext != del) {
        temp = temp->pnext;
    }
    if (temp == NULL) return;
    temp->pnext = del->pnext;
    if (del == l.pTail) {
        l.pTail = temp;
    }
    delete del;
}





// Xóa tất cả node có giá trị lớn nhất
void xoa_phan_tu_gia_tri_lon_nhat(LIST &l) {
    if (l.phead == NULL) return;

    NODE *p = l.phead;
    int max_value = l.phead->data;
    
    // Tìm giá trị lớn nhất
    while (p != NULL) {
        if (p->data > max_value) {
            max_value = p->data;
        }
        p = p->pnext;
    }
    
    // Xóa tất cả các nút có giá trị bằng giá trị lớn nhất
    p = l.phead;
    while (p != NULL) {
        NODE *temp = p;
        p = p->pnext;
        if (temp->data == max_value) {
            xoanode(l, temp);
        }
    }
}






// Xóa các node thỏa điều kiện
void xoa_cac_nut_thoa_dieu_kien(LIST& l) {
    NODE* ptr = l.phead;
    NODE* next;
    while (ptr != NULL) {
        next = ptr->pnext;
        if (isPrime(ptr->data)) {
            xoanode(l, ptr);
        }
        ptr = next;
    }
}





//Lấy giá trị node bất kỳ
int lay_gia_tri_node_bat_ky(LIST l, int vitri) {
    NODE* current = l.phead;
    int count = 0;
    while (current != NULL) {
        if (count == vitri) {
            return current->data;
        }
        count++;
        current = current->pnext;
    }
    return -1;
}




//Tìm kiếm 1 phần tử trong danh sách
//Viết giải thuạt tìm nút (đối tượng có giá trị k trong danh sách )
NODE* tim_kiem_1_phan_tu_trong_danh_sach(LIST& l, int x) {
    NODE* q = l.phead;
    while (q != NULL) {
        if (q->data == x) {
            return q;
        }
        q = q->pnext;
    }
    return NULL; // Trả về NULL nếu không tìm thấy
}





//Tìm node có giá trị nhỏ thứ 2
NODE* tim_nut_co_gia_tri_nho_thu_hai_trong_dslk(LIST l) {
    if (l.phead == NULL || l.phead->pnext == NULL) {
        return NULL;
    }
    int firstMin = INT_MAX, secondMin = INT_MAX;
    NODE* current = l.phead;
    while (current != NULL) 
	{
        if (current->data < firstMin) 
		{
            secondMin = firstMin;
            firstMin = current->data;
        } else if (current->data < secondMin && current->data != firstMin) 
		{
            secondMin = current->data;
        }
        current = current->pnext;
    }
    if (secondMin == INT_MAX) {
        return NULL;
    }
    current = l.phead;
    while (current != NULL) {
        if (current->data == secondMin) {
            return current;
        }
        current = current->pnext;
    }
    return NULL;
}




//tìm giá trị khoá min lớn hơn k cho trước
//viết giải thuật tìm nút trong DSLK mà lưu trữ đối tượng có giá trị nhỏ nhất lớn hơn một giá trị k nguyên cho trước
NODE *tim_gia_tri_khoa_min_lon_hon_gia_tri_k(LIST l,int k)
{
	if(l.phead==NULL) return NULL;
	int min=INT_MAX;
	NODE *result=NULL;
	for(NODE *p=l.phead;p!=NULL;p=p->pnext)
	{
		if(p->data>k && p->data < min)
		{
			min=p->data;
			result=p;
		}
	}
	return result;
}





//tăng giá trị số nguyên tố lên 1
void tang_gia_tri_nguyen_to_len_1(LIST& l) {
    NODE* p = l.phead;
    while (p != NULL) {
        if (isPrime(p->data)) {
            p->data += 1;
        }
        p = p->pnext;
    }
}




//đếm số lượng phần từ danh sách
int dem_so_luong_phan_tu(LIST l) {
    int count = 0;
    NODE* p = l.phead;
    while (p != NULL) {
        count++;
        p = p->pnext;
    }
    return count;
}




//đếm số lượng số nguyên tố
int dem_so_luong_phan_tu_nguyen_to(LIST l) 
{
    int count = 0;
    NODE* p = l.phead;
    while (p != NULL) {
        if (isPrime(p->data)) {
            count++;
        }
        p = p->pnext;
    }
    return count;
}





//Viết giải thuật đếm xem danh sách l có bao nhiêu nút có giá trị nhỏ hơn hoặc bằng 1
int dem_danh_sach_gia_tri_nho_hon_hoac_bang_1(LIST l)
{
	int dem = 0;
	for(NODE *p = l.phead; p != NULL; p = p->pnext)
	{
		if((p->data) <= 1) dem++;
	}
	return dem;
}








//xoá toàn bộ danh sách
void xoa_toan_bo_danh_sach(LIST& l) {
    NODE* p = l.phead;
    while (p != NULL) {
        NODE* nextNode = p->pnext;
        delete p;
        p = nextNode;
    }
    l.phead = l.pTail = NULL;
}





// Hàm sắp xếp danh sách theo chiều tăng dần
//Sắp xếp các nút trong danh sách l theo thứ tự tăng
void sap_xep_danh_sach_tang_dan(LIST &l)
{
    if(l.phead == NULL) return; // Không cần return 0 vì hàm là void

    for(NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        for(NODE *q = p->pnext; q != NULL; q = q->pnext)
        {
            if(p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}




// Hàm sắp xếp danh sách theo chiều giảm dần
void sap_xep_danh_sach_giam_dan(LIST& l) {
    if (l.phead == NULL || l.phead->pnext == NULL) {
        return;
    }
    NODE* p = l.phead;
    while (p != NULL) {
        NODE* q = p->pnext;
        while (q != NULL) {
            if (p->data < q->data) {
                swap(p->data, q->data);
            }
            q = q->pnext;
        }
        p = p->pnext;
    }
}








// Hàm tách danh sách thành 2 danh sách chẵn và lẻ
void tach_danh_sach_chan_le(LIST& l, LIST& chan, LIST& le) {
    NODE* p = l.phead;
    while (p != NULL) {
        if (p->data % 2 == 0) {
            them_vao_cuoi(chan, p->data);
        } else {
            them_vao_cuoi(le, p->data);
        }
        p = p->pnext;
    }
}







// Hàm tạo danh sách chỉ chứa các số nguyên tố
void tao_danh_sach_chi_chua_so_nguyen_to(LIST& l, LIST& primeList) {
    NODE* p = l.phead;
    while (p != NULL) {
        if (isPrime(p->data)) {
            them_vao_cuoi(primeList, p->data);
        }
        p = p->pnext;
    }
}





// Hàm trộn 2 danh sách tăng dần
void tron_hai_danh_sach_tang_dan(LIST& l1, LIST& l2, LIST& result) {
    NODE* p1 = l1.phead;
    NODE* p2 = l2.phead;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            them_vao_cuoi(result, p1->data);
            p1 = p1->pnext;
        } else {
            them_vao_cuoi(result, p2->data);
            p2 = p2->pnext;
        }
    }
    while (p1 != NULL) {
        them_vao_cuoi(result, p1->data);
        p1 = p1->pnext;
    }
    while (p2 != NULL) {
        them_vao_cuoi(result, p2->data);
        p2 = p2->pnext;
    }
}





// Hàm sắp xếp số chẵn lên đầu
void sap_xep_chan_len_dau(LIST& l) {
    LIST chan, le;
    khoi_tao_list(chan);
    khoi_tao_list(le);
    NODE* p = l.phead;
    while (p != NULL) {
        if (p->data % 2 == 0) {
            them_vao_cuoi(chan, p->data);
        } else {
            them_vao_cuoi(le, p->data);
        }
        p = p->pnext;
    }
    l.phead = chan.phead;
    chan.pTail->pnext = le.phead;
    l.pTail = le.pTail;
}






// Hàm chèn vào danh sách sao cho vẫn có thứ tự
void chen_vao_danh_sach(LIST& l, int value) {
    NODE* p = khoi_tao_node(value);
    if (l.phead == NULL || l.phead->data >= value) {//khi danh sách không có phần tử nào mà l.pheadata>=value==>ta chèn vào đầu
        p->pnext = l.phead;
        l.phead = p;
        if (l.pTail == NULL) {
            l.pTail = p;
        }
        return;
    }
    NODE* current = l.phead;
    while (current->pnext != NULL && current->pnext->data < value) {
        current = current->pnext;
    }
    p->pnext = current->pnext;
    current->pnext = p;
    if (p->pnext == NULL) {
        l.pTail = p;
    }
}



int main() {
    LIST l;
    khoi_tao_list(l);
    int choice;
    do {
        system("cls");
        cout << "1. Them node vao cuoi danh sach\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Them node vao dau danh sach\n";
        cout << "4. Them node vao sau node co gia tri value\n";
        cout << "5. Them n phan tu vao sau node co gia tri value\n";
        cout << "6. Xoa phan tu dau\n";
        cout << "7. Xoa phan tu cuoi\n";
        cout << "8. Xoa node sau node co gia tri x\n";
        cout << "9. Xoa tat ca node co gia tri x\n";
        cout << "10. Xoa n node bat dau tu vi tri start\n";
        cout << "11. Xoa cac node thoa dieu kien\n";
        cout << "12. Lay gia tri node bat ky\n";
        cout << "13. Tim node co gia tri nho thu hai\n";
        cout << "14. Tim node co khoa nho nhat lon hon k\n";
        cout << "15. Xoa tat ca node co gia tri lon nhat\n";
        cout << "16. Tang gia tri nut nguyen to len 1\n";
        cout << "17. Xoa tat ca phan tu co gia tri bang x\n";
        cout << "18. Dem so luong phan tu trong danh sach\n";
        cout << "19. Dem so luong phan tu nguyen to\n";
        cout << "20. Xoa toan bo danh sach\n";
        cout << "21. Sap xep tang dan\n";
        cout << "22. Sap xep giam dan\n";
        cout << "23. Xoa phan tu le va luu vao danh sach khac\n";
        cout << "24. Tach danh sach thanh chan le\n";
        cout << "25. Tao danh sach chi chua so nguyen to\n";
        cout << "26. Tron 2 danh sach tang dan\n";
        cout << "27. Sap xep chan len dau\n";
        cout << "28. Chen vao danh sach sao cho van co thu tu\n";
        cout << "29. Do dai danh sach lien ket\n";
        cout << "30. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int x;
            cout << "Nhap gia tri: ";
            cin >> x;
            them_vao_cuoi(l, x);
            break;
        }
        case 2:
            hien_thi_danh_sach(l);
            system("pause");
            break;
        case 3: {
            int x;
            cout << "Nhap gia tri: ";
            cin >> x;
            them_vao_dau(l, x);
            break;
        }
        case 4: {
            int value, add;
            cout << "Nhap gia tri node can tim: ";
            cin >> value;
            cout << "Nhap gia tri node can them: ";
            cin >> add;
            them_vao_sau_node_bat_ky(l, value, add);
            break;
        }
        case 5: {
            int n, value;
            cout << "Nhap so luong node can them: ";
            cin >> n;
            int a[n];
            for (int i = 0; i < n; i++) {
                cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
                cin >> a[i];
            }
            cout << "Nhap gia tri node can tim: ";
            cin >> value;
            them_n_phan_tu_vi_tri_bat_ky(l, a, n, value);
            break;
        }
        case 6:
            xoa_phan_tu_dau(l);
            break;
        case 7:
            xoa_phan_tu_cuoi(l);
            break;
        case 8: {
            int x;
            cout << "Nhap gia tri node can tim: ";
            cin >> x;
            xoa_phan_tu_sau_node_bat_ky(l, x);
            break;
        }
        case 9: {
            int x;
            cout << "Nhap gia tri x: ";
            cin >> x;
            xoa_tat_ca_phan_tu_co_gia_tri_bang_key(l, x);
            break;
        }
        case 10: {
            int start, n;
            cout << "Nhap vi tri bat dau: ";
            cin >> start;
            cout << "Nhap so luong node can xoa: ";
            cin >> n;
            xoa_n_phan_tu_tai_vi_tri_bat_ky(l, start, n);
            break;
        }
        case 11:
            xoa_cac_nut_thoa_dieu_kien(l);
            break;
        case 12: {
            int vitri;
            cout << "Nhap vi tri node can lay gia tri: ";
            cin >> vitri;
            cout << "Gia tri node tai vi tri " << vitri << " la: " << lay_gia_tri_node_bat_ky(l, vitri) << endl;
            system("pause");
            break;
        }
        case 13: {
            NODE* node = tim_nut_co_gia_tri_nho_thu_hai_trong_dslk(l);
            if (node != NULL) {
                cout << "Gia tri node nho thu hai: " << node->data << endl;
            } else {
                cout << "Khong tim thay node nho thu hai\n";
            }
            system("pause");
            break;
        }
        case 14: {
            int k;
            cout << "Nhap gia tri k: ";
            cin >> k;
            NODE* node = tim_nut_khoa_min_lon_hon_gia_tri_k(l, k);
            if (node != NULL) {
                cout << "Node co khoa nho nhat lon hon " << k << " la: " << node->data << endl;
            } else {
                cout << "Khong tim thay node nao lon hon " << k << endl;
            }
            system("pause");
            break;
        }
        case 15:
            xoa_phan_tu_gia_tri_lon_nhat(l);
            break;
        case 16:
            tang_gia_tri_nguyen_to_len_1(l);
            break;
        case 17: {
            int x;
            cout << "Nhap gia tri x: ";
            cin >> x;
            xoa_tat_ca_phan_tu_co_gia_tri_bang_key(l, x);
            break;
        }
        case 18:
            cout << "So luong phan tu trong danh sach la: " << dem_so_luong_phan_tu(l) << endl;
            system("pause");
            break;
        case 19:
            cout << "So luong phan tu nguyen to trong danh sach la: " << dem_so_luong_phan_tu_nguyen_to(l) << endl;
            system("pause");
            break;
        case 20:
            xoa_toan_bo_danh_sach(l);
            break;
        case 21:
            sap_xep_danh_sach_tang_dan(l);
            break;
        case 22:
            sap_xep_danh_sach_giam_dan(l);
            break;
        case 23: {
            LIST l1;
            khoi_tao_list(l1);
            NODE* p = l.phead;
            while (p != NULL) {
                if (p->data % 2 != 0) {
                    them_vao_cuoi(l1, p->data);
                }
                p = p->pnext;
            }
            p = l1.phead;
            while (p != NULL) {
                xoa_tat_ca_phan_tu_co_gia_tri_bang_key(l, p->data);
                p = p->pnext;
            }
            hien_thi_danh_sach(l1);
            system("pause");
            break;
        }
        case 24: {
            LIST chan, le;
            khoi_tao_list(chan);
            khoi_tao_list(le);
            tach_danh_sach_chan_le(l, chan, le);
            cout << "Danh sach chan: ";
            hien_thi_danh_sach(chan);
            cout << "Danh sach le: ";
            hien_thi_danh_sach(le);
            system("pause");
            break;
        }
        case 25: {
            LIST primeList;
            khoi_tao_list(primeList);
            tao_danh_sach_chi_chua_so_nguyen_to(l, primeList);
            hien_thi_danh_sach(primeList);
            system("pause");
            break;
        }
        case 26: {
            LIST l1, l2, result;
            khoi_tao_list(l1);
            khoi_tao_list(l2);
            khoi_tao_list(result);
            int n1, n2, x;
            cout << "Nhap so luong phan tu danh sach 1: ";
            cin >> n1;
            for (int i = 0; i < n1; i++) {
                cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
                cin >> x;
                them_vao_cuoi(l1, x);
            }
            cout << "Nhap so luong phan tu danh sach 2: ";
            cin >> n2;
            for (int i = 0; i < n2; i++) {
                cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
                cin >> x;
                them_vao_cuoi(l2, x);
            }
            tron_hai_danh_sach_tang_dan(l1, l2, result);
            hien_thi_danh_sach(result);
            system("pause");
            break;
        }
        case 27:
        	{
			
            sap_xep_chan_len_dau(l);
            break;
        }
        case 28: {
            int value;
            cout << "Nhap gia tri can chen: ";
            cin >> value;
            chen_vao_danh_sach(l, value);
            break;
        }
        case 29:{
        	int lenlist=do_dai_list(l);
        	cout <<"Danh sach co do dai la : "<<lenlist <<endl;
        	
			break;
		}
        }
    } while (choice != 100);
    return 0;
}
