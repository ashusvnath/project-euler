#include<stdio.h>

int digs_used[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int get_next(int n,int d){
	int i=n,j;
	if(digs_used[i]==-1)digs_used[i]=d;
	else
		for(i=0;i<10;i++){
			if(digs_used[i]>=0)continue;
			n--;
			if(n==0){
			 digs_used[i]=d;
			 break;
			}
		}
	for(j=0;j<10;j++) printf("%c ",digs_used[j]>=0 ? ('0'+digs_used[j]):'_');
	printf("\n");
	return i;
}

int main(int argc, char *argv[]){
	int fact[]={1,1,2,6,24,120,720,5040,40320,362880};
	int n=1000000,i;
	int t,dig=9,count=0;
	int pos=0;
	int num[10]={0};
	/*while(n>0&&dig>=0){
		t = n/fact[dig];
		pos += t*fact[dig];
		num[count]=get_next(t,count);
		n=n%fact[dig];
		dig--;
		count++;
	}
	for(i=0;i<10;i++)printf("%d",num[i]);
	printf("\n");
	printf("Lexical position so far:%d\n",pos);*/
	for(count=9;count>=0&&n>=0;count--){
		printf("%d, %d\n",n/fact[count]+1,(n/fact[count])*fact[count]);
		n=n%fact[count];
	}
	return 0;
}
