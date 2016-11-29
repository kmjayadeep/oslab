/*
Exp no : 13
Selective repeat SW simulation
S1330-R-Jayadeep
15/11/2016
*/

#include<iostream>
#include<random>
#include<queue>
#include<map>

using namespace std;

#define window_size 5

class Socket{
	map<int,char> data;
public:
	int receive(char c,int seq){
		if(random()%2){
			data[seq] = c;
			return seq;
		}
		else
			return -1;
	}
	string receivedData(){
		string ret = "";
		for(auto i:data){
			ret+=i.second;
		}
		return ret;
	}
};

int main(){
	string input;
	cout<<"Enter input string : ";
	cin>>input;
	Socket socket;
	int ack;
	queue<pair<int,char>> data;
	for(int i=0;i<input.length();i+=window_size){
		for(int j=i;j<i+window_size&&j<input.length();j++)
			data.push(pair<int,char>(j,input[j]));
		while(!data.empty()){
			pair<int,char> d = data.front();
			cout<<"Sending "<<d.second<<" : "<<d.first<<endl;
			ack = socket.receive(d.second,d.first);
			data.pop();
			if(ack!=-1){
				cout<<"Received ack : "<<ack<<endl;
			}
			else{
				cout<<"Not received ack : "<<ack<<endl;
				data.push(d);
			}
		}
		cout<<"Received : "+socket.receivedData()<<endl;
	}
	return 0;
}

/************************OUTPUT***************************

Enter input string : helloworld
Sending h : 0
Received ack : 0
Sending e : 1
Not received ack : -1
Sending l : 2
Received ack : 2
Sending l : 3
Received ack : 3
Sending o : 4
Received ack : 4
Sending w : 5
Received ack : 5
Sending o : 6
Not received ack : -1
Sending r : 7
Not received ack : -1
Sending l : 8
Received ack : 8
Sending d : 9
Received ack : 9
Sending e : 1
Not received ack : -1
Sending o : 6
Received ack : 6
Sending r : 7
Not received ack : -1
Sending e : 1
Received ack : 1
Sending r : 7
Received ack : 7
Received : helloworld



Result
--------
Program is executed and output is verified
*************************************************/
