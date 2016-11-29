/*
Exp no : 11
Stop and wait SW simulation
S1330-R-Jayadeep
06/10/2016
*/

#include<iostream>
#include<random>

using namespace std;

class Socket{
    string data;
public:
    int receive(char c,int seq){
        if(random()%2){
            data+=c;
            return seq;
        }
        else
            return -1;
    }
    string receivedData(){
        return data;
    }
};

int main(){
    string input;
    cout<<"Enter input string : ";
    cin>>input;
    Socket socket;
    int ack;
    for(int i=0;i<input.length();i++){
        do{
            cout<<"Sending "<<input[i]<<endl;
            ack = socket.receive(input[i],i);
            cout<<"Received ack : "<<ack<<endl;
        }while(ack!=i);
    }
    cout<<"Received : "+socket.receivedData()<<endl;
    return 0;
}

/************************OUTPUT***************************

Enter input string : helloworld
Sending h
Received ack : 0
Sending e
Received ack : -1
Sending e
Received ack : 1
Sending l
Received ack : 2
Sending l
Received ack : 3
Sending o
Received ack : 4
Sending w
Received ack : -1
Sending w
Received ack : -1
Sending w
Received ack : 5
Sending o
Received ack : 6
Sending r
Received ack : -1
Sending r
Received ack : 7
Sending l
Received ack : -1
Sending l
Received ack : 8
Sending d
Received ack : 9
Received : helloworld

*************************************************/



Result
--------
Program is executed and output is verified
