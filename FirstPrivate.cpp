#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int i;
	int index=0;
	int n;
	cout<<"Vector Space:";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	printf("First vector:");
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	printf("Second vector:");
	for(i=0;i<n;i++){
		cin>>b[i];
	}
   #pragma omp parallel firstprivate(index)
	{
        int thread=omp_get_thread_num();
        //cout<<thread<<"\n";
        while(index<n){
        	if(index==thread-1){
        		c[index]=a[index]+b[index];
        		break;
        	}
        	index++;
        }

	}
	cout<<"Due to firstprivate:"<<index<<"\n";
	cout<<"output vector:"<<"\n";
	cout<<"a[i]"<<" "<<"b[i]"<<" "<<"c[i]"<<"\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<"    "<<b[i]<<"    "<<c[i]<<"  "<<"\n";
	}
    return 0;
}