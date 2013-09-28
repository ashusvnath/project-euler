#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

typedef struct unitary_divisor{
  unsigned long num;
  unsigned int index;
  unsigned int is_prime;
  struct unitary_divisor *next, *prev;
} UD;

UD *make_ud(unsigned long n){
  UD *p;
  p = (UD*)malloc(sizeof(UD));
  p->num = n;
  p->index = 1;
  p->is_prime = TRUE;
  p->next = NULL;
}

unsigned long pow_modn(unsigned long base, unsigned int index, unsigned long n){
  unsigned long ans = 1;
  while(index > 0){
    ans = (ans * base) % n;
    index--;
  }
  return ans;
}

void calculate_index(UD * ptr, unsigned long max){
  unsigned max_index, i, num = ptr->num;
  max_index = (unsigned)floor(log(max)/log(ptr->num));
  /* printf("(%lu)%lu->%u,", max, ptr->num, max_index); */
  for(i = 1 ; i <= max_index ; i++){
    num *= ptr->num;
    ptr->index += (max / num);
    printf("\nptr->i:%u,ptr->n:%lu,max:%lu", ptr->index, ptr->num, max);
  }
  return;
}

int main(int argc, char *argv){
  unsigned long ans = 1,max,i, mod_constant = 1000000009;
  UD *bottom, *trav1, *trav2, *temp, *prev;
  printf("Enter the number whose factorial you want to factorize:");

  scanf("%lu", &max);
  printf("Initializing ..");
  trav1 = bottom = make_ud(2);
  for(i = 3 ; i <= max; i += 2){
    trav1->next = make_ud(i);
    trav1->next->prev = trav1;
    trav1 = trav1->next;
  }
  printf("Done\nFactorizing & calculating .. ");
  calculate_index(bottom, max);
  i = (1 + pow_modn(bottom->num, 2 * bottom->index, mod_constant)) % mod_constant;
  ans = ((ans * i) % mod_constant);
  printf("\n%lu, %u :> %lu :> %lu, ", bottom->num, bottom->index, i, ans);
  trav1 = bottom->next;
  while(trav1 != NULL){
    trav2 = trav1->next;
    prev = trav1;
    while(trav2 != NULL){
      if((trav2->num) % (trav1->num) == 0){
        temp = trav2;
        prev->next = trav2->next;
        trav2 = trav2->next;
        free(temp);
      } else {
        prev = trav2;
        trav2 = trav2->next;
      }
    }
    calculate_index(trav1, max);
    i = (1 + pow_modn(trav1->num, 2 * trav1->index, mod_constant)) % mod_constant;
    ans = ((ans * i) % mod_constant);
    printf("\n%lu, %u :> %lu :> %lu, ", trav1->num, trav1->index, i, ans);
    trav1 = trav1->next;
  }
  printf("\n..Done\n");

  printf("The required answer is %lu\n", ans);
  return 0;
}
