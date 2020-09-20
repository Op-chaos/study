/*hello.c 2.1*/
#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int *pin;
    double *dpin;
	pin=mxGetPr(prhs[0]);
    dpin=mxGetPr(prhs[0]);
    
    mexPrintf("pin[1]:%d\n",pin[1]);
    mexPrintf("pin[1]:%f\n",dpin[1]);
}


