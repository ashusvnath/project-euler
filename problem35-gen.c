#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

unsigned long highestNumberCheckedForPrimality;

struct __prime_num{
	unsigned long p;
	struct __prime_num *next;
};

typedef struct __prime_num* PNODE;

#define NEW_PRIME_NODE() (PNODE)malloc(sizeof(struct __prime_num))

PNODE primeTop;

int isPrime(unsigned long n){
	PNODE trav=primeTop;
	while(trav != NULL && trav->p > n) trav = trav-> next;
	if(trav==NULL) return 0;
	if(trav->p==n) return 1;
	return 0;
}

int addIfPrime(unsigned long n){
	PNODE trav =  primeTop;
	if(n<=0) return 0;
	while(trav!=NULL && n<trav->p) {trav = trav->next;}
	while(trav!=NULL && n%trav->p!=0) {trav = trav->next;}
	if(trav==NULL){
		trav = NEW_PRIME_NODE();
		trav->p = n;
		trav->next = primeTop;
		primeTop = trav;
		return 1;
	}
	if(trav->p == n) return 1;
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

int main(){
	initialize();
	getPrimesUpto(1000000UL);
	
	PNODE pTrav = primeTop;
	while(pTrav != NULL){
		printf("%lu\n",pTrav->p);
		pTrav = pTrav->next;
	}
	
	return 0;	
}
