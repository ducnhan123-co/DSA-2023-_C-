#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void NhapChuoi(string& s) {
    cout << "Nhap chuoi: ";
    getline(cin, s);
     cin.ignore(); 
}

void XuatChuoi(string s) {
    cout << "Chuoi vua nhap la: " << s << endl;
}

void chuhoadau(char *s)
{
    s[0] = toupper(s[0]);
    while (strstr(s, " ") != NULL)
    {
        s = strstr(s, " ") + 1;
        s[0] = toupper(s[0]);
    }
}
//check 
int demkhoangtrang(char *s)
{
int d=0;
while(strstr(s," ")!=NULL)
{
d++;
s=strstr(s," ")+1;
}
return d;
} 
//check
void xoakhoangtrangduthua(string  &s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ' && s[i+1]==' ')
		{
			s.erase(s.begin()+i);
			i--;
		}
	}
}

//void noichuoi(char *a,char *b)
//{ 
//strcat(a,b);
//puts(a);
//} 
void noichuoi(string& a, string& b) {
    a += b; // N?i chu?i b vào sau chu?i a
    cout << a <<endl;
}

void chuthuong(string &s){
	for(int i = 0; i < s.size(); i++){
		s[i] = tolower(s[i]);
	}
	
//	cout << s<< endl;
}
void chuhoa(string &s){
	for(int i = 0; i < s.size(); i++){
		s[i] = toupper(s[i]);
	}
	
	cout << s<< endl;
}

void chuxenke(string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }
        }
    }
    cout << s << endl;
}
void daochuoi(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}


//Vi?t chuong trình tìm ki?m 1 kí t? xem có trong chu?i không, n?u có xu?t ra v? trí c?a t? ch? kí t? dó
void vitritucantim(const string &s, char t) {
    int n = s.size();
    int dem = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            dem++;
        } else if (s[i] == t) {
            cout << "Vi tri chu ky tu '" << t << " la " << dem << endl;
            return; 
        }
    }
    cout << "Ky tu '" << t << "khong xuat hien trong chuoi." << endl;
}

//Vi?t 1 chuong trình d?m m?t ký t? xu?t hi?n bao nhiêu l?n trong chu?i.
void demkytuxuathien(string &s,char t)
{
	int dem=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]==t) dem++;
	}
	cout << "Ky tu  "<< t <<" xuat hien " << dem << " lan ";
}
//Nh?p vào chu?i s1 và s2, cho bi?t v? trí xu?t hi?n c?a chu?i s2 trong s1. 
int vitri(char *a,char *b)
{
int d=-1;
if(strstr(a,b)!=NULL)
cout << strlen(a) << endl;
cout << strstr(a,b)<<endl;  // strstr phan duc nhan / duc ==>duc nhan
cout <<strlen(strstr(a,b))<<endl;  
d=strlen(a)-strlen(strstr(a,b)); // do dai cua chuoi a tru di do dai cua chuoi con b co trong a // vi du phan duc nhan ==>do dai la 13 // duc // chuoi con la 3 
return d;
} 

// tim ten
void timten(const char *a, const char *b) {
    int n = strlen(a);
    const char *s = NULL;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == ' ') {
            s = a + i + 1;
            break;
        }
    }
    if (s != NULL) {
        // Chuy?n d?i tên trong chu?i thành ch? thu?ng
        char tenTrongChuoi[strlen(s) + 1];
        strcpy(tenTrongChuoi, s);


        // Chuy?n d?i tên dã nh?p thành ch? thu?ng
        char tenNhap[strlen(b) + 1];
        strcpy(tenNhap, b);
 

        // So sánh hai chu?i tên
        if (strcmp(tenTrongChuoi, tenNhap) == 0) {
            cout << "ban da nhap dung ten " << s << endl;
        } else {
            cout << "Ban nhap sai ten\n";
        }
    } else {
        cout << "Chuoi khong có ten\n";
    }
}
//dao vi tri
void daoViTriTuDauVaTuCuoi(string &s) {
    // T?o m?t stringstream d? chia chu?i thành các t?
    stringstream ss(s);
    string word;
    vector<string> words;

    // Ð?c t?ng t? t? chu?i vào vector
    while (ss >> word) {
        words.push_back(word);
    }

    // N?u có ít nh?t hai t? trong chu?i, d?o v? trí c?a t? d?u và t? cu?i
    if (words.size() >= 2) {
        swap(words.front(), words.back());

        // Xây d?ng chu?i m?i t? các t? trong vector
        stringstream result;
       for (size_t i = 0; i < words.size(); ++i) {
    result << words[i] << " ";
}

        // Gán l?i chu?i k?t qu? vào chu?i s
        s = result.str();
    }
}
void cathoten(char *s) {
    char *t;
    int i;
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' ' && s[i + 1] != ' ') { // luc duy?t dang duyet o s[i]
            break;
        }
    }
    t = s + i + 1; // s la chuoi ==> vi ta la chuoi nen tra ve chuoi  chuoi + 1 tu la tu do === phan + 2= phandu //
    s[i] = '\0';
    cout << "ho lot: " << s << endl;
    cout << "ho ten: " << t << endl;
}

