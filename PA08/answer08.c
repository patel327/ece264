#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

List * List_createNode(const char * str){
  List * head = malloc(sizeof(List));
  head -> next = NULL;
  head -> str = strdup(str)
  
  return head;
}
