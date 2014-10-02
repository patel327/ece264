#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
    int ind;
	
    //printf("Printing command-line arguments:\n");
    for(ind = 1; ind < argc; ind++) 
    {
	  printf("%s ", argv[ind]);
    }
    //printf("Done!\n");

    return EXIT_SUCCESS;
}
