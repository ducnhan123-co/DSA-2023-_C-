#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

typedef struct diem {
	float dai_so = 0;
	float Mac = 0;
	float cpp = 0;
} diem;

typedef struct sv {
	string ho;
	string ten;
	string ma_sv;
	string phai;
	diem ds_diem;
} sv;

struct node_sv {
	sv data;
	node_sv* pNext;
};

typedef struct node_sv node_sv;

typedef struct danhsach {
	node_sv* pHead = NULL;
	node_sv* pTail = NULL;
} danhsach;

istream& operator >> (istream& is, sv& a) {
	cout << "Nhap ho: ";
	getline(is, a.ho);
	cout << "Nhap ten: ";
	getline(is, a.ten);
	cout << "Nhap phai: ";
	getline(is, a.phai);
	cout << "Nhap ma sinh vien: ";
	getline(is, a.ma_sv);

	return is;
}

node_sv* khoi_tao_node(sv x) {
	node_sv* p = new node_sv;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void them(danhsach& dssv, sv x) {// them vao cuoi
	node_sv* p = khoi_tao_node(x);
	if (dssv.pHead == NULL) {
		dssv.pHead = dssv.pTail = p;
	}
	else {
		dssv.pTail->pNext = p;
		dssv.pTail = p;
	}
}

void xuat(danhsach& dssv) {
	int i = 1;
	for (node_sv* k = dssv.pHead; k != NULL; k = k->pNext) {
		cout << "\t\t----- Sinh vien " << i++ << " ----- " << endl;
		cout << "Ma sv: " << k->data.ma_sv << endl;
		cout << "Ho ten: " << k->data.ho << " " << k->data.ten << endl;
		cout << "Phai: " << k->data.phai << endl;
		cout << "---- Diem: ----" << endl;
		cout << "Dai so: " << k->data.ds_diem.dai_so << endl;
		cout << "Mac: " << k->data.ds_diem.Mac << endl;
		cout << "Cpp: " << k->data.ds_diem.cpp << endl;
	}
}
/*
void load_file(danhsach &dssv)
{
	ifstream filein("input.txt");
	while (filein.eof()==false)
	{
		sv a;
		getline(filein,a.ho);
		getline(filein,a.ten);
		getline(filein,a.ma_sv);
		getline(filein,a.phai);
		filein >> a.ds_diem.dai_so;
		filein.ignore();
		filein >>a.ds_diem.Mac;
		filein.ignore();
		filein >>a.ds_diem.cpp;
		filein.ignore();
       them(dssv,a)
	}
}
*/
void xoa_sv(danhsach& dssv, const string& vt) {
    // Trường hợp danh sách rỗng
    if (dssv.pHead == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    // Trường hợp xóa ở đầu danh sách
    while (dssv.pHead != NULL && dssv.pHead->data.ma_sv.compare(vt) == 0) {
        node_sv* temp = dssv.pHead;
        dssv.pHead = dssv.pHead->pNext;
        delete temp;
        // Kiểm tra nếu danh sách đã trở thành rỗng
        if (dssv.pHead == NULL) {
            dssv.pTail = NULL;
            cout << "Xoa thanh cong!" << endl;
            return;
        }
    }

    // Trường hợp xóa ở vị trí khác đầu danh sách
    node_sv* previous = dssv.pHead;
    node_sv* current = dssv.pHead->pNext;
    while (current != NULL) {
        if (current->data.ma_sv.compare(vt) == 0) {
            previous->pNext = current->pNext;
            delete current;
            // Kiểm tra nếu current là phần tử cuối cùng trong danh sách
            if (previous->pNext == NULL) {
                dssv.pTail = previous;
            }
            cout << "Xoa thanh cong!" << endl;
            return;
        }
        previous = current;
        current = current->pNext;
    }

    // Trường hợp không tìm thấy sinh viên cần xóa
    cout << "Khong tim thay sinh vien co ma " << vt << endl;
}


void menu() {
	danhsach dssv;
	//load_file(dssv);
	bool kt_menu = true;
	while (kt_menu == true) {
		system("cls");
		cout << "1. Nhap sinh vien" << endl;
		cout << "2. Xuat danh sach sinh vien" << endl;
		cout << "3. Xoa 1 sinh vien"<<endl;
		cout << "0. Thoat" << endl;
		int lc;
		cout << "Nhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 1: {
			int sl;
			cout << "Nhap so luong sinh vien can them: ";
			cin >> sl;
			cin.ignore();
			for (int i = 1; i <= sl; i++) {
				cout << "\t\t ===== Nhap sinh vien thu " << i << " ===== " << endl;
				sv x;
				cin >> x;
				them(dssv, x);
			}
			break;
		}
		case 2:
			xuat(dssv);
			system("pause");
			break;
		case 0:
			kt_menu = false;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			break;
		case 3:
			string vt;
			cin.ignore();
			cout<<"Nhap vi tri sinh vien can xoa : ";
			getline(cin,vt);
			xoa_sv(dssv,vt);
			
		}
	}
}

int main() {
	menu();
	return 0;
}
