#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

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

unsigned long poly(int a,int b,int n){
	long temp;
	temp = n*(n+a) + b;
	if(temp<0) return 0UL;
	return (unsigned)temp;
}

int main(int argc, char *argv[]){
	int a,b,n,max=0,maxa=0,maxb=0;
	unsigned long x;
	initialize();
	getPrimesUpto(1000000);
	PNODE trav = NULL;
	trav = primeTop;
	while(trav->p > 1000) trav = trav->next;
	while(trav!=NULL){
		b = trav->p;
		for(a=-1000;a<1000;a++){
			n=-1;
			do{
				n++;
				x=poly(a,b,n);
				printf("%lu ",x);
			}while(isPrime(x));
			printf("==>%d consecutive primes for for a n(n%+d)%+d starting with n=0\n",n,a,b);
			if(n>max) { max=n; maxa=a; maxb=b; }
		}
		trav = trav->next;
	}
	printf("%d consecutive primes are derived from a n(n%+d)%+d starting with n=0\n",max,maxa,maxb);
	return 0;
}
