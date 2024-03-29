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
  
  for(counter = len; counter>=0;counter--)
  {
    if(str[counter] == ch)
    {
      return &str[counter];
    }
    //len++;
  }
  return NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int len = 0;
  int counter = 0;
  //char *none="null";

  
  while(haystack[len] != '\0')
  {
    len = len + 1;
  }
  
  if(needle[counter] == '\0')
  {
    return &haystack[0];
  }
  for(counter = 0; counter<len+1;counter++)
  {
    if(haystack[counter] == needle[0])
    {
      return &haystack[counter];
    }
    //len++;
  }
  return NULL;
}  

char * my_strcpy(char * dest, const char * src)
{
  int counter = 0;
  
  while(src[counter] != '\0')
  {
    dest[counter] = src[counter];
    counter++;
  }
  dest[counter] = '\0';
  
  return &dest[0];
}

char * my_strcat(char * dest, const char * src)
{
  int counter = 0;
  int ind = 0;
  
  while(dest[counter] != '\0')
  {
    counter++;
  }
  while(src[ind] !='\0')
  {
    dest[counter+ind] = src[ind];
    ind++;
  }
  dest[counter+ind] = '\0';
  
  return &dest[0];
}

int my_isspace(int ch)
{
  int success = 0;
  
  if((ch == '\r') || (ch == '\t') || (ch == ' ') || (ch == '\n') || (ch == '\v') || (ch == '\f'))
  {
    success = 1;
  }

  return success;
}

int my_atoi(const char * str)
{
  int ret = 0;
  int ind = 0;
  int minus = 0;
  
  
  if(str[ind] == '-')
  {
  minus = 1;
  }
  
  while(str[ind] != '\0')
  {
    if(str[ind] == '0' || str[ind] == '1' || str[ind] == '2' || str[ind] == '3' || str[ind] == '4' || str[ind] == '5' || str[ind] == '6' || str[ind] == '7' || str[ind] == '8' || str[ind] == '9')
    {
      ret = 10*ret + (str[ind] - '0');
    }
    ind++;
  }
  
  if(minus == 1)
  {
    return -ret;
  }
  return ret;
}
