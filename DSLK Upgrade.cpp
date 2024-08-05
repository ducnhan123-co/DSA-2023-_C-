#include<iostream>
using namespace std;
int main()
{
 ptrNode avlTree;
 Init(avlTree); // Tạo cây avlTree rỗng
 int option = 0;
 do
 {
 system("cls");
 cout << "Cac tac vu cua cay:" << endl;
 cout << "1. Kiem tra cay rong." << endl;
 cout << "2. Them khoa vao cay." << endl;
 cout << "3. Tim kiem khoa trong cay." << endl;
 cout << "4. Loai bo khoa trong cay." << endl;
 cout << "5. Duyet cay theo thu tu NLR." << endl;
 cout << "6. Kiem tra tinh can bang." << endl;
 cout << "7. Huy bo cay." << endl;
 cout << "0. Ket thuc." << endl;
 cout << "Chon tac vu: ";
 cin >> option;
 switch(option)
 {
 case 1: // Kiểm tra cây rỗng
 {
 // Kiểm tra cây avlTree rỗng
 if (IsEmpty(avlTree))
 cout << "Cay rong ..." << endl;
 else
 cout << "Cay khac rong ..." << endl;
 system("pause");
 break;
 }
 case 2: // Thêm khóa vào cây
 {
 int theKey;
 cout << "Nhap khoa them vao: ";
 cin >> theKey;
 // Thêm khóa theKey vào cây avlTree
 Insert(avlTree, theKey);
 break;
 }
 case 3: // Tìm kiếm khóa trong cây
 {
 int theKey;
 cout << "Nhap khoa tim kiem: ";
 cin >> theKey;
 // Tìm kiếm khóa theKey trong cây avlTree
 ptrNode p = Find(avlTree, theKey);
 if (p != NULL)
 cout << "Tim thay khoa " << p->Key << endl;
 else
 cout << "Khong tim thay khoa " << theKey << endl;
 system("pause");
 break;
 }
 case 4: // Loại bỏ khóa trong cây
 {
 int theKey;
 cout << "Nhap khoa loai bo: ";
 cin >> theKey;
 bool error;
 // Loại bỏ khóa theKey của cây avlTree
 Remove(avlTree, theKey, error);
 if (error)
 {
 cout << "Khong co khoa " << theKey << endl;
 system("pause");
 }
 break;
 }
 case 5: // Duyệt cây theo thứ tự NLR
 {
 if (IsEmpty(avlTree))
 cout << "Cay rong ..." << endl;
 else
 // Duyệt cây avlTree theo thứ tự NLR
 Traverse(avlTree);
 system("pause");
 break;
 }
 case 6: // Kiểm tra tính cân bằng
 {
 int a[] = {4, 2, 1, 0, 0, 3, 0, 0, 5, 0, 8, 7, 6,
 0, 0, 0, 0};
 int i = 0;
 // Tạo cây avlTree từ mảng a[]
 Create(avlTree, a, i);
 int height;
 // Kiểm tra cây avlTree có tính cân bằng
 bool avl = IsBalanced(avlTree, height);
 if (avl)
 cout << "Cay co tinh can bang" << endl;
 else
 cout << "Cay khong co tinh can bang" << endl;
 system("pause");
 break;
 }
 case 7: // Hủy bỏ cây
 {
 // Hủy bỏ cây avlTree
 Clear(avlTree);
 break;
 }
 }
 } while (option != 0);
 return 0;
}