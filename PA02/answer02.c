#include <stdlib.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
  int len=0;
  
  while(str[len] != '\0')
  {  
    len = len + 1;
  }
  return len;
}

int my_countchar(const char * str, char ch)
{
  int len = 0;
  int counter = 0;
  int occur = 0;
  
  while(str[len] != '\0')
  {
    len = len + 1;
  }
  
  do
  {
    if(str[counter] == ch)
    {
      occur = occur + 1;
    }
    counter = counter + 1;
  }while(counter<len+1);
  
  return occur;
}

char * my_strchr(const char * str, int ch)
{
  int len = 0;
  int place = -2;
  int counter = 0;
  const char * newstr;
  int ind;
  int rtrn;
  
  while(str[len] != '\0')
  {
    len = len + 1;
  }
  do
  {
    if(str[counter] == ch)
    {
      place = counter;
    }
    counter++;
  }while(counter<len+1 || place != (counter+1));  
  
  if place = -2
  {
    rtrn = (null)
  }
  else
  {
    for(ind=place;ind<=len+1;ind++)
    {
    newstr[ind]=str[ind];
    }
    rtrn = newstr[ind];
  }
  return rtrn;
  
}
