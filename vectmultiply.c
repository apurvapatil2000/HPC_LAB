%%cu
#include<stdio.h>
__global__ void vectmultiply(int *x,int *y,int *z){
	int index=blockIdx.x;
  z[index]=x[index]* y[index];
  printf("%d,%d,%d",x[index],y[index],z[index]);
}
int main(){

	int n=2,res=0;
	int a[2]={3,4};
	int b[2]={7,4};
	int c[n];
	int *x,*y,*z;
	int i;
	cudaMalloc((void**)&x,n*sizeof(int));
	cudaMalloc((void**)&y,n*sizeof(int));
	cudaMalloc((void**)&z,n*sizeof(int));
	cudaMemcpy(x,a,n*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(y,b,n*sizeof(int),cudaMemcpyHostToDevice);
    vectmultiply<<<n,1>>>(x,y,z);
    cudaMemcpy(c,z,n*sizeof(int),cudaMemcpyDeviceToHost);
    printf("\nDot product of two vectors:");
    for(i=0;i<n;i++){
    	res=res+c[i];
    }
    printf(" %d  ",res);
    cudaFree(x);
    cudaFree(y);
    cudaFree(z);
    return 0;
}
