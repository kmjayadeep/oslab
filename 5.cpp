/*
Exp no 5
Program to implement chat program using sockets
S1330-R-Jayadeep
01-08-2016
*/

#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<cstring>

using namespace std;

bool isServer = true;

int main(int argc,char* argv[]){
      if(argc<2||string(argv[1])=="client"){
            isServer = false;
      }
      struct sockaddr_in servAddr,cliAddr;
      struct hostent *server;
      bzero((char*) &servAddr,sizeof(servAddr));
      servAddr.sin_family = AF_INET;
      servAddr.sin_port = htons(5693);
      int sockFd,newSockFd,n;
      socklen_t cliLen;
      char buffer[256];
      sockFd = socket(AF_INET, SOCK_STREAM,0);
      if(sockFd<0){
            cout<<"Unable to create socket"<<endl;
            return 0;
      }
      if(isServer){
            servAddr.sin_addr.s_addr = INADDR_ANY;
            if(bind(sockFd,(struct sockaddr *) &servAddr,sizeof(servAddr))<0){
                  cout<<"Error on binding";
                  return 0;
            }
            listen(sockFd,5);
            cliLen = sizeof(cliAddr);
            newSockFd = accept(sockFd, (struct sockaddr*) &cliAddr,&cliLen);
            if(newSockFd<0){
                  cout<<"Error on Accept";
                  return 0;
            }
            while(true){
                  bzero(buffer,256);
                  n = read(newSockFd,buffer,255);
                  if(n<0)
                        cout<<"Error reading";
                  if(n>0)
                        cout<<buffer<<endl;
            }
            return 0;
      }

      if(connect(sockFd,(struct sockaddr *) &servAddr,sizeof(servAddr))<0){
            cout<<"Error on connecting";
            return 0;
      }
      bzero(buffer,256);
      while(true){
            cin>>buffer;
            n = write(sockFd,buffer,strlen(buffer));
            if(n<0)
                  cout<<"Error writing"<<endl;
      }
      return 0;
}


/****************SAMPLE OUTPUT****************

Program 1:

hello world
program works
12345

Program 2:

hello world
program works
12345




Result
--------
Program is executed and output is verified

**********************************************/
