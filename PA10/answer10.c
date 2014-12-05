#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer10.h"

typedef struct locnode_tr{
  struct locnode_tr * next;
  long int bOffset;
  long int rOffset;
}locnode;

typedef struct busnode_tr {
  char * name;
  locnode * head;
  struct busnode_tr * left;
  struct busnode_tr * right;
}busnode;

typedef struct YelpDataBST {
  FILE * busptr;
  FILE * revptr;
  busnode * root;
} YelpDataBST;

struct YelpDataBST* create_business_bst(const char* businesses_path,
const char* reviews_path){
  FILE * bptr;
  FILE * rptr;
  char  line[2000];
  long int busoff;
  
  YelpDataBST * busbst = malloc(sizeof(YelpDataBST));
  bptr = fopen(businesses_path, "r");
  rptr = fopen(reviews_path, "r");
  while(fgets(line, 2000,bptr) != NULL){
    busoff = ftell(bptr);
    
  }
  
  
}

struct Business* get_business_reviews(struct YelpDataBST* bst,
char* name, char* state, char* zip_code){
  
}

void destroy_business_bst(struct YelpDataBST* bst){
  
}

void destroy_business_result(struct Business* b){
  
}


char ** explode(const char * str, const char * delims/*, int * arrLen*/)
{
int ind;
int N = 0;
for(ind=0; ind<strlen(str);ind++)
{
if(strchr(delims, str[ind]) != NULL)
{
N++;
}
}
char**arrstr = malloc(sizeof(char*)*(N+1));
//*arrLen = N + 1;
//int row;
ind = 0;
int last = 0;
int arrInd = 0;
for(ind=0; ind < strlen(str); ind++)
{
if(strchr(delims, str[ind]) != NULL)
{
arrstr[arrInd] = malloc(sizeof(char)*(ind-last + 1));
//arrstr[arrInd] = '\0';
memcpy(arrstr[arrInd], &str[last],ind-last);
arrstr[arrInd][ind - last] = '\0';
last = ind +1;
arrInd++;
}
}
arrstr[N] = malloc(sizeof(char)*(strlen(str)-last + 1));
//arrstr[N] = '\0';
memcpy(arrstr[N], &str[last],strlen(str)-last);
arrstr[N][strlen(str) - last] = '\0';
return (arrstr);
}
