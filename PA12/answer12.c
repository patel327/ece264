#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "answer12.h"

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
  char* ret = malloc(sizeof(char));
  //char ret2[2000];
  
  int ind = 0;
  uint128 test = value;
  int counter = 0;
  
  while(test != 0){
    test = test/10;
    counter++;
  }
  for(ind = 0; ind < counter; ind++){
    ret[counter-(ind+1)] = (value % 10)+ (int)'0';
    value = value/10;
    
  }
  ret[counter] = '\0';
  //ret = ret2;
  return ret;
}

int primalityTestParallel(uint128 value, int n_threads){
  
}
