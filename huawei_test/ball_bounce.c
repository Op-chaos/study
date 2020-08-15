#include<stdio.h>
int main()
{
    int i;
    double sum = 0 ,start;
    while(scanf("%lf",&start)){
        sum = start;
        for(i=1;i<5;i++){
            sum = sum + start;
            start = start / 2;
        }
        start = start / 2;
        printf("%lf\n%lf\n", sum,start);
    }
}