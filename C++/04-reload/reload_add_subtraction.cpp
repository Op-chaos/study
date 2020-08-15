#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define PrintComplex(n) (n).Print(#n)

class Complex{
private:
    double real, imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){}
    friend ostream & operator<<(ostream & os, const Complex & c);
    friend istream & operator>>(istream & is, Complex & c);
    Complex operator+(Complex & c){               // 使用成员函数方法重载加法
        real +=c.real;
        imag +=c.imag;
        return * this;
    }
    friend Complex operator-(Complex &c1, Complex &c2);   // 返回类型为 Complex
    void print();
    void Print(string name);

    operator double(){return real;}     // 重载强制类型转换符

    Complex & operator++();                    // ++C 形式
    Complex operator++(int);                   // C++ 形式
    friend Complex & operator--(Complex & c);      // --C
    friend Complex operator--(Complex & , int);
};

Complex &Complex::operator++(){
    real += (real/(real+imag));
    imag += (imag/(real+imag));
    return *this;
}

Complex Complex::operator++(int){
    Complex c(*this);
    c.real = real;
    c.imag = imag;
    real += (real/(real+imag));
    imag += (imag/(real+imag));
    return c;
}

Complex & operator--(Complex & c){
    c.real -= (c.real/(c.real+c.imag));
    c.imag -= (c.imag/(c.real+c.imag));
    return c;
}

Complex operator--(Complex & c, int){
    Complex tmp(c);
    tmp.real = c.real;
    tmp.imag = c.imag;
    c.imag -= (c.imag/(c.imag+c.real));
    c.real -= (c.real/(c.imag+c.real));
    return tmp;
}

Complex operator-(Complex &c1, Complex &c2){     // 使用全局函数类型重载减法
    Complex c(c1);
    c.real = c1.real - c2.real;
    c.imag = c2.imag - c1.imag;
    return c;
}

void Complex::print(){
    if(imag>0)
        cout<<real<<"+"<<imag<<"i"<<endl;
    else if(imag<0)
        cout<<real<<imag<<"i"<<endl;
    else
        cout<<real<<endl;
}

void Complex::Print(string name) {
    if(imag>0)
        cout<<name<<" = "<<real<<"+"<<imag<<"i"<<endl;
    else if(imag<0) {
        cout<<name<<" = "<<real<<imag<<"i"<<endl;
    }
    else {
        cout<<name<<" = "<<real<<endl;
    }
}

ostream & operator<<(ostream &os,const Complex &c){
    os<< c.real << "+" << c.imag << "i";       //以指定格式输出
    return os;                          // os 就是cout
}
istream & operator>>(istream & is, Complex &c){
    string s;
    is>>s;                                     // is 就是cin
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);            // 分离出代表实部的字符串
    c.real = atof(sTmp.c_str());               // atof库函数能将const char*指针指向的内容转换成float类型
    sTmp = s.substr(pos+1,s.length()-pos-2);   // 分离出代表虚部的字符串
    c.imag = atof(sTmp.c_str());
    return is;
}



int main()
{
    Complex c1={1,2}, c2={2,3};
    Complex c3, c4;
    c3 = c1-c2;
    c1.print();
    c3.print();
    c4 = c1+c2;
    cout<<"c4=";
    c4.print();

    cout<<c2<<endl;

    cout<<(double)c2<<endl;     // 使用重载后的double
    double n = 2+c2;            // 在类中如果有类型转换的重载，编译器会自动调用

    c4++;
    cout<<"c4++ = ";
    c4.print();
    cout<<"--c4 = ";
    --c4;
    c4.print();
    PrintComplex(c4);
}
