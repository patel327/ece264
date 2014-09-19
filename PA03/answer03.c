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
  int* numrow = 0;
  for(ind=0; ind<strlen(str);ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
      (*numrow)++;
    }
    if(strchr(delims, str[strlen(str)-1]) != NULL)
    {
      (*numrow)++;
    }
  }
  char**arrstr = malloc(sizeof(char*)*(*numrow));
  free(*arrstr);  
  int row;
  ind=0;
  int begin = 0;
  for(row=0; row < (*numrow); row++)
  {
    int numcol = 0;
    begin = ind;
    while(strchr(delims, str[ind]) != NULL)
    {
      numcol++;
      ind++;
    }
    ind++;
    arrstr[row] = malloc(sizeof(char)*numcol);
    free(arrstr[row]);
    memcpy(arrstr[row],str,(ind-begin));
    arrstr[row][ind-begin] = '\0';

  }

  return (**arrstr);
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
