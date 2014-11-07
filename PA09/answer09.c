#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

char ** explode(const char * str, const char * delims, int * arrLen);
BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root);
BusinessNode * create_node(char * stars, char * name, char * address);

BusinessNode *
create_node(char * stars, char * name, char * address){
  BusinessNode * node;
  node = malloc(sizeof(BusinessNode));
  node -> left = NULL;
  node -> right = NULL;
  node -> name = NULL;
  node -> stars = NULL;
  node -> address = NULL;
  return node;
}

BusinessNode *
tree_insert(BusinessNode * node, BusinessNode * root){
  if(root == NULL){
    return node;
  }
  if(strcmp(node -> name, root -> name) == -1 || strcmp(node -> name, root -> name == 0)){
    tree_insert(node, root -> left);
    return root;
  }
  tree_insert(node, root -> right);
  return root;
}

BusinessNode *
load_tree_from_file(char * filename){
  if(filename != "yelp_businesses.tsv"){
    return NULL;
  }
}

BusinessNode *
tree_search_name(char * name, BusinessNode * root){
  
}

void
destroy_tree(BusinessNode * root){
  
}


char ** explode(const char * str, const char * delims, int * arrLen)
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
  *arrLen = N + 1;
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
