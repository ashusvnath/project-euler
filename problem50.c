#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_SIZE 1000000

unsigned long prime_list[LIST_SIZE];
unsigned long prime_sum_list[LIST_SIZE] = {0}, max = 0;
unsigned int prime_list_top=0;
unsigned int mark = 0;

void initialize_prime_lists(){
  prime_list[0]=2;prime_list[1]=3; prime_list[2]=5;prime_list[3]=7;
  prime_sum_list[0]=2;prime_sum_list[1]=5; prime_sum_list[2]=10;prime_sum_list[3]=17;
  prime_list_top=3;
  return;
}

void push(unsigned long n){
  prime_list_top++;
  prime_list[prime_list_top] = n;
  prime_sum_list[prime_list_top] = prime_sum_list[prime_list_top-1] + n;
  if(!mark && prime_sum_list[prime_list_top]> max) mark = prime_list_top;
}

unsigned int is_prime(unsigned long n){
  unsigned int i;
  for(i=0;i<=prime_list_top && prime_list[i] < n;i++)
    if(n%prime_list[i]==0) return 0;
  push(n);
  return 1;
}

void find_all_primes_upto(unsigned long n){
  unsigned long i;
  for(i=prime_list[prime_list_top] + 2; prime_list[prime_list_top]<=n; i+=2){
    is_prime(i);
  }
}

unsigned int search_tree(unsigned long candidate){
  unsigned start, end, mid;
  unsigned count;
  count = 0;
  start = 0;
  end = prime_list_top - 1;
  mid = 0;
  while(start<=end){
    mid = (start + end)/2;
    if(candidate == prime_list[mid]) return 1;
    else if(candidate > prime_list[mid]) start = mid+1;
    else end = mid-1;
    count++;
  }
  return 0;
}

void print_primes(){
  unsigned i;
  for(i=0;i<prime_list_top; i++)
    printf("%6lu ", prime_list[i]);
  printf("\n");
  for(i=0;i<prime_list_top; i++)
    printf("%6lu ", prime_sum_list[i]);
  printf("\n");
}

int main(int argc, char *argv[]){
  int i, start_i, end_i;
  unsigned max_length = 1, length_difference = 0;
  int max_end_i = 0, max_start_i = 0;
  unsigned long prime_sum_difference = 0;
  initialize_prime_lists();
  printf("Enter upper limit for search: ");
  scanf("%lu", &max);
  find_all_primes_upto(max);
  printf("Highest prime so far: %lu\n", prime_list[prime_list_top]);
  printf("Highest prime sum so far: %lu\n", prime_sum_list[prime_list_top]);
  /* print_primes(); */
  printf("Max is %lu", max);
  for(end_i = prime_list_top; end_i > 0; end_i--){
    for(start_i = 0;(end_i - start_i + 1) > max_length; start_i++){
      length_difference = end_i - start_i + 1;
      prime_sum_difference = (prime_sum_list[end_i] - prime_sum_list[start_i]) + prime_list[start_i];
      if(length_difference > max_length && prime_sum_difference < max && search_tree(prime_sum_difference)){
          /* printf("\ns:%u e:%u len_diff:%u prime_sum_diff:%lu",start_i, end_i, length_difference, prime_sum_difference); */
          if(max_length < length_difference){
            max_length = length_difference; max_end_i = end_i; max_start_i = start_i;
          }
      }
    }
  }
  printf("\nMAX::start:%u, length:%u, sum_diff:%lu", max_start_i, max_end_i - max_start_i + 1, prime_sum_list[max_end_i] - prime_sum_list[max_start_i] + prime_list[max_start_i]);
  printf("\n");
  return 0;
}
