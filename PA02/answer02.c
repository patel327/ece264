#include <stdlib.h>
#include <stdio.h>
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
  int counter = 0;
  //char *none="null";

  
  while(str[len] != '\0')
  {
    len = len + 1;
  }
  
  for(counter = 0; counter<len+1;counter++)
  {
    if(str[counter] == ch)
    {
      return &str[counter];
    }
    //len++;
  }
  return NULL;
}  
  
char * my_strrchr(const char * str, int ch)
{
  int len = 0;
  int counter = 0;
  //char *none="null";

  
  while(str[len] != '\0')
  {
    len = len + 1;
  }
  
  for(counter = len+1; counter>len+1;counter--)
  {
    if(str[counter] == ch)
    {
      return &str[counter];
    }
    //len++;
  }
  return NULL;
}
