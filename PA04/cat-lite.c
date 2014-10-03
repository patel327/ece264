#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind;
    //printf("Printing command-line arguments:\n");
  for(ind = 1; ind < argc; ind++)
  {
  if(strcmp(argv[ind],"--help") == 0)
  {
    printf("Usage: cat-lite [--help] [FILE]...\n"
    "With no FILE, or when FILE is -, read standard input.\n\n"

    "Examples:\n"
    "cat-lite README   Print the file README to standard output.\n"
    "cat-lite f - g    Print f's contents, then standard input,\n" 
    "                  then g's contents.\n"
    "cat-lite          Copy standard input to standard output.\n");
    return EXIT_SUCCESS;
  }
  }  
  
  
  for(ind = 1; ind < argc; ind++)
  {
    FILE* rfile = fopen(argv[ind],"r");
    if(rfile == NULL)
    {
      fprintf(stderr, "cat cannot open %s\n", argv[ind]);
      return EXIT_FAILURE;
    }
    if(argv[ind] == "-")
    {
      int b = fgetc(stdin);
      fputc(b, stdout);
    }
    else
    {
    int c = fgetc(*argv[ind]);
    fputc(c ,stdout);
    }
    fclose(argv[ind]);
    return EXIT_SUCCESS;
  }
}  
