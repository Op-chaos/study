#include<stdio.h>

int main()
{
    int i,j,n,tem,num[1000];
    while(scanf("%d", &n) != EOF) {
        for(i=0;i<n;i++) {
            scanf("%d",&tem);
            num[i] = tem;
        }
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++) {
                if(num[i]>num[j]){
                    tem = num[i];
                    num[i] = num[j];
                    num[j] = tem;
                }
            }
        }
        printf("%d\n",num[0]);
        for(i=1;i<n;i++) {
            if(num[i] != num[i-1]){
                printf("%d\n",num[i]);
            }
        }
    }
    return 1;
}