#include<stdio.h>
int main()
{
    int num,i,j,diff1_start=2;
    int tmp1 = 1, tmp2 = 1,tmp;
    while(scanf("%d",&num)){
        for(i = 0; i < num; i++){
            tmp1 = tmp1 + i;
            for(j = 0, tmp2 = tmp1; j< num-i;j++) {
                printf("%d ",tmp2);
                tmp2 = tmp2 + diff1_start + j;
            }
            printf("\n");

            diff1_start++;
        }
    }
}
