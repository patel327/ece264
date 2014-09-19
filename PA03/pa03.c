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
int arrLen;


printf("answer = %s\n", strcat_ex(&dest, &n, src));
printf("answer2 = %s\n", implode(str*, &delims, &arrLen));

return EXIT_SUCCESS;
}
