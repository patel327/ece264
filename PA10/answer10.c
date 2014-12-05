#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer10.h"

tree_insert(busnode * treenode, busnode * root);
char ** explode(const char * str, const char * delims/*, int * arrLen*/);
rofind(FILE * fp, int id);

typedef struct locnode_tr{
  struct locnode_tr * next;
  long int bOffset;
  long int rOffset;
  int id;
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
  char ** busarr;
  busnode * treenode;
  
  YelpDataBST * busbst = malloc(sizeof(YelpDataBST));
  bptr = fopen(businesses_path, "r");
  rptr = fopen(reviews_path, "r");
  busoff = ftell(bptr);
  while(fgets(line, 2000,bptr) != NULL){
    busarr = explode(line, "\t");
    treenode = malloc(sizeof(busnode));
    treenode -> name = busarr[1];
    tree_insert(treenode ,busbst -> root);
    locnode * locations = malloc(sizeof(locnode));
    locations -> bOffset = busoff;
    locations -> id = atoi(busarr[0]);
    locations -> rOffset = rofind(rptr, locations -> id);
    busoff = ftell(bptr);
    free();
  }
  
  
}

struct Business* get_business_reviews(struct YelpDataBST* bst,
char* name, char* state, char* zip_code){
  
}

void destroy_business_bst(struct YelpDataBST* bst){
  
}

void destroy_business_result(struct Business* b){
  
}

rofind(FILE * fp, int id){
  char line[2000];
  char ** revarr;
  long int pos = ftell(fp);

  while(fgets(line, 2000, fp)!= NULL){
    revarr = explode(line, "\t");
    if(atoi(revarr[0]) > id){
      fseek(fp, pos, SEEK_SET);
      return -1;
    }
    pos = ftell(fp);
    free();
  }
  return pos;
}

tree_insert(busnode * treenode, busnode * root){
  if(root == NULL){
    return node;
  }
// if(node == NULL){
// return root;
// }
  if(strcasecmp(node -> name, root -> name) < 0){
    root -> left = tree_insert(node, root -> left);
    return root;
  }
  if(strcasecmp(node -> name, root -> name) > 0){
    root -> right = tree_insert(node, root -> right);
    return root;
  }
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
