/*hello.c 2.0*/
#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int in;
    in = *(mxGetPr(prhs[0]));
	if(in==1)
		mexPrintf("hello,world!\n");
	else
		mexPrintf("´ó¼ÒºÃ£¡\n");
    
    int *pin;
    double *dpin;
	pin=mxGetPr(prhs[0]);
    dpin=mxGetPr(prhs[0]);
    printf("********\n");
    printf("pin:%d\n",pin);
    printf("dpin:%f\n",dpin);
}
