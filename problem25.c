#include<stdio.h>
#include<math.h>

double lPhi;
double lSqrt5;
double logOf10;

void init(){
	lPhi = log(1.61803);
	lSqrt5 = log(sqrt(5.0e0));
	logOf10 = log(10.0e0);
}

double fib(int n){
	double val;
	val=(n*lPhi-lSqrt5);
	return floor(val/logOf10);
}

int main(int argc, char *argv[]){	
	int i;
	init();
	for(i=1;i<5000;i++){
		if(fib(i)>=999){
			printf("Fibonacci number %d is the first to have 1000 digits\n",i);
			break;
		}
	}
	return 0;
}
