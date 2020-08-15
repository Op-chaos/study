#include <iostream>
#include <algorithm>

using namespace std;

class A 
{
private:
    int num;
public:
    A(int n):num(n) {}
    bool operator < (const A & aa)const {
        cout << num << " < " << aa.num << " ?" << endl;   // 可认为A定义的两个对象，互相不小于对方
        return false;
    }
    bool operator == (const A & aa)const {
        cout << num << " == " << aa.num << " ?" << endl;   // 可认为A定义的两个对象，互相不小于对方
        return true;
    }
};

int main()
{
    A a[] = {A(0),A(1),A(2),A(3),A(4)};

    cout << binary_search(a, a + 4, A(9));   // 用对象a中重载的小于比较小于，用默认的大于比较两个值大小
    return 0;
}