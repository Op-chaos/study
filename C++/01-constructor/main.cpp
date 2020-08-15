#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class CSample{
	private:
		int x;
	public:
		CSample() {cout << "this is first one" << endl; }
		CSample(int n){
				x = n;
				cout<<"this is scende one"<<endl;
		}
};

int main() {
	CSample array1[2];
	CSample array2[2] = {2,3};
	CSample array3[2] = {4};
	
	return 0;
}



