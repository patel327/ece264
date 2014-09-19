#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
  
  
  if( (*dest == NULL))
  {
    char * newdest;
    newdest = malloc(sizeof(char*)*(1 + 2 * (strlen(src))));
    *n = (1 + 2 * (strlen(src)));
    
    strcpy(newdest,*dest);
    free(*dest);
    **dest = &newdest;
    strcat(*dest, src);
    return (*dest);
  }
  else if((strlen(src) + strlen(*dest) + 1 > *n) )
  {
    char * newdest;
    newdest = malloc(sizeof(char*)*(1 + 2 * (strlen(*dest) + strlen(src))));
    *n = (1 + 2 * (strlen(*dest) + strlen(src)));
    
    strcpy(newdest,*dest);
    free(*dest);
    **dest = &newdest;
    strcat(*dest, src);
    return (*dest);
  }
  else
  {
    strcat(*dest, src); //append with enough space
    return(*dest);
  }
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  return 0;
}

char * implode(char * * strArr, int len, const char * glue)
{
  return 0;
}

void sortStringArray(char * * arrString, int len)
{
  return 0;
}

void sortStringCharacters(char * str)
{
  return 0;
}

void destroyStringArray(char * * strArr, int len)
{
  return 0;
}
