#include<iostream>
using namespace std;
int main()
{
	int x,y,c;
	cout<<"请输入：1，正常输入输出；other，流操作";
	cin>>c;
	if (c == 1) {
		cout<<"输入x，y：";
		cin>>x>>y;
		if(y == 0){
			cerr << "error" << endl;
		} else{
			cout << x/y << endl;
		}
	} else {
		cout<<"输入x，y：";
		cin>>x>>y;
		freopen("test.txt","w",stdout);      /* 这句之后的 流输出都会写入文件 test.txt*/
		if(y == 0){
			cerr << "error" << endl;
		} else{
			freopen("c.txt","r",stdin);
			cin >> x >> y;                  /* 这句之后的 流输入都会在文件 c.txt 中读取*/
			cout << x << "/" << y << " = " << x/y << endl;
		}

	}
	cout << "结束" << endl;  
	string s;
	cin >> s;
	cout << s << endl;
	freopen("/dev/tty","r",stdin);    /* 恢复句柄， 把输入流还给输入设备*/
    freopen("/dev/tty","w",stdout);   /* 恢复输出句柄，把输出还给屏幕 */
    printf("succeed!/n");

	string name;
    string city;
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Enter the city you live in: ";
    getline(cin, city);
    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;

	return 0;
 } 
