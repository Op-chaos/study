#include "fun.h"
int rt_data(int data,int (*tr_fun)())
{
	return ((*tr_fun)(data));
}  
