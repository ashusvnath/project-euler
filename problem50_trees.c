#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_SIZE 1000000

typedef struct prime_struct {
  unsigned long prime;
  unsigned long prime_sum;
  struct prime_struct *next, *prev;
  struct prime_struct *left, *right;
  unsigned int left_depth, right_depth;
} PRIME;

PRIME* make_new(){
  PRIME *new;
  new = (PRIME *) malloc(sizeof(PRIME));
  new->left = new->right = NULL;
  new->prev = new->next = NULL;
  new->left_depth = new->right_depth = 0;
  return new;
}

void push(unsigned long prime, PRIME** top, PRIME** bottom){
  PRIME *new;
  new = (PRIME *) malloc(sizeof(PRIME));
  new->prime = prime;
  if(*top != NULL){
    new->prime_sum = (*top)->prime_sum + prime;
    (*top)->prev = new;
  }else{
    new->prime_sum = prime;
    *bottom = new;
  }
  new->next = *top;
  *top = new;
  printf("%p(%lu, %lu) ",*top, (*top)->prime, (*top)->prime_sum);
}

void initialize(PRIME** top, PRIME** bottom){
  push(2, top, bottom);
}

int is_prime(unsigned long prime_candidate, PRIME** base_top, PRIME** base_bottom){
  PRIME *top, *bottom;
  top = *base_top;
  bottom = *base_bottom;
  while(top || bottom || top != bottom){
    if(top->prev != bottom) break;
    if(top){
      if(prime_candidate % top->prime == 0) return 0;
      else top = top->next;
    }
    if(bottom){
      if(prime_candidate % bottom->prime == 0) return 0;
      else bottom = bottom-> prev;
    }
  }
  push(prime_candidate, base_top, base_bottom);
  return 1;
}

void insert_into_tree(PRIME* element, PRIME* root){
  PRIME *current;
  /* if(element->prime < 500000) return; */
  if(root == NULL){
    root = element;
    return;
  }
  current = root;
  while(1){
    if(current->prime > element->prime){
      if(current->left == NULL){
        current->left = element;
        current->left_depth = 1;
        break;
      } else {
        current->left_depth += 1;
        current = current->left;
      }
    } else {
      if(current->right == NULL){
        current->right = element;
        current->right_depth = 1;
        break;
      } else {
        current->right_depth += 1;
        current = current->right;
      }
    }
  }
  return;
}

int main(int argc, char *argv[]){
  PRIME* top = NULL;
  PRIME* bottom = NULL;
  PRIME* root = NULL;
  PRIME* mid = NULL;
  unsigned long prime_candidate = 3;
  initialize(&top, &bottom);
  while(prime_candidate < 1000000){
    sleep(2);
    is_prime(prime_candidate, &top, &bottom);
    prime_candidate += 2;
  }
  while(top){
    printf("%lu ", top->prime);
    top = top->next;
  }
  printf("\n");
  return 0;
}
