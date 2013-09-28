#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 28123

long primeStack[STACK_SIZE];
int primeStackTop;

long abundantStack[STACK_SIZE];
int abundantStackTop;

FILE *primes;
FILE *abundants;
FILE *expressible;
void initializeStacks(){
    primeStack[0]=2;primeStack[1]=3;
    primeStack[2]=5;primeStack[3]=7;
    primeStackTop=3;
    abundantStackTop=0;
    abundantStack[abundantStackTop]=12; 
    /*primes=fopen("primes.txt","w");
    abundants=fopen("abundants.txt","w");
	expressible=fopen("expressible_as_sum_of_abundant_pairs.txt","w");
	*/
}

void cleanup(){
	/*fclose(primes);
	fclose(abundants);
	fclose(expressible);*/
}

void pushPrime(long n){
    primeStackTop++;    
    primeStack[primeStackTop]=n;
    //fprintf(primes,"%ld\n",n);
}

void pushAbundant(long n){
    abundantStackTop++;    
    abundantStack[abundantStackTop]=n;
	//fprintf(abundants,"%ld\n",n);
}

long primeStackContains(int n){
    int i;
    if(n>primeStack[primeStackTop]) return 0;
    for(i=0;i<=primeStackTop;i++)
        if(primeStack[i]==n) return 1;
    return 0;
}

int isPrime(long n){
    int i;
    for(i=0;i<=primeStackTop;i++)
        if(n%primeStack[i]==0) return 0;
    pushPrime(n);
    return 1;
}

void findAllPrimesUpto(long n){
    long i;
    for(i=primeStack[primeStackTop]; i<=n; i+=2)
       isPrime(i);
}

void isAbundant(long n){
	long highestPowerOfPrime[STACK_SIZE]={0}, temp, prime;
	long prodFactors = 1;
    long count = 0, sum = 1, prod = 0;
    int i=0;
    if(n==1||primeStackContains(n)) return;
	temp = n;
	for(i = 0; temp>1; i++){
		if(i > primeStackTop) findAllPrimesUpto(temp);
		prime = primeStack[i];
		if(temp%prime == 0)
		{
			prod = 1;
			sum = 1;
			while(temp % prime == 0){
				temp = temp / prime;
				prod *= prime;
				sum += prod;
			}
			highestPowerOfPrime[i] = sum;
		}
	}
	prodFactors=1;
	for(i--;i>=0;i--){
		if(highestPowerOfPrime[i]==0) continue;
		prodFactors *= highestPowerOfPrime[i];
	}
	sum	= prodFactors - n;
	if(sum>n)
		pushAbundant(n);
	return;
}

void updateAllAbundantsUpto(long n){
	int i;
	for(i=abundantStack[abundantStackTop]+1;i<=n;i++)
		isAbundant(i);
}

int abundantStackContains(long n){
	int i=0;
	while(i<=abundantStackTop && abundantStack[i]<n) i++;
	return abundantStack[i]==n ? 1 : 0;
}

int isExpressibleAsSumOfAbundantPair(long n){
	int i=abundantStackTop;
	while(i>=0&&n<abundantStack[i]) i--;
	if(i<0) return 0;
	for(;i>=0;i--){
		if(abundantStackContains(n-abundantStack[i])){ 
			//fprintf(expressible,"%ld\n",n); 
			return 1;
		}
	}
	return 0;
}
int main(int argc, char *argv[]){
	initializeStacks();
	long sumNotExpressibleAsAbundantSum=0;
	long i;
	for(i = 1; i <= 28123; i++){
		if(i>abundantStack[abundantStackTop]) updateAllAbundantsUpto(i);
		if(!isExpressibleAsSumOfAbundantPair(i))
			sumNotExpressibleAsAbundantSum += i;
	}
	printf("Sum of all positive integers (<= 28123) not\
	 expressible as a sum of a pair of abundant numbers is %ld\n",sumNotExpressibleAsAbundantSum);	
	cleanup();
	return 0;
}
