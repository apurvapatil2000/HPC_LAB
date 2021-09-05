#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int n,scalar;
	int i;
	cout<<"Vector Space:"<<"\n";
	cin>>n;
	int a[n+1];
	int index=0;
	int c[n+1];
	cout<<"vector"<<"\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Scalar to add"<<"\n";
	cin>>scalar;
    #pragma omp parallel firstprivate(index)
	{
        int thread=omp_get_thread_num();
        //cout<<thread<<"\n";
        while(index<n){
        	if(index==thread-1){
        		c[index]=a[index]+scalar;
        		break;
        	}
        	index++;
        }

	}

 	cout<<"Output vector"<<"\n";
 	for(i=0;i<n;i++){
 		cout<<"a[i]+scalar="<<a[i]<<"+"<<scalar<<"="<<c[i]<<" "<<"\n";
 	}
  return 0;	
}