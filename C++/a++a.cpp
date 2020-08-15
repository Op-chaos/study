#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	a = 1;
	b = a++;
	cout<<"a = "<<a<<"\nb = "<<b<<endl;
	c = ++a;
	cout<<"a = "<<a<<"\nc = "<<c<<endl;
	return 0;
 } 
