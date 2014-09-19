#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * * argv)
{

//char * s1 = "Hello World!";
//char * s2 = "";
//char * s3 = "foo";
char* dest = NULL;
char src = "added";
int n = 1;

printf("answer = %s\n", strcat_ex(&dest, &n, src));

return EXIT_SUCCESS;
}
