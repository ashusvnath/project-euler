#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIST_SIZE 9999

unsigned long prime_list[LIST_SIZE];
unsigned int prime_list_top;
unsigned long digits[10000] = {0};
short int same_digits_array[10000];

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

unsigned int is_prime(unsigned long n){
  unsigned int i;
  for(i=0;i<=prime_list_top && prime_list[i] < n;i++)
    if(n%prime_list[i]==0) return 0;
  push(n);
  return 1;
}

void find_all_primes_upto(unsigned long n){
  unsigned long i;
  for(i=prime_list[prime_list_top] + 2; i<=n; i+=2)
    is_prime(i);
}

unsigned long digits_of_number(unsigned long n){
  int i = 0;
  unsigned long num = n, hash = 0;
  while(n>0){ hash |= (1<<(n%10)); n = n/10; }
  digits[num]=hash;
  return hash;
}

int main(int argc, char *argv[]){
  unsigned long j;
  unsigned long prime0 = 0 , prime1 = 0, prime2 = 0;
  unsigned long digits_hash0 = 0, digits_hash1 = 0, digits_hash2 = 0;
  unsigned long temp_num;
  int found = 0;
	initialize_prime_list();
  j = 0;
  find_all_primes_upto(10000);
  while(prime_list[j] + 6660 <= 9999){
    prime0 = 0 , prime1 = 0, prime2 = 0;
    digits_hash0 = 0, digits_hash1 = 0, digits_hash2 = 0;
    /* if(j%1==0){ */
    /*   printf(".j = %lu \n", j); */
    /*   printf("Primes %4lu %4lu %4lu\n", prime0, prime1, prime2); */
    /*   printf("Hashes %lx %lx %lx\n", digits_hash0, digits_hash1, digits_hash2); */
    /* } */
    prime0 = prime_list[j];
    prime1 = prime0 + 3330;
    prime2 = prime0 + 6660;
    digits_hash0 = digits_of_number(prime0);
    digits_hash1 = digits_of_number(prime1);
    digits_hash2 = digits_of_number(prime2);
    if (is_prime(prime0) && is_prime(prime1) && is_prime(prime2)){
      if((digits_hash0 == digits_hash1) && (digits_hash0 == digits_hash2)){
        printf("%lu, %lu",j , prime0);
        printf("Sequence %4lu%4lu%4lu\n", prime0, prime1, prime2);
        found++;
      }
    }
    j++;
  }
  return 0;
}
