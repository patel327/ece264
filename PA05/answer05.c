#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer05.h"



void partitionAll(int value)
{
  int * arr;
  arr = malloc(sizeof(int)*value);
  partition(arr,0,value);
  free(arr);
  return EXIT_SUCCESS;
  
}
