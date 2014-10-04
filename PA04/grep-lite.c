#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int ind;
  
   for(ind = 1; ind < argc; ind++)
  {
  if(strcmp(argv[ind],"--help") == 0)
  {
  printf("Usage: grep-lite [OPTION]... PATTERN\n"
  "Search for PATTERN in standard input. PATTERN is a\n"
  "string. grep-lite will search standard input line by\n"
  "line, and (by default) print out those lines which\n"
  "contain pattern as a substring.\n"
  "\n"
  "  -v, --invert-match     print non-matching lines\n"
  "  -n, --line-number      print line numbers with output\n"
  "  -q, --quiet            suppress all output\n"
  "\n"
  "Exit status is 0 if any line is selected, 1 otherwise;\n"
  "if any error occurs, then the exit status is 2.\n");
  return EXIT_SUCCESS;
  }
  }  
  
  char mystring[2001];
  //fgets(mystring,2001,stdin);
  
  while(fgets(mystring,2001,stdin) != NULL)
  {
  if(((strstr(mystring,"-q")) != NULL)||((strstr(mystring,"-n")) != NULL)||((strstr(mystring,"-v")) != NULL)||((strstr(mystring,"--invert-match")) != NULL)||((strstr(mystring,"--quiet")) != NULL)||((strstr(mystring,"--line-number")) != NULL))
  return 2;
  }
  int lineNo = 1;
  int counter = 0;
  while(fgets(mystring,2001,stdin) != NULL)
  {
    lineNo++;
    if((strstr(mystring, "-q") != NULL)||(strstr(mystring, "--quiet") != NULL)){
    return 1;
    if((strstr(mystring, "-n") != NULL)||(strstr(mystring, "--line-number") != NULL)){
    printf("%d:",lineNo);
    counter++;}    
    if((strstr(mystring, "-v") != NULL)||(strstr(mystring, "--invert-match") != NULL)){
      if(strstr(mystring ,(argv[argc])) == NULL){ //pattern found
        fputs(mystring, stdout);
        counter++;
      }
    }

    return 0;

    }
  }
  
  return 1;
}
