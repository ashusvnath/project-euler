#include <stdio.h>
int main(int argc,char *argv[]){
	unsigned int tn,n=0,sequence_length;
	unsigned int lengths[1000000]={0};
	unsigned int max=0,start;
	while(n<1000000U){
		n=n+1U;
		tn=n;
		sequence_length=1U;
		do
		{
			if(tn%2==1)
				tn=3*tn+1U;
			else{
				tn/=2U;
				if(tn<n){
					sequence_length += lengths[tn];
					break;
				}
			}
			sequence_length++;
		}while(tn!=1U);
		lengths[n]=sequence_length;
		if(sequence_length>max){
			max=sequence_length;
			start=n;
		}
	}n
	printf("\n%u gives a sequence of length %u\n",start,max);	
	return 0;
}
