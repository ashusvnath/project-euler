#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

struct __seq_tree_node{
    int start;
    int length;
    struct __seq_tree_node *left,*right;
};


typedef struct __seq_tree_node* NODE;

struct __stack  {
    int n;
    struct __stack *next;
};

typedef struct __stack* STACK; 

