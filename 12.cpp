/*
Exp no : 12
Go Back-N SW simulation
S1330-R-Jayadeep
15/11/2016
*/

#include<iostream>
#include<cstring>
#include<random>
#include<map>
#include<climits>

using namespace std;

int window_size = 5;

class Socket{
	map<int,char> data;
public:
	int receive(int seq){
		if(data[seq])
			return seq;
		else
			return INT_MAX;
	}
	void send(char c,int seq){
		if(random()%2){
			data[seq] = c;
		}
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
	char in[100];
	cout<<"Enter input string : ";
	cin.getline(in,100);
	string input(in);
	Socket socket;
	int ack;
	int i=0;
	window_size--;
	int count = 0;
	while(i<(input.length()+window_size)){
		if(i<input.length()){
			cout<<"Sending "<<input[i]<<" : "<<i<<endl;
			socket.send(input[i],i);
		}
		if(i>=window_size){
			ack = socket.receive(i-window_size);
			if(ack!=INT_MAX){
				if(ack==count){
					cout<<"Received ack : "<<ack<<endl;
					count++;
				}
			}
			else{
				cout<<"Not received ack : "<<i-window_size<<endl;
				i = i - window_size - 1;
			}
		}
		i++;
	}
	cout<<"Received : "+socket.receivedData()<<endl;
	return 0;
}

/************************OUTPUT***************************


Enter input string : helloworldindia
Sending h : 0
Sending e : 1
Sending l : 2
Sending l : 3
Sending o : 4
Sending w : 5
Received ack : 0
Sending o : 6
Not received ack : 1
Sending e : 1
Sending l : 2
Sending l : 3
Sending o : 4
Sending w : 5
Received ack : 0
Sending o : 6
Not received ack : 1
Sending e : 1
Sending l : 2
Sending l : 3
Sending o : 4
Sending w : 5
Received ack : 0
Sending o : 6
Received ack : 1
Sending r : 7
Received ack : 2
Sending l : 8
Received ack : 3
Sending d : 9
Received ack : 4
Sending i : 10
Received ack : 5
Sending n : 11
Not received ack : 6
Sending o : 6
Received ack : 1
Sending r : 7
Received ack : 2
Sending l : 8
Received ack : 3
Sending d : 9
Received ack : 4
Sending i : 10
Received ack : 5
Sending n : 11
Not received ack : 6
Sending o : 6
Received ack : 1
Sending r : 7
Received ack : 2
Sending l : 8
Received ack : 3
Sending d : 9
Received ack : 4
Sending i : 10
Received ack : 5
Sending n : 11
Received ack : 6
Sending d : 12
Not received ack : 7
Sending r : 7
Received ack : 2
Sending l : 8
Received ack : 3
Sending d : 9
Received ack : 4
Sending i : 10
Received ack : 5
Sending n : 11
Received ack : 6
Sending d : 12
Not received ack : 7
Sending r : 7
Received ack : 2
Sending l : 8
Received ack : 3
Sending d : 9
Received ack : 4
Sending i : 10
Received ack : 5
Sending n : 11
Received ack : 6
Sending d : 12
Received ack : 7
Sending i : 13
Received ack : 8
Sending a : 14
Received ack : 9
Received ack : 10
Received ack : 11
Received ack : 12
Not received ack : 13
Sending i : 13
Received ack : 8
Sending a : 14
Received ack : 9
Received ack : 10
Received ack : 11
Received ack : 12
Received ack : 13
Received ack : 14
Received : helloworldindia



Result
--------
Program is executed and output is verified
*************************************************/
