#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class ClassMeta
{
private:
	string m_className;
	string m_objectName;
public:
	ClassMeta(const char* className, const char* objectName): m_className(className), m_objectName(objectName) {
        cout<<"2"<<endl;
    }
	void printMeta()
	{
		cout << m_className << " [" << m_objectName << "]" << endl;
	}
};

#define DEFINE_CLASS(c,n) c n(#c,#n)     /* 第一个#是预处理指令，第二三个#作用是将标记转换为字符串*/
class NodeClass : public ClassMeta
{
public:
	NodeClass(const char* className, const char* objectName) : ClassMeta(className, objectName) {
        cout<<"1"<<endl;
    }
};

/* 改进*/
#define Print(n) n.print(#n)
class Complex
{
private:
	double real;
    double imag;
public:
	Complex(double r, double i):real(r), imag(i) {}
	void print(string name)
	{
        if ( !real && !imag)
            cout << name << " = " << "0" << endl;
        else if(real && imag) {
            if (imag > 0) {
		        cout << name << " = " << real << "+" << imag << "i" << endl;
            } else {
		        cout << name << " = " << real << imag << "i" << endl;
            }
        }
        else if(real)
            cout << name << " = " << real <<endl;
        else
            cout << name << " = " << imag << "i" <<endl;
	}
};


int main()
{
    DEFINE_CLASS(NodeClass,node1);
	DEFINE_CLASS(NodeClass,node2);
	node1.printMeta();
    printf("fengexian\n");
	NodeClass *pNode = &node2;
	pNode->printMeta();
    
    int r,i;
    while(cin >> r >> i) {
        Complex num(r, i);
        Print(num);
    }
}