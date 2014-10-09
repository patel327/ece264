#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer05.h"

void printPart(int *arr, int len)
{
  int ind;
  printf("=");
  for(ind=0; ind<len-1; ind++)
  {
    printf("%d + ",arr[ind]);
  }
  printf("%d\n", arr[len-1]);
}

void evenpartition(int *arr, int ind, int left)
{
  int val;
  if(left == 0)
  {
    printPart(arr, ind);
    return;
  }
  for(val = 2; val<= left; val+=2)
  {
    arr[ind] = val;
    evenpartition(arr, ind+1, left-val);
  }
}

void decpartition(int * arr, int ind, int left)
{
  int val = ind;
  if (left == val)
  {
    printPart(arr, ind);
    return;
  }
  int max = left;
  if(ind != left)
  {
    max = arr[ind + 1] - 1;
  }
  for (val = max; val >= left; val--)
  {
    arr[ind] = val;
    decpartition(arr, ind - 1, left + val);
  }
}

void incpartition(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
  {
    printPart(arr, ind);
    return;
  }
  int min = 1;
  if(ind != 0)
  {
    min = arr[ind - 1] + 1;
  }
  for (val = min; val <= left; val++)
  {
    arr[ind] = val;
    incpartition(arr, ind + 1, left - val);
  }
}

void oddpartition(int *arr, int ind, int left)
{
  int val;
  if(left == 0)
  {
    printPart(arr, ind);
    return;
  }
  for(val = 1; val<= left; val+=2)
  {
    arr[ind] = val;
    oddpartition(arr, ind+1, left-val);
  }
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
  //return EXIT_SUCCESS;
  
}

void partitionIncreasing(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  incpartition(arr,0,value);
  free(arr);
}

void partitionDecreasing(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  decpartition(arr,value,0);
  free(arr);
}

void partitionOdd(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  oddpartition(arr,0,value);
  free(arr);
  //return EXIT_SUCCESS;
}

void partitionEven(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  evenpartition(arr,0,value);
  free(arr);
  //return EXIT_SUCCESS;
}

void partitionOddAndEven(int value)
{
  //return;
}

void partitionPrime(int value)
{
  //return;
}
