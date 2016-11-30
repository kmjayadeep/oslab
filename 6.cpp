/*
  Exp no : 6
  Dining philosopher problem
  S1330-R-Jayadeep
  01/04/2016
*/

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>

using namespace std;
sem_t s;
sem_t fork[5];

void *eatAndThink(void * arg){
  int i=*(int*)arg;
  sem_wait(&s);
  cout<<"phil "+to_string(i)+" waiting"+"\n";
  sem_wait(fork+i);
  sem_wait(fork+(i+1)%5);
  cout<<"phil "+to_string(i)+" eating"+"\n";
  sem_post(fork+(i+1)%5);
  sem_post(fork+i);
  cout<<"phil "+to_string(i)+" thinking"+"\n";
  sem_post(&s);
  pthread_exit(NULL);
}
int main(){
  sem_init(&s,0,4);
  for(int i=0;i<5;i++)
    sem_init(fork+i,0,1);
  pthread_t phil[5];
  int args[5];
  for(int i=0;i<5;i++){
    args[i] = i;
    if(pthread_create(phil+i,NULL,&eatAndThink,args+i)!=0){
      cout<<"phil"<<i<<"not created";
    }
  }
  pthread_exit(NULL);
}


/*************************OUTPUT***********************

phil 1 waiting
phil 1 eating
phil 1 thinking
phil 3 waiting
phil 3 eating
phil 3 thinking
phil 0 waiting
phil 4 waiting
phil 0 eating
phil 0 thinking
phil 4 eating
phil 4 thinking
phil 2 waiting
phil 2 eating
phil 2 thinking


Result
--------
Program is executed and output is verified
*******************************************************/
