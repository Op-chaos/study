#include <iostream>
#include <string.h>
#include <unistd.h>

#define VarName(x) #x

using namespace std;

class String {
private:
    char *str;
    char *name;
public:
    String():str(new char[1]) { str[0] = 0;}

    String(String &s)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    
    void print_str()
    {
        cout<<str<<endl;
    }

    String & operator = (const char *s)
    {
        delete [] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        cout<<"调用赋值重构函数1"<<endl;
        return *this;
    }

    String & operator = (const String &s)
    {
        if (this == &s) {
            return *this;
        }
        delete [] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
        return *this;
    }

    ~String() {
        cout<<str<<"调用析构函数"<<&str<<endl;
        printf("str %p\n", str);
        delete [] str;
    }
};

int main()
{
    String s1, s2;
    s1 = "string1";
    s2 = "string2";
    s1.print_str();
    s2.print_str();
    s1 = s2;
    s1.print_str();
    s2.print_str();

    String s3(s1);
    // cout<<"1"<<endl;
    // s3.print_str();

    // _name(s1);
    usleep(100000);
    // cout<<"s1="<<s1.get_str<< ";s2="<<s2.get_str<<endl;
}
