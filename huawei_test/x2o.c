#include<stdio.h>

int main()
{
    int num;
    while(scanf("%x", &num) != EOF) {
        printf("%o\n",num);
    }
}