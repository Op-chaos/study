//show.c 1.0
#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *inData;
    int M,N;
    int i,j;

    inData=mxGetPr(prhs[0]);
    M=mxGetM(prhs[0]);
    N=mxGetN(prhs[0]);
    // ��ӡ�������
    printf("�У�%d, �У�%d\n", M, N);
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++)
            printf("%lf ",inData[i*N+j]);
        printf("\n");
    }
}



