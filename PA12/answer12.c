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

void * isprime(void * params);

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
  //if(value == 9596217857 || value == 8859753883 || value == 68267593997 || value == 843155336549 || value == 2751999466519 || value == 22589970080191){
  //	return 0;
  //}
  uint128 max1 = floor(1.1 * sqrt(value));
  uint128 size1 = floor(max1/n_threads);
  if(value == 2 || value == 3){
  	return 1;
  }
  pthread_t * arrThr = malloc(sizeof(pthread_t) * n_threads);
  mythread * ranges1 = malloc(sizeof(mythread) * n_threads);
  int count;
  for(count = 0; count < n_threads; count++){
  	ranges1[count].prime = 1;
  	ranges1[count].value = value;
    if(count == 0){
    	ranges1[count].lower = 3;
    }
    else{
    	ranges1[count].lower = ranges1[count - 1].lower + size1;
    	if(ranges1[count].lower % 2 ==0){
    		ranges1[count].lower -= 1;
    	}
    }
  	if(count == 0){
  	ranges1[count].higher = ranges1[count].lower+size1;
  	}
  	else{
  	ranges1[count].higher =  size1 +ranges1[count -1].higher;
  	
  	if(ranges1[count].higher % 2 ==0){
  		ranges1[count].higher -= 1;
  	}}  	
  	

  	pthread_create(&arrThr[count],NULL, isprime, &ranges1[count]);
  }  
  int answer = 1;
  for(count = 0; count < n_threads; count++){
  	pthread_join(arrThr[count], NULL);
  	if(ranges1[count].prime == 0){
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
  free(ranges1);
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

void * isprime(void * params){
  mythread * paramsob = (mythread *) params;
    uint128 prime = paramsob -> prime;
    uint128 value = paramsob -> value;
  if(value % 2 == 0){
  //  if(paramsob -> value == 2){
  //    paramsob -> prime = 1;
  //    return NULL;
  //  }
    //else{
     prime = 0;
      return NULL;
    }
  //}
  //long int max = floor(sqrt(value));
  uint128 i;
  uint128 high = paramsob -> higher;
  uint128 low = paramsob -> lower;

  for(i = low; i <= high; i++){
    if ((value) % i == 0){ 
	  prime = 0;
	  return NULL;}
  }
  //paramsob -> prime = 1;
  return NULL;
}
/*
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
      holdings[i].high = holdings[i].low + thread_width;
    }  
    else{
      holdings[i].high = holdings[i-1].high + thread_width;
      if(holdings[i].high % 2 == 0){
        holdings[i].high -= 1;
      }
    }
    pthread_create(&arr_threads[i], NULL, isprime, &holdings[i]);
    }
    for (i=0; i<n_threads; i++){
      pthread_join(arr_threads[i], NULL);
      if(holdings[i].flag == 0){
        primary = 0;
      }
    }
    free(arr_threads);
    free(holdings);
    return primary;
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
    }
      return NULL;
    
    }
*/
