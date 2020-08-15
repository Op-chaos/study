#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream f1out("some1.dat", ios::out | ios::binary);
	int x=120;
	f1out.write((const char *)(&x), sizeof(int) );
	f1out.close();
	ifstream fin("some1.dat", ios::in | ios::binary);
	int y;
	fin.read((char *) & y, sizeof(int));
	fin.close();
	cout<< y << endl;
	return 0;
} 
