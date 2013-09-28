#include<stdio.h>
#include<math.h>

#define LIST_SIZE 1000000
int prime_list[LIST_SIZE],number_of_odd_primes;

void initialize_prime_list(){
  prime_list[0]=2;prime_list[1]=3;
  prime_list[2]=5;prime_list[3]=7;
  number_of_odd_primes=3;
}

void add_to_primes_list(int n){
  number_of_odd_primes++;
  prime_list[number_of_odd_primes]=n;
}

int prime_list_contains(int n, int index_hint){
  int i;
  if(n>prime_list[number_of_odd_primes]) return 0;
  for(i=index_hint;i<=number_of_odd_primes && n >= prime_list[i];i++){
    if(prime_list[i]==n) return i;
  }
  return 0;
}

int isprime(int n){
  int i;
  for(i=1;i<=number_of_odd_primes;i++)
    if(n%prime_list[i]==0) return 0;
  add_to_primes_list(n);
  return 1;
}

void find_all_primes_upto(int n){
  int i;
  for(i=prime_list[number_of_odd_primes] + 2; i<=n; i+=2)
    isprime(i);
}

int is_goldbach(int num){
  int square, squrt, indx=1;
  int num_less_prime;
  while(num > prime_list[indx]){
    num_less_prime = num - prime_list[indx];
    square = num_less_prime / 2;
    squrt = (int)floor(sqrt(square));
    if(squrt*squrt == square){
       /* printf("\n%d = %d + 2 * %d ^ 2", num, prime_list[indx], squrt); */
       return 1;
    }
    indx++;
  }
  return 0;
}

int get_next_composite_odd_number(composite_odd_number){
  int index_hint = 1;
  do{
    composite_odd_number += 2;
  }while(index_hint = prime_list_contains(composite_odd_number, index_hint));
  return composite_odd_number;
}

int main(int argc, char *argv[]){
  int composite_odd_number=9;
  initialize_prime_list();
  while(1){
    if(composite_odd_number > prime_list[number_of_odd_primes])
      find_all_primes_upto(10*composite_odd_number);
    if(is_goldbach(composite_odd_number)) {
      composite_odd_number = get_next_composite_odd_number(composite_odd_number);
    }
    else{
      printf("\n%d is a non goldbach composite number", composite_odd_number);
      break;
    }
  }
  return 0;
}
