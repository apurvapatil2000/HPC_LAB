#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc,char *argv[]){
    int limit=10;
    int processid=0,next,prev;
    int numberofprocess=0;
    MPI_Request request,request2;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&processid);
    MPI_Comm_size(MPI_COMM_WORLD,&numberofprocess);
    int data=0;
    while(data<=limit){
    	next=(processid+1)%numberofprocess;
    	prev=(processid)%numberofprocess;


    	MPI_Isend(&data,1,MPI_INT,prev,0,MPI_COMM_WORLD,&request);
    	cout<<"Process_1: "<<next<<"  "<<"data: "<<data<<"\n";
    	//MPI_Wait(&request,&status);

    	MPI_Irecv(&data,1,MPI_INT,next,0,MPI_COMM_WORLD,&request2);
    	cout<<"Process_2: "<<next<<"  "<<"data: "<<data<<"\n"<<"\n";
    	//MPI_Wait(&request2,&status);
    	data++;
    }
   MPI_Finalize();
   return 0;
}
