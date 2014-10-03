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
    int a = 0;
    int b = 0; //counters
    int c = 0; //counters
    //FILE* rfile = fopen(argv[ind],"r");
    //if(rfile == NULL)
    //{
    //  fprintf(stderr, "cat cannot open %s\n", argv[ind]);
    //  return EXIT_FAILURE;
    //}
    if(argv[1] == "\0")
    {
      a = fgetc(stdin);
      fputc(a, stdout);
    }
    if((strcmp(argv[ind],"-") == 0))
    {
      while(b!=EOF){
      b = fgetc(stdin);
      if(b !=EOF){
      fputc(b, stdout);}
      }

    }
    else
    {
      FILE* rfile = fopen(argv[ind],"r");
      if(rfile == NULL)
      {
      fprintf(stderr, "cat cannot open %s\n", argv[ind]);
      return EXIT_FAILURE;
      }
      while(c!=EOF) {
      c = fgetc(rfile);
      if(c !=EOF){
      fputc(c ,stdout);}
      }

      fclose(rfile);
    }
    if((argc - ind) == 1)
    {printf("\n");}
  }
  return EXIT_SUCCESS;
}  
