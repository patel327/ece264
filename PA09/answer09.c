#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

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
  
}

BusinessNode *
load_tree_from_file(char * filename){
  
}

BusinessNode *
tree_search_name(char * name, BusinessNode * root){
  
}

void
destroy_tree(BusinessNode * root){
  
}
