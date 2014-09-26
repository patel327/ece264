#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

int comparef(const void * arg1, const void * arg2);
int comparefs(const void *arg1, const void *arg2);
char * strcat_ex(char * * dest, int * n, const char * src);

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
  *arrLen = N + 1;
  //int row;
  ind = 0;
  int last = 0;
  int arrInd = 0;
  
  for(ind=0; ind < strlen(str); ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
    arrstr[arrInd] = malloc(sizeof(char)*(ind-last + 1));
    //arrstr[arrInd] = '\0';
    memcpy(arrstr[arrInd], &str[last],ind-last);
    arrstr[arrInd][ind - last] = '\0';
    last = ind +1;
    arrInd++;
    }
  }
  arrstr[N] = malloc(sizeof(char)*(strlen(str)-last + 1));
  //arrstr[N] = '\0';
  memcpy(arrstr[N], &str[last],strlen(str)-last);
  arrstr[N][strlen(str) - last] = '\0';
  return (arrstr);
}

char * implode(char * * strArr, int len, const char * glue)
{
  int ind = 0;
  //char* str;
  str[0]='\0';
  for(ind = 0; ind < len; ind++)
  {
    strcat_ex(strArr,&len,glue);
  }
  for(ind = 0; ind < len-1; ind ++)
  {
    strcat_ex(strArr,&len,strArr[ind+1]);
  }
  char* str = malloc(sizeof(char)*strlen(strArr[0]));
  strcpy(str,strArr[0]);
  return(&str[0]);
}

void sortStringArray(char * * arrString, int len)
{
  qsort(&arrString[0], len, sizeof(char*),comparefs);
}

void sortStringCharacters(char * str)
{
  qsort(&str[0], strlen(str), sizeof(char),comparef);
}

void destroyStringArray(char * * strArr, int len)
{
  int ind = 0;
  for(ind = 0; ind < len; ind++)
  {
    free(strArr[ind]);
    free(strArr);
  }
}

int comparef(const void * arg1, const void * arg2)
{
  const char * ptr1 = (const char *)arg1;
  const char * ptr2 = (const char *)arg2;
  
  const char val1 = * ptr1;
  const char val2 = * ptr2;
  
  if(val1 < val2)
  {
    return -1;
  }
  else if(val1 == val2)
  {
    return 0;
  }
  return 1;
}

int comparefs(const void *arg1, const void *arg2)
{
  const char * const * ptr1 = (const char **) arg1;
  const char * const * ptr2 = (const char **) arg2;
  
  const char * str1 = * ptr1;
  const char * str2 = * ptr2;
  
  return(strcmp(str1, str2));
}
