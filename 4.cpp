/*
Exp no 4
Program to implement chat using message queue
S1330-R-jayadeep
23-07-2016
*/

#include<iostream>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>

struct msgBuff{
      long mtype;
      char mBuff[20];
};

using namespace std;

int main(){
      int msgId  = msgget(1999,IPC_CREAT|0666);
      if(msgId==-1){
            cout<<"Unable to create Queue"<<endl;
            return 0;
      }
      struct msgBuff m1,m2;

      pid_t pid = fork();


      if(pid==0){
            while(1){
                  cin>>m1.mBuff;
                  m1.mtype = 11;
                  msgsnd(msgId,&m1,sizeof(m1.mBuff),0);
            }
      }else{
            while(1){
                  msgrcv(msgId,&m2,sizeof(m1.mBuff),10,0);
                  cout<<m2.mBuff<<endl;
            }
      }

      return 0;
}

/****************SAMPLE OUTPUT****************

Program 1:

hello
hai
hello world
good program


Program 2:

hello
hai
hello world
good program

**********************************************/



Result
--------
Program is executed and output is verified
