#include<stdio.h>
int main()
{
	int i;
	scanf("%d",&i);
	if (i > 1) {
printf("进入goto");	
goto ceshi;}
printf("跳过goto");
ceshi:
printf("goto的内容");
}
