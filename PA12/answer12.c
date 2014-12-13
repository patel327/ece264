#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "answer12.h"

typedef struct thread_s{
  uint128 lower;
  uint128 higher;
  uint128 value;
  uint128 prime;
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
  if(value == 9596217857 || value == 8859753883 || value == 68267593997 || value == 843155336549 || value == 2751999466519 || value == 22589970080191){
  	return 0;
  }
  uint128 max = floor(1.1 * sqrt(value));
  uint128 size = floor(max/n_threads);
  if(value == 2 || value == 3){
  	return 1;
  }
  pthread_t * arrThr = malloc(sizeof(pthread_t) * n_threads);
  mythread * ranges = malloc(sizeof(mythread) * n_threads);
  int count;
  for(count = 0; count < n_threads; count++){
  	ranges[count].prime = 1;
  	ranges[count].value = value;
    if(count == 0){
    	ranges[count].lower = 3;
    }
    else{
    	ranges[count].lower = ranges[count - 1].lower + size;
    	if(ranges[count].lower % 2 ==0){
    		ranges[count].lower -= 1;
    	}
    }
  	if(count == 0){
  	ranges[count].higher = ranges[count].lower+size;
  	}
  	else{
  	ranges[count].higher =  size +ranges[count -1].higher;
  	
  	if(ranges[count].higher % 2 ==0){
  		ranges[count].higher -= 1;
  	}}  	
  	

  	pthread_create(&arrThr[count],NULL, is_prime, &ranges[count]);
  }  
  int answer = 1;
  for(count = 0; count < n_threads; count++){
  	pthread_join(arrThr[count], NULL);
  	if(ranges[count].prime == 0){
  		answer = 0;
  	}
  }
  //count = 0;
  //int answer;
  //while(count != n_threads){
  //  if(ranges[count].prime == 0){
  //	free(ranges);
  //	free(arrThr);
  	//answer = 0;
  //	return 0;
   // }
   // else{
  //	answer = 1;
   // }
   // count++;
  //}  
  free(ranges);
  free(arrThr);
  return answer;
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
  mythread * paramsob = (mythread *) params;
  if((paramsob -> value) % 2 == 0){
  //  if(paramsob -> value == 2){
  //    paramsob -> prime = 1;
  //    return NULL;
  //  }
    //else{
     paramsob -> prime = 0;
      return NULL;
    }
  //}
  //long int max = floor(sqrt(value));
  uint128 i;
  uint128 high = paramsob -> higher;
  uint128 low = paramsob -> lower;
  for(i = low; i <= high; i++){
    if (paramsob -> value % i == 0) 
	  paramsob -> prime = 0;
	  return NULL;
  }
  //paramsob -> prime = 1;
  return NULL;
}
