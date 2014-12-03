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
  HuffNode * ascchar;
  Stack * stack = Stack_create();
  int num = 0;
  while(num != EOF){
    num = fgetc(fp);
    if(num == 1){
      ascchar = HuffNode_create(fgetc(fp));
      Stack_pushFront(stack, ascchar);
    }
    if(num ==0){
      Stack_popPopCombinePush(stack);
      if(stack->head->next == NULL){
        free(stack -> head);
        free(stack);
        return ascchar;}
    }
  }
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp){
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  unsigned char onebit = 0;
  StackNode * head = NULL;
  HuffNode * tn;
  Stack * ln;
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
      ln = Stack_create();
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

int readBit(FILE * fptr, unsigned char * bit, unsigned char * whichbit, unsigned char * curbyte){
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
