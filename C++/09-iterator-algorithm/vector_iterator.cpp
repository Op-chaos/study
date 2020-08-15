#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v;    //一个用于存放int类型的数组，声明时为空
    v.push_back(1); 
    v.push_back(2);
    v.push_back(4);
    
    vector<int>::const_iterator i;  /* 相当于创建了一个可以指向V的指针变量， 类似int * */
    for(i = v.begin(); i != v.end(); ++i)
        cout << *i << ",";
    cout << endl;

    vector<int>::reverse_iterator r;  /* 反向迭代器 */
    for(r = v.rbegin(); r != v.rend();++r)   // ++操作反向移动
        cout << *r << ",";
    cout << endl;

    vector<int>::iterator g;  /* 相当于创建了一个可以指向V的指针变量， 类似int * */
    for(g = v.begin(); g != v.end(); ++g)
        *g = 40;          

    for(i = v.begin(); i != v.end(); ++i)
        cout << *i << ",";
    cout << endl;
    for(i = v.begin(); i < v.end(); ++i)
        cout << *i << ",";
    cout << endl;
}
