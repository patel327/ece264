#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"

void test5()
{
  const char * str = "The\nTuring test";
  const char * delims = " \n";
  int n;
  char * * strArr = explode(str, delims, &n);
  printf("answer2 = %s\n", strArr[0]);
}

int main(int argc, char * * argv)
{
  test5();
  int len = 0;
  char * * strArr = explode("100 224 147 80", " ", &len);
  char * str = implode(strArr, len, ", ");
  printf("(%s)\n", str); // (100, 224, 147, 80)
  return 0;
//char * s1 = "Hello World!";
//char * s2 = "";
//char * s3 = "foo";
//char* dest = NULL;
//char* src = "added";
//int n = 1;
//char * str = "The\nTuring test";
//char * delims = " \n";
//char * str1 = "The Turing test";
//char * delims1 = " ";
//int arrLen;
//int arrLen1;

  //int arr[] = {1 ,2, 3};


 //printf("answer = %s\n", strcat_ex(&dest, &n, src));
 //printf("answer2 = %s\n", explode(str, delims, &arrLen));
 //printf("answer3 = %s\n", explode(str1, delims1, &arrLen1));

return EXIT_SUCCESS;
}
