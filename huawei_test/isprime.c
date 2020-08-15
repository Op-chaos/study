#include<stdio.h>

int main()
{
    int num, i;
    while(scanf("%d", &num) != EOF) {
        for(i = 2; i <= num; i++) {
            while(num % i == 0) {
                num = num / i;
                printf("%d ",i);
            }
        }
    }

    return 0;
}