/*
Exp no : 10
FTP Using TCP
S1330-R-Jayadeep
03/10/2016
*/

#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<unistd.h>
#include<fstream>

using namespace std;

#define port 9012

int main(int argc,char* argv[]){
    int tcpSocket,nBytes;
    struct sockaddr_in addr,cliAddr;
    bool client = true;
    bzero((char*) &addr,sizeof(addr));
    if(argc==2)
        client = false;
    socklen_t addr_size,cliLen;
    tcpSocket = socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    int newSockFd;
    if(!client){
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        bind(tcpSocket,(struct sockaddr*) &addr,sizeof(addr));
        cout<<"waiting for File"<<endl;
        listen(tcpSocket,5);
        addr_size = sizeof(addr);
        newSockFd = accept(tcpSocket,(struct sockaddr*) &cliAddr,&cliLen);
        if(newSockFd<0){
            cout<<"Error on accept";
        }
    }else{
        if(connect(tcpSocket,(struct sockaddr*)&addr,sizeof(addr))<0){
            cout<<"Error on connecing";
            return 0;
        }
    }
    while(!client){
        char* buffer;
        int size;
        if(read(newSockFd,&size,sizeof(size))<0){
            cout<<"Error reading";
            break;
        }
        cout<<"Receiving file of size : "<<size<<endl;
        buffer = new char[size];
        if(read(newSockFd,buffer,size)<0){
            cout<<"Error reading";
            break;
        }
        cout<<"File received"<<endl;
        cout<<buffer<<endl;
        cout<<"Enter file name to write : ";
        string file;
        cin>>file;
        ofstream fout(file.c_str());
        if(!fout)
            cout<<"Unable to open file"<<endl;
        fout.write(buffer,size);
        cout<<"Written to "<<file<<endl;
    }
    while(client){
        //client
        char* buffer;
        int size;
        cout<<"Enter file name"<<endl;
        string fileName;
        cin>>fileName;
        ifstream fin(fileName.c_str());
        fin.seekg(0,ios::end);
        size = fin.tellg();
        fin.seekg(0,ios::beg);
        buffer = new char[size];
        fin.read(buffer,size);
        if(write(tcpSocket,&size,sizeof(size))>=0)
            cout<<"File Size : "<<size<<endl;
        else
            cout<<"Unable to send file metadata"<<endl;
        if(write(tcpSocket,buffer,size)>=0)
            cout<<"File Sent"<<endl;
        else
            cout<<"Unable to send file"<<endl;
    }
    return 0;
}

/**********************************OUTPUT***************************

Enter file name
1-fork.c
File Size : 660
File Sent


waiting for File
Receiving file of size : 660
File received

#include<stdio.h>
#include<sys/types.h>

void printDetails(){
    printf("%d : process id is : %d\n",getpid(),getpid());
    printf("%d : parent id is : %d\n",getpid(),getppid());
    printf("%d : real user id is : %d\n",getpid(),getuid());
    printf("%d : effective user id is : %d\n",getpid(),geteuid());
    printf("%d : group id is : %d\n",getpid(),getgid());
    printf("%d : effective group id is : %d\n",getpid(),getegid());
}

int main(){
    pid_t pid = fork();
//    printf("pid is : %d\n",pid);
    if(pid>0){
        printDetails();
        printf("%d : child id is %d\n",getpid(),pid);
    }else{
        printDetails();
        printf("%d : i am child of %d\n",getpid(),getppid());

    }
    return 0;
}


Enter file name to write : out.txt
Written to out.txt


*********************************************************************************************************************************/




Result
--------
Program is executed and output is verified
