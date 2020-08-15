#include<iostream>

using namespace std;

template <class type1, class type2>
void swap(type1 & x, type2 & y)
{
    type2 z = (type2) x;
    x = (type1) y;
    y = z;
}

int main()
{
    int x;
    double y;
    x = 10;
    y = 20.5;
    cout << "x = " << x << ", y = " << y << endl;
    swap(x,y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}