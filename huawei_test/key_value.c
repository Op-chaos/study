#include<stdio.h>
int main()
{
    int a[1000] = {0};
    int n,i, key, value;
    while(scanf("%d",&n) != EOF) {
        for(i=0; i < n; i++) {
            scanf("%d %d",&key,&value);
            a[key] = a[key] + value;
        }
        for (i=0; i < 1000; i++) {
            if (a[i] > 0) {
                printf("%d %d\n",i,a[i]);
            }
        }
    }
}