//tim tu
void timtu(char *a,char *b)
{
char *t=strstr(a,b);//vi tri xuat hien b dau tien trong a
puts(t);
} 


//doi xung
bool kiemtrachuoidoixung (string &s)
{
	string reversed = s;
	reverse(reversed.begin(),reversed.end());
	return s == reversed;
}

//tach so ra khoi chuoi 
void tachso(char *s) {
    int a[100], j = 0;

    // Bước 1: Duyệt qua từng ký tự trong chuỗi s
    for (int i = 0; i < strlen(s); i++) {
        // Bước 2: Kiểm tra nếu ký tự hiện tại là một chữ số
        if (s[i] >= '0' && s[i] <= '9') {
            // Bước 3: Chuyển đổi ký tự thành số và lưu vào mảng a
            a[j] = s[i] - '0'; // Chuyển đổi ký tự thành số
            j++; // Tăng chỉ số mảng để lưu số tiếp theo

            // Bước 4: Dịch chuyển các ký tự trong chuỗi để loại bỏ số vừa tách
            for (int t = i; t < strlen(s); t++) {
                s[t] = s[t + 1]; // Di chuyển mỗi ký tự từ vị trí t+1 đến vị trí t
            }
            i--; // Giảm biến i để xem xét lại ký tự tiếp theo
        }
    }

    // In ra các số đã tách
    cout << "Cac so da tach tu chuoi la: ";
    for (int i = 0; i < j; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // In ra chuỗi s sau khi loại bỏ các số
    cout << "Chuoi sau khi loai bo cac so: " << s << endl;
}
void xoakitu(string &s, char b) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == b) {
            for (int j = i; j < n; j++) {
                s[j] = s[j + 1];
            }
            i--; // Giảm biến lặp i để kiểm tra lại ký tự tiếp theo
            n--; // Giảm kích thước của chuỗi đi một đơn vị
        }
    }
    cout << "Chuoi sau khi xoa la : "<<s <<endl;
}
// in hoa ky tu dau cua chuoi
void inhoakitudauchuoi(string &s)
{
	chuthuong(s);
	if (s[0] !=' ')
	{
		s[0]=s[0]-32;
	}
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]==' ' && s[i+1] !=' ')
		{
			s[i+1]=s[i+1]-32;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
	}
}
// void dao thu tu cac tu
void daothutu(char *s)
{
char c[255];
c[0]='\0';//ham strcat noi chuoi tai vi tri NULL
for(int i=strlen(s)-1;i>=0;i--)
if(s[i]==' ')
{
strcat(strcat(c,s+i+1)," ");
s[i]='\0';
}
strcat(c,s);
puts(c);
}

// xoa n ki tu tu vi tri vt
void xoa(string &s, int vt, int n) {
    s.erase(vt, n);
    cout << s;
}

//chen 1 chuoi d sau vi tri vt 
void chen(char *s, char *d, int vt)
{
    char c[255];
    strcpy(c, s + vt);
    cout << "vi tri s+vt: " << *(s + vt) << endl;
    cout << "vi tri strcpy(c,s+vt) "<< strcpy(c,s+vt) <<endl;
    cout << "chuoi c hien tai : "<< c <<endl;
    cout << "vi tri d : " << d << endl;
    strcpy(s + vt, d);
    cout << "vi tri s+vt hien tai : "<< *(s+vt) <<endl;
    cout << "vi tri d hien tai : "<< d<< endl;
    cout << "chuoi s hien tai :" << s <<endl;
    cout <<"chuoi c hien tai : "<<c<<endl;
    strcat(s, c);

    puts(s);
}
//xoa tu nhap o ban phim
void xoaTu(string &s, string tuXoa) {
    // Tìm vị trí của từ cần xóa trong chuỗi
    int viTri = s.find(tuXoa);
    
    // Nếu từ cần xóa không tồn tại trong chuỗi, không làm gì cả
    if (viTri == -1) {
        cout << "Tu khong ton tai trong chuoi." << endl;
        return;
    }
    
    // Xóa từ khỏi chuỗi
    s.erase(viTri, tuXoa.length());
    cout << s;
}

