#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer10.h"


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

busnode * tree_insert(busnode * treenode, busnode * root);
char ** explode(const char * str, const char * delims/*, int * arrLen*/);
long int rofind(FILE * fp, int id);
void bussort(Business * object, char * state, char * zip_code, locnode * node, YelpDataBST * bst);
int getrevnum( YelpDataBST * bst, locnode * node);
locnode * tree_search_name(char * name, busnode * root);

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
  busbst -> busptr = bptr;
  busbst -> revptr = rptr;
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
    free(busarr[0]);
    free(busarr[1]);
    free(busarr[2]);
    free(busarr[3]);
    free(busarr[4]);
    free(busarr[5]);
    free(busarr[6]);
    free(busarr);
  }
  //fclose(busbst -> revptr);
  //fclose(busbst -> busptr);
  return busbst;
  
}

struct Business* get_business_reviews(struct YelpDataBST* bst,
char* name, char* state, char* zip_code){
  struct Business * busob = malloc(sizeof(Business));
  busob -> name = name;
  locnode * node = tree_search_name(name, bst -> root);
  bussort(busob, state, zip_code, node, bst);
  
  
}

void destroy_business_bst(struct YelpDataBST* bst){
  
}

void destroy_business_result(struct Business* b){
  
}

void bussort(Business * object, char * state, char * zip_code, locnode * node, YelpDataBST * bst){
  object -> num_locations = 0;
  locnode* curr = node;
  while(curr -> next != NULL){
    curr = curr -> next;
    object -> num_locations += 1;
  }
  fseek(bst -> busptr, node -> bOffset, SEEK_SET);
  object -> locations = malloc(sizeof(Location));
  for(int i = 0; i < (object -> num_locations); i++){
  
  char mystring[2000] = "";  
  fgets(mystring, 2000, bst -> busptr);
  char** busarr = explode(mystring, "\t");
  object -> locations[i] -> address = malloc(sizeof(char));
  object -> locations[i] -> city = malloc(sizeof(char));
  object -> locations[i] -> state = malloc(sizeof(char));
  object -> locations[i] -> zip_code = malloc(sizeof(char));
  object -> locations[i] -> address = busarr[2];
  object -> locations[i] -> city = busarr[3];
  object -> locations[i] -> state = busarr[4];
  object -> locations[i] -> zip_code = busarr[5];
  free(busarr[0]);
  free(busarr[1]);
  free(busarr[2]);
  free(busarr[3]);
  free(busarr[4]);
  free(busarr[5]);
  free(busarr[6]);
  free(busarr);
  object -> num_reviews = getrevnum(bst, node);
  object -> location -> reviews = malloc(sizeof(Review));
  fseek(bst -> revptr, node -> rOffset, SEEK_SET);
  for(j=0; j < (object -> num_reviews); j++){
    char mystring2[20000] = "";
    fgets(mystring2, 20000, bus ->revptr);
    char** revarr = explode(mystring2, "\t")
    object -> locations -> reviews[j] -> text = malloc(sizeof(char));
    object -> locations -> reviews[j] -> stars = atoi(revarr[1]);
    object -> locations -> reviews[j] -> text = revarr[5];
    free(revarr[0]);
    free(revarr[1]);
    free(revarr[2]);
    free(revarr[3]);
    free(revarr[4]);
    free(revarr[5]);
    free(revarr); 
  }
  
  }
}

int getrevnum( YelpDataBST * bst, locnode * node){
  int num = 0;
  fseek(bst -> revptr, node -> rOffset, SEEK_SET);
  while(1){
    char ** revarr;
    char mystring[20000];
    fgets(mystring, 20000, bst-> revptr);
    revarr = explode(mystring, "\t");
    if(bst -> root -> head -> id == atoi(revarr[0])){
      num++;
    }
    if(bst -> root -> head -> id != atoi(revarr[0])){
      free(revarr[0]);
      free(revarr[1]);
      free(revarr[2]);
      free(revarr[3]);
      free(revarr[4]);
      free(revarr[5]);
      free(revarr); 
      return num;
    }    
    free(revarr[0]);
    free(revarr[1]);
    free(revarr[2]);
    free(revarr[3]);
    free(revarr[4]);
    free(revarr[5]);
    free(revarr);    
  }
  return 0;
}

locnode * tree_search_name(char * name, busnode * root){
  if(root == NULL){
    return NULL;
  }
  if((strcasecmp(name, root -> name)) == 0){
    return root -> head;
  }
  if((strcasecmp(name, root -> name)) > 0){
    root -> head = tree_search_name(name, root -> right);
    return root -> head;
  }
  //if((strcasecmp(name, root -> left)) < 0){
    root -> head = tree_search_name(name, root -> left);
    return root -> head;
  //}
}

long int rofind(FILE * fp, int id){
  char line[20000];
  char ** revarr;
  long int pos = ftell(fp);

  while(fgets(line, 20000, fp)!= NULL){
    revarr = explode(line, "\t");
    if(atoi(revarr[0]) == id){
      free(revarr[0]);
      free(revarr[1]);
      free(revarr[2]);
      free(revarr[3]);
      free(revarr[4]);
      free(revarr[5]);
      free(revarr);      
      return pos;
    }
    if(atoi(revarr[0]) > id){
      fseek(fp, pos, SEEK_SET);
      free(revarr[0]);
      free(revarr[1]);
      free(revarr[2]);
      free(revarr[3]);
      free(revarr[4]);
      free(revarr[5]);
      free(revarr);
      return -1;
    }
    pos = ftell(fp);

  }
  return -1;
}

busnode * tree_insert(busnode * treenode, busnode * root){
  if(root == NULL){
    return treenode;
  }
// if(node == NULL){
// return root;
// }
  if(strcasecmp(treenode -> name, root -> name) < 0){
    root -> left = tree_insert(treenode, root -> left);
    return root;
  }
  if(strcasecmp(treenode -> name, root -> name) > 0){
    root -> right = tree_insert(treenode, root -> right);
    return root;
  }
  //if(strcasecmp(treenode -> name, root -> name) == 0){
    locnode * curr = root -> head;
    while(curr -> next != NULL){
      curr = curr-> next;
    }
    curr -> next = treenode -> head;
    return root;
  //}
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
