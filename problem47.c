#include<stdio.h>
#include<stdlib.h>
#define list_SIZE 10000000

unsigned long prime_list[list_SIZE];
unsigned int prime_list_top;

void initialize_prime_list(){
  prime_list[0]=2;prime_list[1]=3; prime_list[2]=5;prime_list[3]=7;
  prime_list_top=3;
}

void push(unsigned long n){
  prime_list_top++;
  prime_list[prime_list_top]=n;
}

unsigned long prime_list_contains(unsigned int n){
  unsigned int i;
  if(n>prime_list[prime_list_top]) return 0;
  for(i=0;i<=prime_list_top;i++)
    if(prime_list[i]==n) return 1;
  return 0;
}

unsigned int isprime(unsigned long n){
  unsigned int i;
  for(i=0;i<=prime_list_top;i++)
    if(n%prime_list[i]==0) return 0;
  push(n);
  return 1;
}

void find_all_primes_upto(unsigned long n){
  unsigned long i;
  for(i=prime_list[prime_list_top] + 2; i<=n; i+=2)
    isprime(i);
}

void prime_factorize(unsigned long n, unsigned long *prime_factors,
    unsigned long *prime_factor_powers, unsigned long *num_prime_factors){

	unsigned int i, index;
  unsigned long pow, k;
  /* printf("\nn:%lu = ",n); */
	index = 0;
	for(i = 0; n > 1 ; i++){
		if(i > prime_list_top) find_all_primes_upto(n);
		k = prime_list[i];
		if(n % k == 0){
			prime_factors[index] = k;
			/* printf("%lu^",k); */
      pow = 0;
      while(n % k == 0){ n = n/k; pow++; }
      prime_factor_powers[index] = pow;
      /* printf("%lu*",pow); */
			index++;
		}
	}
  /* printf(" -- num_factors:%u",index); */
	*num_prime_factors = index;
	return;
}

void reinitialize(unsigned long factors[3][100], unsigned long powers[3][100], unsigned long number_of_factors[3]){
  int i,j;
  for(i=0;i<3;i++){
    number_of_factors[i]=0;
    for(j=0;j<4;j++)
      factors[i][j]=powers[i][j]=0;
  }
}

int main(int argc, char *argv[]){
  unsigned int j,k;
  unsigned long i;
  unsigned long factors[4][100] = {0}, powers[4][100] = {0}, number_of_factors[4] = {0};
	initialize_prime_list();
	find_all_primes_upto(1000);
  i = 646;
  while(1) {
    i++;
    for(k=0;k<4;k++){
      prime_factorize(i+k, factors[k], powers[k], &number_of_factors[k]);
      if(number_of_factors[k] != 4) break;
    }
    if(k==4){
      for(k = 0 ; k < 4 ; k++){
        printf("\n%lu = ", i + k);
        for(j = 0 ; j < 4 ; j++){
          printf("(%lu ^ %lu) * ", factors[k][j], powers[k][j]);
        }
      }
      printf("\nThe numbers are %lu %lu %lu %lu\n", i, i + 1, i + 2, i + 3);
      break;
    }
  }
  return 0;
}
