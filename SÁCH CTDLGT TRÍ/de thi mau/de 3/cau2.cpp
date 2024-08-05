/*Làm thế nào chuyển các phần tử trong stack S1 sang stack S2 với yêu cầu sau 
-thứ tự các phần tử S2 giống như S1
-Không được dùng thêm stack phụ,chỉ được dùng thêm vài biến phụ
*/
#include <iostream>
#include <stack>

using namespace std;

void transferStack(stack<int> &S1, stack<int> &S2)
{
    int count = 0;  // Biến đếm số phần tử trong stack S1

    // Đếm số phần tử trong stack S1
    while (!S1.empty()) {
        S2.push(S1.top());
        S1.pop();
        count++;
    }

    // Đưa các phần tử từ S2 về lại S1
    for (int i = 0; i < count; i++) {
        S1.push(S2.top());
        S2.pop();
    }

    // Đưa các phần tử từ S1 sang S2 lần cuối
    for (int i = 0; i < count; i++) {
        S2.push(S1.top());
        S1.pop();
    }
}

int main()
{
    stack<int> S1;
    stack<int> S2;

    // Đẩy các phần tử vào stack S1
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);

    cout << "Stack S1 ban dau: ";
    stack<int> tempS1 = S1;
    while (!tempS1.empty()) {
        cout << tempS1.top() << " ";
        tempS1.pop();
    }
    cout << endl;

    // Chuyển các phần tử từ S1 sang S2
    transferStack(S1, S2);

    cout << "Stack S2 sau khi chuyen: ";
    while (!S2.empty()) {
        cout << S2.top() << " ";
        S2.pop();
    }
    cout << endl;

    return 0;
}
