#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

struct __seq_tree_node{
    unsigned int start;
    unsigned int length;
    struct __seq_tree_node *left,*right;
};

typedef struct __seq_tree_node* NODE;

struct __stack  {
    unsigned int n;
    unsigned int diff;
    struct __stack *next;
};

typedef struct __stack* STACK;
