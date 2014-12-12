#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "answer12.h"

typedef struct thread_s{
  uint128 lower;
  uint128 higher;
  uint128 value;
  uint128 prime;
}thread;

uint128 alphaTou128(const char * str){
  uint128 ret = 0;
  int ind = 0;
  int minus = 0;
  if(str[ind] == '-')
  {
    minus = 1;
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
  int counter = 0;
  
  while(test != 0){
    test = test/10;
    counter++;
  }
  
  char* ret = malloc((counter+1)*sizeof(char));
  
  for(ind = 0; ind < (counter); ind++){
    ret[counter-(ind+1)] = (value % 10)+ (int)'0';
    value = value/10;
    
  }
  ret[ind] = '\0';
  //ret = ret2;
  return ret;
}

int primalityTestParallel(uint128 value, int n_threads){
  long int max = floor(sqrt(value));
  int size = max/n_threads;
  pthread_t * arrThr = malloc(sizeof(pthread_t) * n_threads);
  thread * ranges = malloc(sizeof(thread) * n_threads);
  int count;
  for(count = 0; count < n_threads; n_threads++){
  	ranges[count].value = value;
    if(count == 0){
    	ranges[count].lower = 3;
  }
    else{
    	ranges[count].lower = count * size;
  }
  	ranges[count].higher = (count+1) * size; 
  	pthread_create(&arrThr[count],NULL, is_prime, ranges[count]);
  }  
  for(count = 0; count < n_threads; n_threads++){
  	pthread_join(arrThr[count], NULL);
  }
  count = 0;
  while(count != n_threads){
    if(ranges[count].prime == 0){
  	return 0;
    }
    else{
  	return 1;
    }
    count++;
  }  
  
//  if(value % 2 == 0){
//    if(value == 2){
//      return 1;
//    }
//    else{
//      return 0;
//    }
//  }
//  //long int max = floor(sqrt(value));
//  long int i;
//  for(i = 3; i <= max; ind += 2){
//    if (n % ((2 * i) + 1) == 0) 
//	  return 0;
//  }
//  return 1;
}

void * is_prime(void * params){
  params = (thread *) params;
  if((params -> value) % 2 == 0){
    if(params -> value == 2){
      params -> prime = 1;
      return NULL;
    }
    else{
      params -> prime = 0
      return NULL;
    }
  }
  //long int max = floor(sqrt(value));
  long int i;
  for(i = params -> lower; i <= (params -> upper); ind += 2){
    if (params -> value % ((2 * i) + 1) == 0) 
	  params -> prime = 0
	  return NULL;
  }
  params -> prime = 1
  return NULL;
}
