#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"

int main(int argc, char * * argv)
{

//char * s1 = "Hello World!";
//char * s2 = "";
//char * s3 = "foo";
char* dest = NULL;
char* src = "added";
int n = 1;
char * str = "The\nTuring test";
char * delims = " \n";
char * str1 = "The Turing test";
char * delims1 = " ";
int arrLen;
int arrLen1


printf("answer = %s\n", strcat_ex(&dest, &n, src));
printf("answer2 = %s\n", explode(str, delims, &arrLen));
printf("answer3 = %s\n", explode(str1, delims1, &arrLen1));

return EXIT_SUCCESS;
}
