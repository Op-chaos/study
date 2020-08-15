#include<iostream>
#include<vector>

using namespace std;

template<class T>
void PrintVector(T s, T e)
{
    for(;s != e; ++s)
        cout << *s << " ";
    cout << endl;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    cout << "1) " << v.end() - v.begin() << endl;

    cout << "2) "; PrintVector(v.begin(), v.end());

    v.insert(v.begin() + 2, 100);
    cout << "3) "; PrintVector(v.begin(), v.end());

    v.erase(v.begin() + 2);
    cout << "4) "; PrintVector(v.begin(), v.end());

    vector<int> v2(4, 100); 
    vector<int>::iterator i;
    cout << "5) "; PrintVector(v2.begin(), v2.end());
    v2.insert(v2.begin(), v.begin() + 1, v.begin() +3);   // 将v的一段插入
    cout << "5) "; PrintVector(v2.begin(), v2.end());

    vector<vector<int> > v4(3);
    for(int i = 0; i < v4.size(); i++) {
        for(int j = 0; j < 4; ++j){
            v4[i].push_back(j);
        }
    }
    for(int i = 0; i < v4.size(); i++) {
        for(int j = 0; j < v4[i].size(); ++j){
            cout << v4[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;

}