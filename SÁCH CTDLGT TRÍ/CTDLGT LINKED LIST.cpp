#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

// Khởi tạo cấu trúc cho một nút
struct Node {
    int data;
    Node *next; // Phần liên kết
};

// Khởi tạo một danh sách
void init(Node *&head) {
    head = NULL;
}

// Tạo một nút mới trong danh sách
Node *CreateNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm một phần tử vào đầu danh sách
void addFirst(Node *&head, int x) {
    Node *p = CreateNode(x);
    p->next = head;
    head = p;
}

// Xuất ra danh sách
void output(Node *head) {
    Node *p = head;
    while (p != NULL) {
        cout << p->data << "     ";
        p = p->next;
    }
}

// Thêm một phần tử vào cuối danh sách
void addLast(Node *&head, int x) {
    Node *p = CreateNode(x);
    if (head == NULL) {
        head = p;
        return;
    }
    Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = p;
}

// Thêm một phần tử sau một phần tử chỉ định
void addAfter(Node *head, int v, int x) {
    Node *p = CreateNode(x);
    Node *q = head;
    while (q != NULL && q->data != v) {
        q = q->next;
    }
    if (q != NULL) {
        p->next = q->next;
        q->next = p;
    }
}

// Tìm kiếm một phần tử trong danh sách liên kết
int searchLinkedList(Node *head, int x) {
    Node *current = head;
    int index = 0;
    while (current != NULL) {
        if (current->data == x) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Xóa phần tử đầu tiên trong danh sách liên kết
void deleteFirst(Node *&head) {
    if (head != NULL) {
        Node *p = head;
        head = p->next;
        delete p;
    }
}

// Xóa phần tử cuối cùng trong danh sách liên kết
void deleteLast(Node *&head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        deleteFirst(head);
        return;
    }
    Node *prev = NULL;
    Node *last = head;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    delete last;
}
void deleteBefore(Node *&head, Node *q) {
    if (head == nullptr || head == q || head->next == nullptr || head->next == q) {
        // Không có phần tử trước phần tử q, hoặc danh sách rỗng, hoặc q là phần tử đầu tiên
        return;
    }
    Node *prev = head;
    Node *current = head->next;
    while (current->next != q) {
        prev = current;
        current = current->next;
    }
    prev->next = q;
    delete current;
}
// Xóa phần tử chỉ định trong danh sách liên kết
void deleteNode(Node *&head, int v) {
    if (head == NULL) {
        return;
    }
    if (head->data == v) {
        deleteFirst(head);
        return;
    }
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL && current->data != v) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        prev->next = current->next;
        delete current;
    }
}

// Xóa toàn bộ danh sách liên kết
void clean(Node *&head) {
    while (head != NULL) {
        deleteFirst(head);
    }
}

// Xóa các phần tử trùng nhau
Node* deleteDuplicates(Node* head){
   Node* ptr = head;
   while(ptr != NULL){
       Node *ptr2 = ptr;
       while(ptr2->next != NULL){
           if(ptr->data == ptr2->next->data){
               Node* n = ptr2->next;
               ptr2->next = ptr2->next->next;
               delete(n);
           }
           else ptr2 = ptr2->next;
       }
       ptr = ptr->next;
   }
   return head;
}

// Tìm phần tử lớn nhất trong danh sách và trả về vị trí của nó
int findMax(Node* head) {
    int max = INT_MIN;
    while (head != nullptr) {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }
    return max;
}
int demSoBangX(Node *head, int x) {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        if (current->data == x) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Đảo ngược danh sách liên kết
Node *reverseLinkedList(Node *head) {
    Node *prev = nullptr;
    Node *current = head;
    while (current != nullptr) {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}


// Độ dài của danh sách liên kết
int lengthLinkedList(Node* head) {
    int count = 0; // Biến đếm số nút
    Node* current = head; // Con trỏ hiện tại trỏ đến đầu danh sách
    while (current != nullptr) {
        count++; // Tăng biến đếm lên 1
        current = current->next; // Di chuyển con trỏ đến nút tiếp theo
    }
    return count; // Trả về độ dài của danh sách
}

// Tăng giá trị của các nút chẵn lên 1
void increaseEven(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data % 2 == 0) { // Nếu giá trị của nút là số chẵn
            current->data++; // Tăng giá trị của nút lên 1
        }
        current = current->next; // Di chuyển đến nút tiếp theo
    }
}

