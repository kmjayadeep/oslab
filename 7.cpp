/*
Exp no : 7
Program to implement bankers algorithm
S1330-R-Jayadeep
26/08/16
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isNeed(int need[],int res[],int n){
    for(int i=0;i<n;i++){
        if(need[i]>res[i])
            return false;
    }
    return true;
}

bool isSafe(int need[][10],int allo[][10],int work[],int m,int n);

int main(){
    int m,n;
    cout<<"Enter no. of resources : ";
    cin>>n;
    int res[n];
    cout<<"Enter resources available :"<<endl;
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    cout<<"Enter no. of processes : "<<endl;
    cin>>m;
    int max[m][10],need[m][10],allo[m][10];
    cout<<"Enter max need of resources for each process :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter allocated resources for each process :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>allo[i][j];
            need[i][j] = max[i][j] - allo[i][j];
        }
    }
    cout<<"Need Matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<need[i][j]<<" ";
        cout<<endl;
    }
    if(!isSafe(need,allo,res,m,n))
        return 0;
    int r;
    cout<<"Enter no. of requests : ";
    cin>>r;
    cout<<"Enter process number and resources needed for each : "<<endl;
    while(r--){
        int p;
        cin>>p; p-=1;
        int req[n];
        for(int i=0;i<n;i++) cin>>req[i];
        bool f = true;
        for(int i=0;i<n;i++){
            if(req[i]+allo[p][i]>max[p][i]){
                f = false;
                cout<<"Request exceeded maximum"<<endl;
                break;
            }
            if(res[i]<req[i]){
                cout<<"Not enough resources to allocate; process has to wait"<<endl;
                f = false;
                break;
            }

        }
        if(!f) continue;
        for(int i=0;i<n;i++){
            need[p][i]-=req[i];
            allo[p][i]+=req[i];
            res[i]-=req[i];
        }
        if(!isSafe(need,allo,res,m,n)){
            for(int i=0;i<n;i++){
                need[p][i]+=req[i];
                allo[p][i]-=req[i];
                res[i]+=req[i];
            }
        }
    }
    return 0;
}

bool isSafe(int need[][10],int allo[][10],int res[],int m,int n){
    vector<bool> finish(m,false);
    vector<int> safeSeq;
    bool f;
    int work[n];
    for(int i=0;i<n;i++) work[i] = res[i];
    do{
        f = false;
        for(int i=0;i<m;i++){
            if(!finish[i]&&isNeed(need[i],work,n)){
                f = true;
                finish[i] = true;
                safeSeq.push_back(i+1);
                for(int j=0;j<n;j++){
                    work[j]+=allo[i][j];
                }
            }
        }
    }while(f);
    if(find(finish.begin(),finish.end(),false)==finish.end()){
        cout<<"Safe state"<<endl;
        cout<<"Sequence : ";
        for(int i:safeSeq)
            cout<<i<<" ";
        cout<<endl;
        return true;
    }
    cout<<"Unsafe state"<<endl;
    return false;
}


/*************************OUTPUT***********************

Enter no. of resources : 3
Enter resources available :
8 8 7
Enter no. of processes : 
3
Enter max need of resources for each process :
3 2 4
5 2 1
3 4 2
Enter allocated resources for each process :
1 1 1
1 1 1
1 1 1
Need Matrix : 
2 1 3 
4 1 0 
2 3 1 
Safe state
Sequence : 1 2 3 
Enter no. of requests : ^C


*******************************************************/



Result
--------
Program is executed and output is verified
