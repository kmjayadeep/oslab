/*
 Exp No 1
Program to fork a process and print its details
S1330-R-jayadeep
30-06-2016 */

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
        if(pid>0){
                printDetails();
                printf("%d : child id is %d\n",getpid(),pid);
        }else{
                printDetails();
                printf("%d : i am child of %d\n",getpid(),getppid());
        }
        return 0;
}

/******************************OUTPUT***************************

19603 : process id is : 19603
19603 : parent id is : 18918
19603 : real user id is : 1031
19603 : effective user id is : 1031
19603 : group id is : 1031
19604 : process id is : 19604
19604 : parent id is : 19603
19603 : effective group id is : 1031
19604 : real user id is : 1031
19603 : child id is 19604
19604 : effective user id is : 1031
19604 : group id is : 1031
19604 : effective group id is : 1031
19604 : i am child of 19603



Result
--------
Program is executed and output is verified

****************************************************************/
