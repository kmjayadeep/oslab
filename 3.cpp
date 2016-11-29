/*
Exp No : 3
Program to input, print and multply matrices using shared memory
S1330-R-Jayadeep
20-07-2016
*/

#include<iostream>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;

class matrix{
     public:
     int m,n;
     int mat[10][10];
     void read(){
          cout<<"Enter dimensions : ";
          cin>>m>>n;
          cout<<"Enter matrix : ";
          for(int i=0;i<m;i++)
               for(int j=0;j<n;j++)
                    cin>>mat[i][j];
     }
     void print(){
          cout<<"Result is"<<endl;
          for(int i=0;i<m;i++){
               for(int j=0;j<n;j++)
                    cout<<mat[i][j]<<" ";
               cout<<endl;
          }
     }
     void multiply(matrix& ma,matrix& res){
          res.m = m;
          res.n = ma.n;
          for(int i=0;i<m;i++){
               for(int j=0;j<ma.n;j++){
                    res.mat[i][j]=0;
                    for(int k=0;k<n;k++)
                         res.mat[i][j]+=mat[i][k]*ma.mat[k][j];
               }
          }
     }
};


int main(){
     int shmid;
     shmid  = shmget(IPC_PRIVATE,3*sizeof(matrix),0666|IPC_CREAT);
     if(shmid<0){
          cout<<"Unable to create shared memory"<<endl;
          return 0;
     }
     matrix *m = (matrix*) shmat(shmid,NULL,0);
     pid_t pid = fork();
     if(pid==0){
          m[0].read();
          m[1].read();
          return 0;
     }
     wait(NULL);
     pid = fork();
     if(pid==0){
          m[0].multiply(m[1],m[2]);
          return 0;
     }
     wait(NULL);
     m[2].print();
     return 0;
}

/*********************************OUTPUT***********************************

Enter dimensions : 3 3
Enter matrix : 1 2 3
4 5 6
7 8 9
Enter dimensions : 3 3
Enter matrix : 7 61 2
0 9 7
2 2 3
Result is
13 85 25
40 301 61
67 517 97



Result
--------
Program is executed and output is verified
**************************************************************************/
