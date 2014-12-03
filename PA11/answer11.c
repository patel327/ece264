#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer11.h"

HuffNode * HuffNode_create(int value){
  HuffNode * node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

void HuffNode_destroy(HuffNode * tree){
  if(tree == NULL){
    return;
  }
  HuffNode_destroy(tree -> left);
  HuffNode_destroy(tree -> right);
  free(tree);
}

Stack * Stack_create(){
  Stack * newstack = malloc(sizeof(Stack));
  newstack -> head = malloc(sizeof(StackNode));
  newstack -> head -> tree = NULL;
  newstack -> head -> next = NULL;
  return newstack;
}

void Stack_destroy(Stack * stack){
  if(stack == NULL){
    return;
  }
  while(stack -> head != NULL){
  HuffNode_destroy(stack -> head -> tree);
  stack -> head = stack -> head -> next;
  free(stack -> head);
  }
  free(stack);
}

int Stack_isEmpty(Stack * stack){
  if (stack == NULL){
    return 1;
  }
  return 0;
}

HuffNode * Stack_popFront(Stack * stack){
  HuffNode * tempnode = stack -> head -> tree;
  Stack * tempstack = NULL;
  tempstack -> head = stack -> head -> next;
  stack -> head -> next = NULL;
  free(stack -> head);
  stack -> head = tempstack -> head;
  return(tempnode);
}

void Stack_pushFront(Stack * stack, HuffNode * tree){
  StackNode * node = malloc(sizeof(StackNode));
  node -> tree = tree;
  node -> next = stack -> head;
}

void Stack_popPopCombinePush(Stack * stack){
  HuffNode * pop1 = Stack_popFront(stack);
  HuffNode * pop2 = Stack_popFront(stack);
  HuffNode * combine = HuffNode_create(1);
  combine -> left = pop1;
  combine -> right = pop2;
  //combine -> value = NULL;
  Stack_pushFront(stack, combine);
}

HuffNode * HuffTree_readTextHeader(FILE * fp){
  
  return;
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp){
  return;
}
