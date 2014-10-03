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
  return EXIT_SUCCESS;
}  
