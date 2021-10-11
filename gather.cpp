#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argv,char *argc[]){
	int rank=0;
	int data=0;
	int partner_rank=0;
	int size=0;
	int arr[5];
	MPI_Init(&argv,&argc);


	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	partner_rank=rank+1;
    MPI_Gather(&partner_rank,1,MPI_INT,&arr,1,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0){
    	cout<<"After gather..."<<"\n";
		for(int i=0;i<4;i++){
			cout<<arr[i]<<" "<<"\n";
		}
	}

    cout<<"\n";
    MPI_Finalize();
    return 0;
}