// ky tu xuat hien nhieu nhat trong chuoi 
char timKyTuXuatHienNhieuNhat(const string &s) {
    // Mảng để lưu số lần xuất hiện của mỗi ký tự
    int dem[256] = {0};

    // Lặp qua từng ký tự trong chuỗi và đếm số lần xuất hiện
    for (char kyTu : s) {
        dem[kyTu]++;
    }

    // Tìm ký tự xuất hiện nhiều nhất
    char kyTuXuatHienNhieuNhat = '\0';
    int soLanXuatHienNhieuNhat = 0;

    for (int i = 0; i < 256; ++i) {
        if (dem[i] > soLanXuatHienNhieuNhat) {
            kyTuXuatHienNhieuNhat = static_cast<char>(i);
            soLanXuatHienNhieuNhat = dem[i];
        }
    }

    return kyTuXuatHienNhieuNhat;
}
//dem so lan xuat hien
void demSoLanXuatHien(const string &chuoi) {
    // Mảng để lưu số lần xuất hiện của mỗi ký tự
    int dem[256] = {0};

    // Lặp qua từng ký tự trong chuỗi và đếm số lần xuất hiện
    for (char kyTu : chuoi) {
        // Tăng giá trị tương ứng trong mảng dem lên 1
        dem[(kyTu)]++;
    }

    // Liệt kê số lần xuất hiện của mỗi ký tự
    for (int i = 0; i < 256; ++i) {
        if (dem[i] > 0) {
            cout << "Ky tu '" << static_cast<char>(i) << "' xuat hien " << dem[i] << " lan." << endl;
        }
    }
}
void menu(string& s) {
    int lc;
    while (true) {
        system("cls"); // Xóa màn hình
        cout << "1. Nhap chuoi can xu ly" << endl;
        cout << "2. Xuat chuoi vua nhap" << endl;
        cout << "3. Xuat chu hoa dau cua moi tu " << endl;
        cout << "4. Dem khoang trang trong chuoi "<<endl;
         cout << "5. Xoa khoang trang du thua trong chuoi "<<endl;
        cout << "6. Noi 2 chuoi a va b "<<endl;
        cout << "7. Chuyen chuoi sang chu thuong "<<endl;
        cout << "8. Chuyen chuoi sang chu hoa "<<endl;
        cout << "9. Chuyen chuoi xen ke hoa va thuong "<<endl;
         cout << "10. Dao chuoi vua nhap "<<endl;
        cout << "11. Vi tri cua tu chua ki tu can tim "<<endl;
        cout << "12. Dem xem 1 ky tu xuat hien bao nhieu lan "<<endl;
        cout << "13. Vi tri xuat hien chuoi s2 trong chuoi s1 "<<endl;
        cout << "14. Tim ten "<<endl;
        cout << "15. Dao vi tri tu dau tien va cuoi cung cua chuoi "<<endl;
        cout << "16. Cat ho va ten cua 1 chuoi "<<endl;
        cout << "17. Tach tu bat dau tu mot tu cho truoc trong chuoi "<<endl;
        cout << "18. Kiem tra 1 chuoi co doi xung hay khong "<<endl;
        cout << "19. Tach so ra khoi chuoi va luu vao mang rieng "<<endl;
        cout << "20. Xoa 1 ki tu trong chuoi "<<endl;
        cout << "21. In hoa 1 ki dau cua 1 chuoi "<<endl;
        cout << "22. Dao thu tu cua cac tu trong chuoi "<<endl;
        cout << "23. Xoa n ki tu tu vi tri vt trong chuoi "<<endl;
        cout << "24. Chen mot chuoi d sau vi tri vt"<<endl;
        cout << "25. Xoa 1 tu nhap o ban phim trong chuoi"<<endl;
        cout << "26. Ki tu xuat hien nhieu nhat trong chuoi la : "<<endl;
        cout << "27. Moi ki tu xuat hien bao nhieu lan : "<<endl;
        cout << "0. Ket thuc" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        cin.ignore();
		if (lc == 1) {
            NhapChuoi(s);
        }
        else if (lc == 2) {
            XuatChuoi(s);
        }
        else if (lc == 3) {
            chuhoadau(&s[0]);
            XuatChuoi(s);
        }
        else if (lc == 4) {
            int d_emkhoangtrang = demkhoangtrang(&s[0]);
            cout << "Chuoi co : " << d_emkhoangtrang << " khoang trang " <<endl;
        }
         else if (lc == 5) {
           //xoa khoang trang du thua
           xoakhoangtrangduthua(s);
            XuatChuoi(s);
        
           
        }
          else if (lc == 6) {
          string a;
          cout <<"Nhap vao chuoi a : ";
          getline(cin,a);
       
          string b;
          cout <<"Nhap vao chuoi b : ";
          getline(cin,b);
          noichuoi(a,b);
        }
         else if (lc == 7) {
            chuthuong(s);
           
        }
         else if (lc == 8) {
            chuhoa(s);
           
        }
        else if (lc == 9) {
            chuxenke(s);
           
        }
         else if (lc == 10) {
            daochuoi(s);
            XuatChuoi(s);
        }
        else if (lc == 11) {
        	char t;
        	cout <<"Nhap ki tu t can tim kiem : ";
        	cin >> t;
           vitritucantim(s,t);
        }
         else if (lc == 12) {
        	char t;
        	cout <<"Nhap ki tu t can dem so lan xuat hien : ";
        	cin >> t;
           demkytuxuathien(s,t);
        }
        else if (lc == 13) {
          string a;
          cout <<"Nhap vao chuoi a : ";
          getline(cin,a);
       
          string b;
          cout <<"Nhap vao chuoi b : ";
          getline(cin,b);
          int vitrixuathien =vitri(&a[0],&b[0]);
          cout << "Vi tri xuat hien chuoi a trong chuoi b la : "<< vitrixuathien <<endl;
        }
          else if (lc == 14) {
          string a;
          cout <<"Nhap vao chuoi a : ";
          getline(cin,a);
       
          string b;
          cout <<"Nhap vao chuoi b : ";
          getline(cin,b);
          timten(&a[0],&b[0]);
        }
        else if (lc==15)
        {
        	daoViTriTuDauVaTuCuoi(s);
        	    XuatChuoi(s);
		}
		else if (lc==16)
        {
        	
        	cathoten(&s[0]);
        	
		}
		else if (lc == 17) {
           string a;
          cout <<"Nhap vao chuoi a : ";
          getline(cin,a);
       
          string b;
          cout <<"Nhap vao chuoi b : ";
          getline(cin,b);
          timtu(&a[0],&b[0]);
        }
        else if (lc==18)
        {
        	
        	kiemtrachuoidoixung(s);
        	if(kiemtrachuoidoixung(s)) 
        	{
        		cout <<"Chuoi doi xung "<<endl;
			}
			else cout <<" chuoi khong doi xung "<<endl;
        	
		}
		else if (lc==19)
		{
			tachso(&s[0]);
		}
		else if (lc==20)
		{
			char b;
			cout <<"Nhap ki tu b can xoa ";
			cin>>b;
			xoakitu(s,b);
		}
		else if (lc==21)
		{
			inhoakitudauchuoi(s);
			cout <<endl;
		}
			else if (lc==22)
		{
		daothutu(&s[0]);
			cout <<endl;
		}
		else if (lc==23)
		{
			int vt;
			cout <<"Nhap vi tri trong chuoi can xoa : ";
			cin >> vt;
			int n;
			cout << "Nhap so luong ki tu can xoa tu vt : ";
			cin >>n;
	      xoa(s,vt,n);
	      cout <<endl;
		}
	else if (lc == 24)
{
    char d[255]; // Khai báo một mảng ký tự để lưu trữ chuỗi d
    cout << "Nhap chuoi d can chen vao: ";
    cin.getline(d, sizeof(d)); // Đọc chuỗi d từ người dùng

    int vt;
    cout << "Nhap vi tri can chen chuoi d vao: ";
    cin >> vt;

    chen(&s[0], d, vt);
}
	else if (lc==25)
		{
			string tuxoa;
			cout << "Nhap 1 tu can xoa : ";
			getline(cin,tuxoa);

			xoaTu(s,tuxoa);
		}
		else if(lc==26)
		{
			char kitumax=timKyTuXuatHienNhieuNhat(s);
			if (kitumax != '\0') {
         cout << "Ky tu xuat hien nhieu nhat la: " << kitumax << endl;
    } else {
        cout << "Khong co ky tu nao trong chuoi." << endl;
    }
		}
			else if(lc==27)
		{
			demSoLanXuatHien(s);
		}

        else if (lc == 0) {
            break; // Thoát kh?i vòng l?p
        }
        else {
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
        }
        system("pause"); // D?ng màn hình
    }
}

int main() {
    string s;
    menu(s);
    return 0;
}