//xoa trung nhau
void xoatrungnhau(Node *head) {
    if (head == NULL || head->next == NULL) {
        return; // Không cần xử lý nếu danh sách rỗng hoặc chỉ có một nút
    }

    Node *current = head;
    while (current->next != NULL) {
        if(current->data == current->next->data) { // So sánh giá trị của các nút
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}
int tongphantudanhsach(Node *head)
{
	if(head==NULL)
	{
		cout<<"DSLK rong : "<<endl;
		return 0;
	}
	int tinhtong=0;
	Node *current =head;
	while (current !=NULL)
	{
		tinhtong +=current->data;
		current=current->next;
	}
	return tinhtong;
}
bool isPrime(int n)
{
	if (n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int demsonguyentotrongdanhsach(Node *head) {
    if (head == nullptr) {
        cout << "DSLK rong" << endl;
        return 0;
    }

    int demprime = 0;
    Node *current = head;
    while (current != nullptr) {
        if (isPrime(current->data)) {
            demprime++;
        }
        current = current->next;
    }
    return demprime;
}
int timPhanTuDuongNhoNhat(Node *head) {
    int minPositive = INT_MAX; // Giả sử giá trị nhỏ nhất là vô cùng lớn
    Node *current = head;
    while (current != nullptr) {
        if (current->data > 0 && current->data < minPositive) {
            minPositive = current->data;
        }
        current = current->next;
    }
    // Kiểm tra nếu không tìm thấy số dương nào trong danh sách
    if (minPositive == INT_MAX) {
        cout << "Khong co so duong trong danh sach" << endl;
        return -1; // Trả về -1 hoặc một giá trị khác để biểu thị không tìm thấy
    }
    return minPositive;
}
// Xóa một nút có giá trị k
void deleteNodeWithValue(Node *&head, int k) {
    if (head == nullptr) {
        // Danh sách rỗng
        return;
    }

    Node *current = head;
    Node *prev = nullptr;

    // Tìm nút có giá trị k và nút trước nó (nếu có)
    while (current != nullptr && current->data != k) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        // Không tìm thấy nút có giá trị k
        cout << "Khong tim thay nut co gia tri " << k << " trong danh sach" << endl;
        return;
    }

    if (prev == nullptr) {
        // Nút có giá trị k là nút đầu tiên trong danh sách
        head = current->next;
    } else {
        // Nút có giá trị k không phải là nút đầu tiên trong danh sách
        prev->next = current->next;
    }

    delete current;
}
void deletePrimeNumbers(Node *&head) {
    Node *current = head;
    while (current != nullptr) {
        if (isPrime(current->data)) {
            Node *temp = current;
            current = current->next;
            deleteNode(head, temp->data);
        } else {
            current = current->next;
        }
    }
}
Node* createLinkedListPrime(Node* head) {
    Node* head2 = nullptr; // Khởi tạo danh sách mới
    Node* current = head;
    while (current != nullptr) {
        if (isPrime(current->data)) { // Kiểm tra số nguyên tố
            addLast(head2, current->data); // Thêm số nguyên tố vào danh sách mới
        }
        current = current->next;
    }
    return head2; // Trả về danh sách mới chỉ chứa số nguyên tố
}
void splitLinkedList(Node* head, Node*& evenHead, Node*& oddHead) {
    Node* current = head;
    Node* evenTail = nullptr; // Đuôi của danh sách chẵn
    Node* oddTail = nullptr;  // Đuôi của danh sách lẻ

    while (current != nullptr) {
        if (current->data % 2 == 0) { // Nếu là số chẵn
            if (evenHead == nullptr) {
                evenHead = current; // Nếu danh sách chẵn rỗng, gán nút hiện tại làm đầu
            } else {
                evenTail->next = current; // Nếu danh sách chẵn không rỗng, nối nút hiện tại vào cuối danh sách
            }
            evenTail = current; // Cập nhật đuôi của danh sách chẵn
        } else { // Nếu là số lẻ
            if (oddHead == nullptr) {
                oddHead = current; // Nếu danh sách lẻ rỗng, gán nút hiện tại làm đầu
            } else {
                oddTail->next = current; // Nếu danh sách lẻ không rỗng, nối nút hiện tại vào cuối danh sách
            }
            oddTail = current; // Cập nhật đuôi của danh sách lẻ
        }
        current = current->next; // Di chuyển tới nút tiếp theo trong danh sách ban đầu
    }

    // Kết thúc danh sách chẵn và danh sách lẻ bằng nullptr
    if (evenTail != nullptr) {
        evenTail->next = nullptr;
    }
    if (oddTail != nullptr) {
        oddTail->next = nullptr;
    }
}

Node* mergeSortedLists(Node* head1, Node* head2) {
    Node* mergedHead = nullptr; // Danh sách kết quả
    Node* tail = nullptr; // Đuôi của danh sách kết quả

    // Trường hợp đặc biệt: Nếu một trong hai danh sách là nullptr, trả về danh sách còn lại
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    // Chọn nút đầu tiên của danh sách kết quả
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    tail = mergedHead; // Cập nhật đuôi của danh sách kết quả

    // Lặp để trộn danh sách
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next; // Cập nhật đuôi của danh sách kết quả
    }

    // Nối phần còn lại của danh sách không rỗng vào danh sách kết quả
    if (head1 != nullptr) {
        tail->next = head1;
    }
    if (head2 != nullptr) {
        tail->next = head2;
    }

    return mergedHead;
}

Node* mergeSortedListsWithoutTail(Node* head1, Node* head2) {
    Node* mergedHead = nullptr; 
    Node* current = nullptr; 

    // Chọn nút đầu tiên của danh sách kết quả
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    current = mergedHead; 

    // Lặp để trộn danh sách
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next; 
    }

    // Nối phần còn lại của danh sách không rỗng vào danh sách kết quả
    if (head1 != nullptr) {
        current->next = head1;
    }
    if (head2 != nullptr) {
        current->next = head2;
    }

    return mergedHead;
}
// Hàm trộn danh sách (merge) với thứ tự giảm dần
Node* mergeSortedListsWithDescendingOrder(Node* head1, Node* head2) {
    Node* mergedHead = nullptr; 
    Node* tail = nullptr; 

    // Chọn nút đầu tiên của danh sách kết quả
    if (head1->data >= head2->data) { // Đổi dấu so sánh
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    tail = mergedHead; 

    // Lặp để trộn danh sách
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data >= head2->data) { // Đổi dấu so sánh
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next; 
    }

    // Nối phần còn lại của danh sách không rỗng vào danh sách kết quả
    if (head1 != nullptr) {
        tail->next = head1;
    }
    if (head2 != nullptr) {
        tail->next = head2;
    }

    // Đảo ngược danh sách để có thứ tự giảm dần
    mergedHead = reverseLinkedList(mergedHead);

    return mergedHead;
}
// Chỉ giữ lại một giá trị trong số các giá trị giống nhau
void keepOneDuplicate(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return; // Không cần xử lý nếu danh sách rỗng hoặc chỉ có một nút
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) { // So sánh giá trị của các nút
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}
// Hàm kiểm tra xem danh sách đã được sắp xếp tăng dần hay không
bool isSortedAscending(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data > current->next->data) {
            return false; // Nếu có phần tử không theo thứ tự tăng dần, trả về false
        }
        current = current->next;
    }

    return true; // Nếu tất cả các phần tử đều theo thứ tự tăng dần, trả về true
}
// Hàm đảo ngược danh sách
//Node* reverseLinkedList(Node* head) {
//    Node* prev = nullptr;
//    Node* current = head;
//    Node* nextNode = nullptr;
//
//    while (current != nullptr) {
//        nextNode = current->next; // Lưu trữ con trỏ đến nút tiếp theo
//        current->next = prev; // Đảo chiều liên kết của nút hiện tại
//        prev = current; // Di chuyển con trỏ prev đến nút hiện tại
//        current = nextNode; // Di chuyển con trỏ current đến nút tiếp theo
//    }
//
//    return prev; // Trả về con trỏ đến nút đầu tiên của danh sách đã đảo ngược
//}
// Hàm tách danh sách thành hai danh sách riêng biệt: chẵn và lẻ
void splitEvenOdd(Node* head, Node*& evenList, Node*& oddList) {
    Node* current = head;
    Node* evenTail = nullptr;
    Node* oddTail = nullptr;

    while (current != nullptr) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->next = nullptr;

        if (current->data % 2 == 0) { // Nếu số là chẵn
            if (evenList == nullptr) {
                evenList = newNode;
            } else {
                evenTail->next = newNode;
            }
            evenTail = newNode;
        } else { // Nếu số là lẻ
            if (oddList == nullptr) {
                oddList = newNode;
            } else {
                oddTail->next = newNode;
            }
            oddTail = newNode;
        }

        current = current->next;
    }
}

