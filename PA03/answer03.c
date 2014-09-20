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
    
    //strcpy(newdest,*dest);
    
    *dest = newdest;
    *dest[0] = '\0';
    strcat(*dest, src);
    return (*dest);
  }
  else if((strlen(src) + strlen(*dest) + 1 > *n) )
  {
    char * newdest;
    newdest = malloc(sizeof(char*)*(1 + 2 * (strlen(*dest) + strlen(src))));
    *n = (1 + 2 * (strlen(*dest) + strlen(src)));
    newdest[0] = '\0';
    strcpy(newdest,*dest);
    free(*dest);
    *dest = newdest;
    strcat(*dest, src);
    return (*dest);
  }
  else
  {
    strcat(*dest, src); //append with enough space
    return(*dest);
  }
}

char ** explode(const char * str, const char * delims, int * arrLen)
{
  int ind;
  int N = 0;
  for(ind=0; ind<strlen(str);ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
      N++;
    }
  }
  
  char**arrstr = malloc(sizeof(char*)*(N+1));
  arrLen = strlen(*arrstr);
  int row;
  ind = 0;
  int last = 0;
  int arrInd = 0;
  
  for(ind=0; ind < (N); ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
    arrstr[arrInd] = malloc(sizeof(char)*(ind-last));
    arrstr[arrInd] = '\0';
    memcpy(arrstr[arrInd], &str[last],ind-last);
    last = ind +1;
    arrInd++;
    }
  }
  arrstr[N] = malloc(sizeof(char)*(strlen(str)-last));
  arrstr[N] = '\0';
  memcpy(arrstr[N], &str[last],strlen(str)-last);
  return (arrstr);
}

char * implode(char * * strArr, int len, const char * glue)
{
  return 0;
}

void sortStringArray(char * * arrString, int len)
{
  
}

void sortStringCharacters(char * str)
{
  
}

void destroyStringArray(char * * strArr, int len)
{
  
}
