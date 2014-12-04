#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer11.h"

int readBit(FILE * fptr, unsigned char * bit, unsigned char * whichbit, unsigned char * curbyte);
HuffNode * HuffNode_create(int value);
void Stack_popPopCombinePush(Stack * stack);
Stack * Stack_create();
HuffNode * Stack_popFront(Stack * stack);
void Stack_pushFront(Stack * stack, HuffNode * tree);

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
  newstack -> head = NULL;
  return newstack;
}

void Stack_destroy(Stack * stack){
  if(stack == NULL){
    return;
  }
  while(stack -> head != NULL){
  StackNode * temp = stack->head->next;
  HuffNode_destroy(stack -> head -> tree);
  free(stack -> head);
  stack -> head = temp;
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
  StackNode * tempstack = stack -> head -> next;
  //tempstack = stack -> head -> next;
  //stack -> head -> next = NULL;
  free(stack -> head);
  stack -> head = tempstack;
  return(tempnode);
}

void Stack_pushFront(Stack * stack, HuffNode * tree){
  StackNode * node = malloc(sizeof(StackNode));
  node -> tree = tree;
  node -> next = stack -> head;
  stack -> head = node;
}

void Stack_popPopCombinePush(Stack * stack){
  HuffNode * pop1 = Stack_popFront(stack);
  HuffNode * pop2 = Stack_popFront(stack);
  HuffNode * combine = HuffNode_create(1);
  combine -> right = pop1;
  combine -> left = pop2;
  //combine -> value = NULL;
  Stack_pushFront(stack, combine);
}

HuffNode * HuffTree_readTextHeader(FILE * fp){
  HuffNode * tree;
  Stack * stack = Stack_create();
  char num;
  while(1){
    num = fgetc(fp);
    if(num == '1'){
      tree = HuffNode_create(fgetc(fp));
      Stack_pushFront(stack, tree);
    }
    if(num =='0'){

      if(stack->head->next == NULL){
      tree = Stack_popFront(stack);
      Stack_destroy(stack);
        return tree;}
      Stack_popPopCombinePush(stack);
    }
    
  }
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp){ //FROM PROFESSOR LU'S BOOK
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  unsigned char onebit = 0;
  //StackNode * head = NULL;
  HuffNode * tn;
  Stack * ln = Stack_create();
  while(done == 0)
  {
    readBit(fp, &onebit, &whichbit, &curbyte);
    if (onebit == 1){
      int bitcount;
      unsigned char value = 0;
      for (bitcount = 0; bitcount <8; bitcount ++)
      {
        value <<= 1;
        readBit(fp, &onebit, &whichbit, &curbyte);
        value |= onebit;
      }
      tn = HuffNode_create(value);
      //ln = Stack_create();
      Stack_pushFront(ln, tn);
    }
    else{
      if(ln -> head -> next == NULL){
        done = 1;
      }
      else{
        Stack_popPopCombinePush(ln);
      }
    }
  }
  HuffNode * root = ln -> head -> tree;
  free(ln -> head);
  free(ln);
  return root;
}

int readBit(FILE * fptr, unsigned char * bit, unsigned char * whichbit, unsigned char * curbyte){ //FROM PROFESSOR LU'S BOOK
  int ret = 1;
  if((*whichbit) == 0){
    ret = fread(curbyte, sizeof(unsigned char), 1 ,fptr);
  }
  if(ret != 1){
    return -1;
  }
  unsigned char temp = (*curbyte) >> (7 - (*whichbit));
  temp = temp & 0X01;
  *whichbit = ((*whichbit) + 1) % 8;
  *bit = temp;
  return 1;
}
