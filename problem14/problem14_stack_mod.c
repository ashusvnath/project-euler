#include "problem14.h"

STACK top;

void __init_stack(){
    top=NULL;
    printf("Initialized stack\n");
}

void push(unsigned int n, unsigned int diff){
    STACK trav,temp;
    temp = (STACK)malloc(sizeof(struct __stack));
    temp->n = n;
    temp->diff = diff;
    temp->next = NULL;
    
    if(top==NULL) { top = temp; return; }
    trav = top;
    while(trav->next != NULL) 
        trav = trav->next;
    trav->next = temp;
}

unsigned int pop(unsigned int* start, unsigned int* length, unsigned int sequence_length){
   unsigned int calc_len;
   STACK temp;
   if(top==NULL) { *start = *length = -1; return 0; }
   temp = top; top = top->next;
   *start = temp->n;
   *length = calc_len = sequence_length - temp->diff;
   if(calc_len<0) {printf("Oops, calculated length < 0 : %u, %u, %u",start,temp->diff,sequence_length); exit(-1);}
   free(temp);
   return calc_len;
}
