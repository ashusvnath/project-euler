#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 1000000

long prime_stack[STACK_SIZE];
int prime_stack_top;

void initialize_prime_stack(){
    prime_stack[0]=2;prime_stack[1]=3;
    prime_stack[2]=5;prime_stack[3]=7;
    prime_stack_top=3;
}

void push(long n){
    prime_stack_top++;    
    prime_stack[prime_stack_top]=n;
}

long prime_stack_contains(int n){
    int i;
    if(n>prime_stack[prime_stack_top]) return 0;
    for(i=0;i<=prime_stack_top;i++)
        if(prime_stack[i]==n) return 1;
    return 0;
}

int isprime(long n){
    int i;
    for(i=0;i<=prime_stack_top;i++)
        if(n%prime_stack[i]==0) return 0;
    push(n);
    return 1;
}

void find_all_primes_upto(long n){
    long i;
    for(i=prime_stack[prime_stack_top]; i<=n; i+=2)
       isprime(i);
}

int* factorize(long n,int *num_factors){
	int i,count,k;
	int *factors;
	factors=(int*)malloc(sizeof(int)*n);
	count=-1;
	for(i=0;n>1;i++){
		if(i>prime_stack_top) find_all_primes_upto(n);
		k=prime_stack[i];
		if(n%k==0){
			count++;
			factors[count]=k;
			while(n%k==0)
				n=n/k;
		}			
	}
	*num_factors=count;
	return factors;
}

int main(int argc, char *argv[]){
	int i;
	initialize_prime_stack();
	find_all_primes_upto(1000);
	//for(i=0;i<prime_stack_top;i++)
	printf("%ld\n",prime_stack[prime_stack_top]);
	//printf("\n");
	return 0;
}
