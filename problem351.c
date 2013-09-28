#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<gmp.h>

unsigned long highestNumberCheckedForPrimality;

unsigned long gcd(unsigned long a, unsigned long b){
	unsigned long c;
	if(a>b) return gcd(b,a);
	c=b%a;
	if(c==0) return a;
	return gcd(c,a);
}

struct __prime_num{
	unsigned long p;
	struct __prime_num *next;
};

typedef struct __prime_num* PNODE;

#define NEW_PRIME_NODE() (PNODE)malloc(sizeof(struct __prime_num))

PNODE primeTop;

int addIfPrime(unsigned long n){
	PNODE trav =  primeTop;
	while(trav!=NULL && n<trav->p) {trav = trav->next;}
	while(trav!=NULL && n%trav->p!=0) {trav = trav->next;}
	if(trav==NULL){
		trav = NEW_PRIME_NODE();
		trav->p = n;
		trav->next = primeTop;
		primeTop = trav;
		return 1;
	}
	return 0;
}

void getPrimesUpto(unsigned long n){
	unsigned long p;
	if(n>highestNumberCheckedForPrimality){
		for(p=(primeTop->p)+2; p<=n; p +=2)
			addIfPrime(p);
		highestNumberCheckedForPrimality = n;
	}
}

unsigned long getTotient(unsigned long n){
	PNODE trav = primeTop;
	unsigned long totient,numProd,denProd,val;
	if(primeTop->p==n) return n-1;
	numProd=1;
	denProd=1;
	val=n;
	while(n>1){
		while(trav!=NULL && trav->p>n) trav=trav->next;
		if(trav==NULL) { getPrimesUpto(n); trav=primeTop; }
		if(n%trav->p==0){
			numProd *= (trav->p-1);
			denProd *= trav->p;
			while(n%trav->p==0) n=n/trav->p;
		}
		trav=trav->next;
	}
	return (val*numProd)/denProd;
}

unsigned long getTotientInverse(unsigned long n){
	return n-getTotient(n);
}

void initialize(){
	PNODE p,q;
	q = NEW_PRIME_NODE();
	q->p = 2;
	q->next = NULL;
	p = NEW_PRIME_NODE();
	p->p = 3;
	p->next = q;
	primeTop = p;
	highestNumberCheckedForPrimality=3;
}

int main(int argc, char *argv[]){
	unsigned long l,j,input;
	mpz_t sum;
	initialize();
	while(1){
		mpz_init_set_str(sum,"2",10);
		printf("Enter value of n to compute H(n):");
		scanf("%lu",&input);
		getPrimesUpto(input);
		for(l=4;l<=input;l++){
			//printf("Totient(%lu): %lu\n",l,getTotient(l));
			mpz_add_ui(sum, sum, getTotientInverse(l));
		}
		mpz_mul_ui(sum,sum,6);
		gmp_printf("Value is %Zd\n",sum);
	}
	mpz_clear(sum);
	return 0;
}
