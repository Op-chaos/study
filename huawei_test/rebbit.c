#include<stdio.h>
//小兔子增长
int main()
{
    int yue,i;
    while(scanf("%d",&yue)){
        int sanyue=0,eryue=0,yiyue=1,tmp;
        for(i=1; i<yue; i++){
            tmp = sanyue;
            sanyue = sanyue + eryue;
            eryue = yiyue;
            yiyue = sanyue;
            printf("%d %d %d\n",yiyue, eryue, sanyue);
        }
        printf("%d \n",yiyue + eryue + sanyue);
    }
}