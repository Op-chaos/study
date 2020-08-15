#include<iostream>
#include<set>

using namespace std;

int main() 
{
    typedef set<int>::iterator IT;
    int a[] = {1,2,3,4,6};
    set<int> st(a, a+5);       // st = 1 2 3 4 6
    pair<IT, bool> result;
    result = st.insert(5);     // st 变成 1 2 3 4 5 6
    if(result.second) {
        cout << * result.first << " inserted " << endl;
    }
    if(st.insert(5).second) {
        cout << * result.first << endl;
    } else {
        cout << *result.first << " already exists " << endl;
    }
    pair<IT, IT> bounds = st.equal_range(4);
    cout << *bounds.first << " , " << *bounds.second << endl;
    return 0;
}