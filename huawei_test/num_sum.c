#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 求输入字符 12 3 31 2 -1 -12 中f负数的个数和正数的均值
int main()
{
	char str1[100],stmp[10];
	int cnt = 0,i = 0,length,nums[100];
	double tmp,sum = 0;
	while(1){
        i = 0;sum = 0;
        do{
            scanf("%d",&nums[i++]);
        } while(getchar() != '\n');
		length = i;
		for(i=0;i<length;i++){
			if(nums[i]<0){
				cnt++;
				sum = sum + nums[i];
			}
		}
		if(cnt==0){
			printf("%d, %d",cnt,cnt);
		} else {
			printf("%d, %lf",cnt,sum/cnt);
		}
	}
 } 