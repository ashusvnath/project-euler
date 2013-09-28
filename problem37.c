#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primes[50000000] = {2, 3, 5, 7};
int last_prime_index = 3;

int is_prime(int i){
  int index = 0;
  int iter_limit;
  if(i == 1)
    return 0;
  iter_limit = (int) floor((double) sqrt(i));
  while(primes[index] != 0 && primes[index] <= iter_limit){
    if (i % primes[index] == 0) return 0;
    index++;
  }
  if(primes[index] > iter_limit){
    last_prime_index++;
    primes[last_prime_index] = i;
    return 1;
  }
  return 0;
}

int is_both_ways_truncatable(int i){
  int left, right;
  int iter = 1, mask = 1;
  int len;
  if(!is_prime(i)) return 0;
  len = (int) floor(log10(i)) + 1;
  while(iter < len){
    mask *= 10;
    left = i % mask;
    right = i / mask;
    if(right == 0 || left == 0){
      printf("Serious bug in logic: i: %d, mask: %d, left: %d, right :%d \n", i, mask, left, right);
      exit(0);
    }
    if(!is_prime(left) || !is_prime(right)) return 0;
    iter++;
  }
  return 1;
}

int main(int argc, char *argv[]){
  int i;
  int sum = 0;
  int found = 0;
  for(i = 9 ; i < 1000000000 ; i += 2) {
    if(is_both_ways_truncatable(i)) {
      sum += i;
      found ++;
      if(found == 11)
        break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
