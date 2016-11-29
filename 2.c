/*
Exp No 2
Program to send an array through pipe and print prime numbers
S1330-R-Jayadeep
11-07-2016
*/

#include<stdio.h>
#include<sys/types.h>

int isPrime(int);

int main(){
      int fd[2];
      int nums[100],n,i;
      if(pipe(fd)){
            printf("Unable to create pipe");
            return;
      }
      n=5;
      pid_t pid = fork();
      if(pid>0){
            printf("Enter no. of elements : ");
            scanf("%id",&n);
            printf("Enter elements\n");
            for(i=0;i<n;i++){
                  scanf("%d",nums+i);
            }
            write(fd[1],nums,n*sizeof(int));
            return 0;
      }
      read(fd[0],nums,n*sizeof(int));
      printf("Prime numbers : ");
      for(i=0;i<n;i++){
            if(isPrime(nums[i]))
                  printf("%d ",nums[i]);
      }
      printf("\n");
      return 0;
}

int isPrime(int n){
      int i;
      if(n<2) return 0;
      for(i=2;i<n;i++)
            if(n%i==0)
                  return 0;
      return 1;
}


/***********************SAMPLE OUTPUT*******************


Enter no. of elements : 7
Enter elements
3 4 5 6 7 8 3
Prime numbers : 3 5 7




Result
--------
Program is executed and output is verified
*******************************************************/
