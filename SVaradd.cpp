#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int n,scalar;
	int i;
	cout<<"Vector Space:"<<"\n";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	cout<<"vector"<<"\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Scalar to add"<<"\n";
	cin>>scalar;
    #pragma omp parallel
	{
		#pragma omp for
 		for(i=0; i<n; i++) 
 		{c[i]=scalar+a[i];}
 	}

 	cout<<"Output vector"<<"\n";
 	for(i=0;i<n;i++){
 		cout<<"a[i]+scalar="<<a[i]<<"+"<<scalar<<"="<<c[i]<<" "<<"\n";
 	}
  return 0;	
}