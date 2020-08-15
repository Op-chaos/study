#include <iostream>
#include <string.h>

using namespace std;

class CArray{
private:
    int size;   //数组元素的个数
    int *ptr;   // 指向动态分配的数组
public:
    CArray(int s=0);        // s代表数组元素个数，构造函数
    CArray(CArray & a);     // 赋值构造函数
    ~CArray();              // 析构函数
    void push_back(int i);  // 具体的需求函数
    CArray & operator=(const CArray & a);     // 赋值号重载函数，用于数组对象间的赋值
    int length()            // 返回数组元素的个数
    {
        return size;
    }
    int & operator[](int i)          //重载[]
    {// 用于支持根据下表访问数组元素,如 n = a[1]; a[2] = 4;
        return ptr[i];
    }
};

CArray::CArray(int s):size(s)     // 构造函数
{
    if(s == 0) {
        ptr = NULL;
    }
    else
        ptr = new int[s];        // 动态分配内存空间
}

CArray::CArray(CArray &a){       // 复制构造函数
    if(!a.ptr){
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
}

CArray::~CArray(){
    if(ptr) delete []ptr;
}

CArray & CArray::operator=(const CArray &a){
    if(ptr == a.ptr)    // 防止a=a赋值的错误
        return *this;
    if(a.ptr == NULL){
        if(ptr) delete [] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if(size < a.size){
        if(ptr)
            delete [] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof (int)*a.size);
    size=a.size;
    return *this;
}

void CArray::push_back(int v)
{// 在数组尾部增加元素
    if(ptr){
        int *tmpPtr = new int[size + 1];   //重新分配内存空间
        memcpy(tmpPtr,ptr,sizeof (int)*size); //copy原数据
        delete []ptr;
        ptr = tmpPtr;
    }
    else {
        ptr = new int[1];
    }
    ptr[size++]=v;  // 加入新的数组元素
}

int main()
{
    CArray a;
    for(int i = 0; i<5; i++)
        a.push_back(i);     // 动态分配内存空间来存放数组变量
    CArray a2, a3;
    a2 = a;                 // 赋值号需要重构
    for(int i=0; i<a.length(); ++i)
        cout<<a2[i]<<" ";   // 对象[] 是重构了[]
    cout<<endl;
    a[3] = 100;
    CArray a4(a);
    for(int i=0; i<a4.length(); i++)
        cout<<a4[i]<<" ";
    return 0;
}
