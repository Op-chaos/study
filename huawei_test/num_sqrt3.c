// 不使用库函数，求立方根
#include<stdio.h>
int main()
{
    int n;
    double x,right,left;
    double yu = 0.000000001,ch=1;

    // while(scanf("%d",&n) != EOF){
        scanf("%d",&n);
        right = n;
        left = 0;
        x = n/2;
        for(ch=1;ch>yu;){
            ch = x*x*x - n;
            if (ch>0){
                right = x;
            } else {
                left = x;
                ch = -ch;
            }
        }
        printf("%lf",x);
    // }
    return 0;
}