// Hàm sắp xếp danh sách theo thứ tự tăng dần
Node* sortAscending(Node* head) {
    // Kiểm tra danh sách rỗng hoặc chỉ có một phần tử
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Sắp xếp danh sách bằng thuật toán insertion sort
    Node* sortedList = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (sortedList == nullptr || current->data < sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            Node* temp = sortedList;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    return sortedList;
}

// Hàm sắp xếp danh sách theo thứ tự giảm dần
Node* sortDescending(Node* head) {
    // Kiểm tra danh sách rỗng hoặc chỉ có một phần tử
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Sắp xếp danh sách bằng thuật toán insertion sort
    Node* sortedList = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (sortedList == nullptr || current->data > sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            Node* temp = sortedList;
            while (temp->next != nullptr && temp->next->data > current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    return sortedList;
}

// Hàm trộn hai danh sách đã sắp xếp theo thứ tự yêu cầu
Node* mergeSorted2Lists(Node* evenList, Node* oddList) {
    if (evenList == nullptr) {
        return oddList;
    }
    if (oddList == nullptr) {
        return evenList;
    }

    Node* mergedList = evenList;
    Node* current = mergedList;

    // Di chuyển đến cuối danh sách số chẵn
    while (current->next != nullptr) {
        current = current->next;
    }

    // Nối danh sách số lẻ vào sau danh sách số chẵn
    current->next = oddList;

    return mergedList;
}

// Hàm sắp xếp các số chẵn tăng dần, các số lẻ giảm dần, giữ nguyên vị trí của số 0
Node* sortEvenAscendingOddDescending(Node* head) {
    Node* evenList = nullptr;
    Node* oddList = nullptr;

    // Tách danh sách thành hai danh sách riêng biệt: chẵn và lẻ
    splitEvenOdd(head, evenList, oddList);

    // Sắp xếp danh sách số chẵn theo thứ tự tăng dần
    evenList = sortAscending(evenList);

    // Sắp xếp danh sách số lẻ theo thứ tự giảm dần
    oddList = sortDescending(oddList);

    // Trộn hai danh sách đã sắp xếp theo thứ tự yêu cầu
    return mergeSortedLists(evenList, oddList);
}


int main() {
    Node *head;
    init(head);

    // Thêm các phần tử vào danh sách
    addFirst(head, 5);
    addFirst(head, 4);
    addFirst(head, 3);
    addFirst(head, 2);
    addFirst(head, 2);
    addFirst(head, 1);
    addAfter(head, 2, 4);

    // In ra danh sách
    cout << "Danh sach: ";
    output(head);
    cout << endl;

    cout << "Do dai cua danh sach: " << lengthLinkedList(head) << endl;
     //tong cac phan tu danh sach la
    int tonglist= tongphantudanhsach(head);
    cout<<"Tong phan tu trong danh sach la : "<< tonglist <<endl;
    
    // Tìm kiếm một phần tử
    int value = 3;
    int index = searchLinkedList(head, value);
    if (index != -1) {
        cout << "Tim thay " << value << " tai vi tri " << index << endl;
    } else {
        cout << "Khong tim thay " << value << " trong danh sach" << endl;
    }

 int dem_prime=demsonguyentotrongdanhsach(head);
 cout<<"Danh sach tren co : "<<dem_prime << " so nguyen to "<<endl;
      
    // Tăng giá trị của các nút chẵn lên 1 đơn vị
    increaseEven(head);
    cout << "Danh sach sau khi tang chan len 1 don vi: ";
    output(head);
    cout << endl;

    // Xóa một phần tử
    value = 2;
    deleteNode(head, value);
    cout << "Danh sach sau khi xoa phan tu " << value << ": ";
    output(head);
    cout << endl;

    // Đảo ngược danh sách
    Node *reversedHead = reverseLinkedList(head);
    cout << "Danh sach sau khi dao nguoc: ";
    output(reversedHead);
    cout << endl;

    
     // Xóa các phần tử trùng nhau
    xoatrungnhau(head);
    cout << "Danh sach sau khi xoa cac phan tu trung nhau: ";
    output(head);
    cout << endl;
     int x = 2;

    // Đếm và in ra số lần xuất hiện của số bằng x trong danh sách
    int count = demSoBangX(head, x);
    cout << "So lan xuat hien cua so " << x << " trong danh sach: " << count << endl;
  // Tìm và in ra phần tử dương nhỏ nhất trong danh sách
    int minPositive = timPhanTuDuongNhoNhat(head);
    if (minPositive != -1) {
        cout << "Phan tu duong nho nhat trong danh sach: " << minPositive << endl;
    }
 // Xóa phần tử ngay trước phần tử được trỏ bởi con trỏ q
 Node *q = head->next;
    deleteBefore(head, q);
   
   
    int k = 2;
    deleteNodeWithValue(head, k);
    // Xóa toàn bộ danh sách
   // clean(head);
 deletePrimeNumbers(head);
 Node* head2 = createLinkedListPrime(head);
 Node* evenHead = nullptr;
Node* oddHead = nullptr;
splitLinkedList(head, evenHead, oddHead);
//Node* mergedHead = mergeSortedLists(head1, head2);
//Node* mergedHeadDescending = mergeSortedListsWithDescendingOrder(head1, head2);

 keepOneDuplicate(head);

 
 
 if (isSortedAscending(head)) {
    cout << "Danh sach da duoc sap xep tang dan." << endl;
} else {
    cout << "Danh sach chua duoc sap xep tang dan." << endl;
}

//Node  *reversedHead = reverseLinkedList(head);

 Node* sortedList = sortEvenAscendingOddDescending(head);

 
    return 0;
}
//void them_sau_pt (dslk &ds,int vt,int x)
//{
//	node *p=khoi_tao_node(x);
//	for(node *k=ds.phead;k!=NULL;k=k->pNext)
//	{
//		if(k->data==vt)
//		{
//			p->pnext=k->pnext;
//			k->pnext=p;
//			if(k==ds.ptail)
//			{
//				ds.ptail=p;
//				return;
//			}
//		}
//	}
//}
