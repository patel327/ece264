#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer05.h"

void printPart(int *arr, int len)
{
  int ind;
  printf("=");
  for(ind=0; ind<len-1; ind++);
  {
    printf("%d +",arr[ind]);
  }
  printf("%d\n", arr[len-1]);
}

void partition(int *arr, int ind, int left)
{
  int val;
  if(left == 0)
  {
    printPart(arr, ind);
    return;
  }
  for(val = 1; val<= left; val++)
  {
    arr[ind] = val;
    partition(arr, ind+1, left-val);
  }
}

void partitionAll(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  partition(arr,0,value);
  free(arr);
  return EXIT_SUCCESS;
  
}

void partitionIncreasing(int value)
{
  //return;
}

void partitionDecreasing(int value)
{
  //return;
}

void partitionOdd(int value)
{
  //return;
}

void partitionEven(int value)
{
  //return;
}

void partitionOddAndEven(int value)
{
  //return;
}

void partitionPrime(int value)
{
  //return;
}
