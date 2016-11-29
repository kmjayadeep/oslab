/*
Exp no : 8
Program to show disk usage status
S1330-R-Jayadeep
26/8/16
*/

#include<iostream>
#include<sys/statvfs.h>
#include<sys/types.h>

using namespace std;

int main(int argc,char* argv[]){
    if(argc<2){
        cout<<"enter path as command line argument"<<endl;
        return 0;
    }
    struct statvfs data;
    if(statvfs(argv[1],&data)<0){
        cout<<"error"<<endl;
    }else{
                cout<<"File system block size : "<<data.f_bsize<<endl;
                cout<<"Fragment size : "<<data.f_frsize<<endl;
                cout<<"Frees Blocks : "<<data.f_bfree<<endl;
                cout<<"Innodes : "<<data.f_files<<endl;
                cout<<"Free innodes : "<<data.f_ffree<<endl;
                cout<<"File sytem id : "<<data.f_fsid<<endl;
    }
}


/********************OUTPUT*****************************************

s1330@linux-server:~/os$ a.out .
File system block size : 4096
Fragment size : 4096
Frees Blocks : 93707010
Innodes : 24420352
Free innodes : 24242469
File sytem id : 4447693369191545766


******************************************************************/




Result
--------
Program is executed and output is verified
