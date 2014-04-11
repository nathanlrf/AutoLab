#include "mex.h"

double mexSimpleDemo(double *y,double a,double b);

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    double *y;
    double m,n;
    //get the value of input 
    m=mxGetScalar(prhs[0]);
    n=mxGetScalar(prhs[1]);
    //generate a pointer to the result
    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    y=mxGetPr(plhs[0]);
    //call the function in C language
    mexSimpleDemo(y,m,n);
}

double mexSimpleDemo(double *y,double a,double b)
{
    return *y=(a>b)?a:b;
}
