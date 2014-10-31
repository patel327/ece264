#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

int comparefs(const void *arg1, const void *arg2);
List * List_merge(List * lhs, List * rhs, comparefs);
int List_length(List * list);

List * List_createNode(const char * str){
  List * head = malloc(sizeof(List));
  head -> next = NULL;
  head -> str = strdup(str)
  
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
  while(list -> nest != NULL){
    counter++;
    list = list.next;
  }
  return counter;
}

List * List_merge(List * lhs, List * rhs, comparefs){
  List* newlist = NULL;
  while(lhs != NULL && rhs != NULL){
    int determine = comparefs(lhs -> str, rhs -> str);
    if(determine >= 0){
      newlist -> str = lhs -> str;
      lhs = lhs->next;
    }
    else{
      newlist -> str = rhs -> str
      rhs = rhs -> next
    }
    newlist -> next = NULL;
  }
  while(lhs != NULL){
    newlist -> str = lhs -> str;
    lhs = lhs -> next;
    newlist -> next = NULL;
  }
  while(rhs != NULL){
    newlist -> str = rhs -> str;
    rhs = rhs -> next;
    newlist -> next = NULL;
  }
  return newlist;
}

List * List_sort(List * list, comparefs){
  if(List_length(list) <= 1){
    return list;
  }
  
}

int comparefs(const void *arg1, const void *arg2)
{
  const char * const * ptr1 = (const char **) arg1;
  const char * const * ptr2 = (const char **) arg2;
  const char * str1 = * ptr1;
  const char * str2 = * ptr2;
  return(strcmp(str1, str2));
}
