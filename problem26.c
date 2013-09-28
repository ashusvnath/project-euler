#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>

mpz_t powTen,powTenMinusOne;
mpz_t rem,num;

void initialize(){
	mpz_init(powTen);
	mpz_init(powTenMinusOne);
	mpz_init(num);
	mpz_init(rem);	
}

int getRecurringDigits(int n){
	int count = 1;
	mpz_set_si(num, n);		
	mpz_set_si(powTen,10);
	while(1){
	    mpz_sub_ui(powTenMinusOne, powTen, 1UL);
		mpz_tdiv_r(rem, powTenMinusOne, num);
		if(mpz_cmp_ui(rem,0)==0) { break; }
		mpz_mul_ui(powTen,powTen,10);
		count++;
	}
	return count; 
}

int main(int argc, char *argv[]){	
	int i,max=0,max_i=0;
	int current;
	double d;
	initialize();
	for(i=3; i<1000; i+=2){
		if(i%5==0) continue;
		d = 10.0e0;
		current=getRecurringDigits(i);
		if(current>max) { max=current; max_i=i; printf("|%3d, %3d| ",max_i,max); }
	}
	printf("%d produces the maximum cycle of %d\n",max_i,max);
	return 0;
}
