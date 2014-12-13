#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "answer12.h"

typedef struct thread_s{
  uint128 low;
  uint128 high;
  uint128 value;
  uint128 flag;
}mythread;

void * is_prime(void * params);

uint128 alphaTou128(const char * str){
  uint128 ret = 0;
  int ind = 0;
  int minus = 0;
  if(str[ind] == '-')
  {
    minus = 1;
    return 0;
  }
  while(str[ind] != '\0')
  {
    if(str[ind] == '0' || str[ind] == '1' || str[ind] == '2' || str[ind] == '3' || str[ind] == '4' || str[ind] == '5' || str[ind] == '6' || str[ind] == '7' || str[ind] == '8' || str[ind] == '9')
    {
      ret = 10*ret + (str[ind] - '0');
    }
  ind++;
  }
  if(minus == 1)
  {
    return -ret;
  }
    return ret;  
}

char * u128ToString(uint128 value){
  //char* ret = malloc(sizeof(char));
  //char ret2[2000];
  
  int ind = 0;
  uint128 test = value;
  int counter = 1;
  
  //if(value == 0){
  //return "0";
  //}
  
  while(test != 0){
    test = test/10;
    counter++;
  }
  
  char* ret = malloc((counter+1)*sizeof(char));
  
  if(value == 0){
  ret[0] = '0';
  ret[1] = '\0';
  return ret;
  }
  counter--;
  for(ind = 0; ind < (counter); ind++){
    ret[counter-(ind+1)] = (value % 10)+ (int)'0';
    value = value/10;
    
  }
  ret[ind] = '\0';
  //ret = ret2;
  return ret;
}
int primalityTestParallel(uint128 value, int n_threads){
  int primary = 1;
  if(value ==2 || value ==3){
    return primary;
  }
  pthread_t * arr_threads = malloc(sizeof(pthread_t) * n_threads);
  mythread * holdings = malloc(sizeof(mythread) * n_threads);
  uint128 max = floor(1.1 * sqrt(value));
  uint128 thread_width = floor(max/n_threads);
  int i;
  for(i=0; i < n_threads; i++){
    holdings[i].value = value;
    holdings[i].flag = 1;
    if(!i){
      holdings[i].low = 3;
    }
    else{
      holdings[i].low = thread_width + holdings[i-1].low;
      if(holdings[i].low % 2 == 0){
        holdings[i].low -= 1;
      }
    }
    if(!i){
      holdings[i].high = holdings[i].high + thread_width;
    }  
    else{
      holdings[i].high = holdings[i-1].high
      if(holding[i].high % 2 == 0){
        holdings[i].high -= 1;
      }
    }
    pthread_create(&arr_threads[i], NULL, isprime, &holdings[i])
    }
    for (i=0; i<n_threads; i++){
      pthread_join(arr_thread[i], NULL);
      if(holdings[i].flag == 0){
        primary = 0;
      }
    }
    free(arr_threads);
    free(holdings);
    return primacy;
  }
  
  void * isprime(void * holdings){
    mythread * testing = (mythread*) holdings;
    uint128 n = testing -> value;
    if(n % 2 ==0){
      testing -> flag = 0;
      return NULL;}
    uint128 high = (testing -> high);
    uint128 low = (testing -> low);
    uint128 i;
    for(i = low; i<= high; i++){
      if(n%i ==0){
        testing -> flag = 0;
        return NULL;
      }
      return NULL;
    }
    }
  

