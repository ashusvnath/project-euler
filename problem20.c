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
	//printf("Finding primes upto %ld\n",n);
    for(i=prime_stack[prime_stack_top]; i<=n; i+=2)
       isprime(i);
}

long get_sum_of_proper_divisors(long n){
	long prime_div_highest_power[STACK_SIZE]={0};
    long temp,num_div,num_to_inspect;
	long prod_numerator = 1 ,prod_denominator = 1;
    long count = 0, sum = 1, prod = 0;
    int i=0;
    if(n==1||prime_stack_contains(n)) return sum;
	temp = n;
	for(i = 0; temp>1; i++){
		if(i > prime_stack_top) find_all_primes_upto(temp);
		num_to_inspect = prime_stack[i];
		if(temp%num_to_inspect == 0)
		{
			//printf("%ld divides %ld",num_to_inspect,n);
			prod = 1;
			sum = 1;
			count = 0;
			while(temp % num_to_inspect == 0){
				temp = temp / num_to_inspect;
				prod *= num_to_inspect;
				sum += prod;
				count++;
			}
			//printf(" %ld times\n",count);
			prime_div_highest_power[i] = sum;
		}
	}
	prod_numerator=1;
	prod_denominator=1;
	for(;i>=0;i--){
		if(prime_div_highest_power[i]<=1) continue;
		prod_numerator *= prime_div_highest_power[i];
	}
	sum	= prod_numerator -n;
	//printf("Sum of proper divisors of %ld is %ld\n",n,sum);
	return sum;
}

long get_amicable_sum(long n){
	long amicable_pair;
	amicable_pair = get_sum_of_proper_divisors(n);
	if(amicable_pair<0) {printf("Error occured while calculating sum of divisors of %ld (%ld)\n",n,amicable_pair); exit(1);}
	if(n != amicable_pair && get_sum_of_proper_divisors(amicable_pair) == n){
		printf("%ld,%ld are amicable\n",n,amicable_pair);
		return (n + amicable_pair);
	}
	else return 0;
}

int main(int argc, char *argv[]){
	initialize_prime_stack();
	long sum=0;
	long i;
	for(i = 1; i <= 10000; i++){
		sum += get_amicable_sum(i);
	}
	printf("Sum of all amicable pairs upto 10000 is %ld\n",sum);	
	return 0;
}
