#include <stdio.h>
#include <math.h>

#define MAX 999999

int ODD_DIGITS[] = {1, 3, 7, 9};
int all_circular_primes[6][5000] = {{2,5}};
int indx[6] = {2,0};

int is_prime(int i){
  int j, k;
  if(i == 1) return 0;
  k = sqrt(i);
  for(j = 3 ; j <= k ; j += 2)
    if(i % j == 0) return 0;
  return 1;
}

int mypow(int i, int j){
  int ans = 1;
  while( j -- > 0)
    ans *= i;
  return ans;
}

int find(int *arr, int k, int l){
  int i;
  for(i = 0; i < indx[l]; i ++)
    if(all_circular_primes[l][i]==k) return 1;
  return 0;
}

int is_circular_prime(int n, int c){
  int circular_primes[c],k;
  int highest_place;
  k = c;
  if(find(all_circular_primes[c], n, c)) return 0;
  highest_place = mypow(10, c - 1);
  int digit;
  do{
    if(is_prime(n) == 0)
      return 0;
    circular_primes[c-1] = n;
    digit = n%10;
    n = (digit*highest_place) + (n/10);
    c --;
  }while(c > 0);
  c = k;
  return 1;
}

int main(int argc, char *argv[]){
  int i,j,s,t;
  int num, iters;
  int num_circular_primes = 2;
  for(i = 1 ; i <= 6 ; i++){
    iters = mypow(4, i);
    for(j = 0 ; j < iters ; j++){
      s = i;
      t = j;
      num = 0;
      do{
        num *= 10;
        num += ODD_DIGITS[t%4];
        t /= 4;
        s--;
      }while(s > 0);
      if(is_circular_prime(num, i)) num_circular_primes += i;
    }
    for(s=0; s<indx[i-1]; s++)
      printf("%d\n", all_circular_primes[i-1][s]);
  }
  printf("%d", num_circular_primes);
}
