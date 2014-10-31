#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

int compar(const char *arg1, const char *arg2);
List * List_merge(List * lhs, List * rhs, int (*compar)(const char *arg1, const char *arg2));
int List_length(List * list);

List * List_createNode(const char * str){
  List * head = malloc(sizeof(List));
  head -> next = NULL;
  head -> str = strdup(str);
  
  return head;
}

void List_destroy(List * list){
  while(list != NULL){
    List* newhead = list -> next;
    free(list -> str);
    free(list);
    list = newhead;
  }
}

int List_length(List * list){
  if(list == NULL){
    return 0;
  }
  int counter = 1;
  while(list -> next != NULL){
    counter++;
    list = list->next;
  }
  return counter;
}

List * List_merge(List * lhs, List * rhs,int (*compar)(const char *arg1, const char *arg2)){
  List* newlist = NULL;
  while(lhs != NULL && rhs != NULL){
    int determine = (*compar)(lhs -> str, rhs -> str);
    if(determine >= 0){
      newlist -> next = lhs -> str;
      lhs = lhs->next;
    }
    else{
      newlist -> next = rhs -> str;
      rhs = rhs -> next;
    }
    //newlist -> next = NULL;
  }
  while(lhs != NULL){
    newlist -> next = lhs -> str;
    lhs = lhs -> next;
    //newlist -> next = NULL;
  }
  while(rhs != NULL){
    newlist -> next = rhs -> str ;
    rhs = rhs -> next;
    //newlist -> next = NULL;
  }
  newlist -> next = NULL;
  return newlist;
}

List * List_sort(List * list,int (*compar)(const char *arg1, const char *arg2)){
  if(List_length(list) <= 1){
    return list;
  }
  
}

int compar(const char *arg1, const char *arg2)
{
  const char * const * ptr1 = (const char **) arg1;
  const char * const * ptr2 = (const char **) arg2;
  const char * str1 = * ptr1;
  const char * str2 = * ptr2;
  return(strcmp(str1, str2));
}
