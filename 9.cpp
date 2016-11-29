/*
Exp no : 9
SMTP Using UDP
S1330-R-Jayadeep
06/10/2016
*/

#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>

using namespace std;

typedef struct Mail{
    char from[100];
    char to[100];
    char subject[200];
    char body[600];
} Mail;

#define port 16000

int main(int argc,char* argv[]){
    int udpSocket,nBytes;
    struct sockaddr_in addr;
    struct sockaddr_storage storage;
    bool client = true;
    if(argc==2)
        client = false;
    socklen_t addr_size;
    udpSocket = socket(PF_INET,SOCK_DGRAM,0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = (INADDR_ANY);
    memset(addr.sin_zero,0,sizeof addr.sin_zero);
    if(!client){
        bind(udpSocket,(struct sockaddr*) &addr,sizeof(addr));
        cout<<"waiting for Email"<<endl;
    }
    addr_size = sizeof storage;
    while(!client){
        Mail mail;
        recvfrom(udpSocket,&mail,sizeof mail,0,(struct sockaddr*) &storage,&addr_size);
        cout<<"Mail received"<<endl;
        cout<<"From : "<<mail.from<<endl;
        cout<<"To : "<<mail.to<<endl;
        cout<<"Subject : "<<mail.subject<<endl;
        cout<<"Body"<<endl<<"-----"<<endl<<mail.body<<endl;
        cout<<"---------------------"<<endl;
    }
    while(client){
        //client
        Mail mail;
        cout<<"Enter from : ";
        cin.getline(mail.from,sizeof mail.from);
        cout<<"Enter to : ";
        cin.getline(mail.to,sizeof mail.to);
        cout<<"Enter subject : ";
        cin.getline(mail.subject,sizeof mail.subject);
        cout<<"Enter body"<<endl;
        cin.getline(mail.body,sizeof mail.body);
        sendto(udpSocket,&mail,sizeof mail,0,(struct sockaddr*) &addr,addr_size);
        cout<<"Mail Sent"<<endl;
    }
    return 0;
}

/*************************OUTPUT***********************

Enter from : kmjayadeep@gmail.com
Enter to : hello@cet.ac.in
Enter subject : Test mail
Enter body
this is just a test mail
Mail Sent

waiting for Email
Mail received
From : kmjayadeep@gmail.com
To : hello@cet.ac.in
Subject : Test mail
Body
-----
this is just a test mail
---------------------






Result
--------
Program is executed and output is verified
*****************************************************/
