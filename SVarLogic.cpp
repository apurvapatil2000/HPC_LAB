#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int n,scalar;
	int i;
	cout<<"Vector Space:"<<"\n";
	cin>>n;
	int a[n+1];
	int c[n+1];
	cout<<"vector"<<"\n";

	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Scalar to add"<<"\n";
	cin>>scalar;
    #pragma omp parallel
	{
 	int id, i, Nthrds, istart, iend;
 	id = omp_get_thread_num();
 	Nthrds = omp_get_num_threads();
 	istart = id*n/Nthrds;
 	iend = (id+1)*n/Nthrds;
 	if(id == Nthrds-1) iend = n;
 		for(i = istart; i<iend; i++) {c[i] = scalar+a[i];}
}

 	cout<<"Output vector"<<"\n";
 	for(i=0;i<n;i++){
 		cout<<"a[i]+scalar="<<a[i]<<"+"<<scalar<<"="<<c[i]<<" "<<"\n";
 	}
  return 0;	
}