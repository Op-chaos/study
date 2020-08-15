#include<stdio.h>

int out[1000],cnt=0;
int Swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int full_sort(int n,int num[],int begin, int end)
{
    int i,tmp = 0;
    if(begin >= end){  // 递归调换数据
        for(i=0;i<n;i++){
            printf("%d ",num[i]);
            tmp = tmp*10 + num[i];
        }
        out[cnt] = tmp;
        cnt++;
    } else {
        // 第1次进入begin = 0，i循环 n 次
        // 第2次进入begin = 1，i循环 n - 1 次
        for(i = begin; i<end; i++){ 
            if (i != begin){
                Swap(&num[i],&num[begin]);
            }
            full_sort(n,num,begin+1,end);
            if (i != begin){
                Swap(&num[i],&num[begin]);
            }
        }
    }
    return 0;
}


int main()
{
    int n,num[10];
    int i, begin = 0;
    while(scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        full_sort(n, num, begin, n);

        printf("%d",cnt);
        for(i=0;i<cnt;i++){
            printf("%d ",out[i]);
        }
    }
    return 0;
}