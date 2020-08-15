#include<stdio.h>
int main()
{
    double num;
    while(scanf("%lf", &num) != EOF) {
        printf("%d",(int)(num + 0.5));
    }
}