#include<stdio.h>

int main(int argc, char *argv[]){
	int square[1002][1002]={{0}};
	//0->right,1->down,2->left,3->up
	int i,j,direction,count,sum,n;
	count=1; direction=-1;
	sum=0;
	printf("Enter value of n:");
	scanf("%d",&n);
	i=j=(n/2)+1;
	do{
		square[i][j]=count;
		count++;
		if(i==j || (i+j)==(n+1)) sum+=square[i][j];
		if(i==j || (i<j&&i+j==(n+2)) || (i>j&&i+j==(n+1))) direction=(direction+1)%4;
		if(direction&1)	i+=(2-direction);
		else j+=(1-direction);
	}while(count<=(n*n));
	if(n<=100){
		for(i=1;i<=n;i++,printf("\n"))
			for(j=1;j<=n;j++)
				printf("%4d ",square[i][j]);
	}
	printf("Sum of all diagonal elements is : %d\n",sum);
	return 0;
}
