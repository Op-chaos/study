//reverse.c 1.0

#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *inData;
    double *outData1, *outData2;
    int M,N;
    int i,j;
    //�쳣����
    if(nrhs!=1)
        mexErrMsgTxt("USAGE: [b,c]=reverse(a)\n");
    if(nlhs!=2)
        mexErrMsgTxt("USAGE: [b,c]=reverse(a)\n");
    if(!mxIsDouble(prhs[0]))
        mexErrMsgTxt("the Input Matrix must be double!\n");
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
    // ÿһ�з�ת
    plhs[0]=mxCreateDoubleMatrix(M,N,mxREAL);
    outData1=mxGetPr(plhs[0]);
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            outData1[j*M+i]=inData[(N-1-j)*M+i];
    // ����ת
    plhs[1] = mxCreateDoubleMatrix(N,M,mxREAL);
    outData2 = mxGetPr(plhs[1]);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            outData2[i*M+j]=inData[i*M+j];
}



