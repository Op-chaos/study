#include<iostream>

using namespace std;

template<class type1>  /* 一个数变成十个数*/
class array
{
public:
    type1 num;
    type1 arr[100];
    array(type1 n):num(n) {
        int i = 0;
        for(i = 0;i<100 && i < n; i++) {
            arr[i] = n;
        }
    }
    void print() {
        int i = 0;
        for(i = 0;i<100 && i < num; i++) {
            cout << arr[i] << " ";
        }
    }

};

int main()
{
    array<int> a(10);
    array<double> b(5.5);

    a.print();
    b.print();

    return 0;
}