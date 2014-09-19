#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
  
  
  if( (*dest == NULL) || (strlen(src) + strlen(*dest) + 1 > *n) )
  {
    char * newdest;
    *newdest = malloc(sizeof(char*)*(1 + 2 * (strlen(*dest) + strlen(src))));
    *n = (1 + 2 * (strlen(*dest) + strlen(src)));
    
    strcpy(*newdest,*dest);
    free(*dest);
    *dest = &newdest;
    strcat(*dest, src);
    return (*dest);
  }
  else
  {
    strcat(*dest, src); //append with enough space
    return(*dest);
  }
}
