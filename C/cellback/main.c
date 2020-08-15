#include "fun.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct gfun{
	int (*pfun)(int);	
}gfun;

int myfun(int data)
{
	printf("get data:%d\n",data);
	return (data*2);
}
 
int main(int argc,char *argv[])
{
	int ret;
	gfun gf;
	gf.pfun = myfun;
	ret = rt_data(100,gf.pfun);
	printf("return data:%d\n",ret);
	return 0;
}
