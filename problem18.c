#include<stdio.h>
#include<malloc.h>
#define ROWS 100

char *t;
int *numbers;

int strlen(char *s){
	int i=0;
	while(*(s+i)!='\0') i++;
	return i;
}

char* substr_upto(char *s, int n){
	int i;
	char *t=(char *)malloc(sizeof(char)*n);
	for(i=0;i<n;i++) t[i]=s[i];
	t[i]='\0';
	return t;
}

int* get_numbers(char *s,char len){
	int count=0;
	char *t,*p;
	t=p=s;
	numbers=(int *)malloc(sizeof(int)*len);
	do{
		while(*t!=' ' && *t!='\0') t++;
		numbers[count++]=atoi(substr_upto(p,t-p));
		p=++t;
	}while(*p!='\0');
	return numbers;
}

int max(int x,int y){
	return (x>=y) ? x:y;
}

int get_highest_sum(int *rows[], int size){
	int i,j;
	for(i=size-2;i>=0;i--){
		for(j=0;j<=i;j++)
			rows[i][j]+=max(rows[i+1][j],rows[i+1][j+1]);
	}
	return rows[0][0];
}

int get_highest_sum_recursive(int *rows[], int i, int j,int size){
	int sum;
	if(i==size-1) return rows[i][j];
	sum=max(
		rows[i][j]+get_highest_sum_recursive(rows,i+1,j,size),
		rows[i][j]+get_highest_sum_recursive(rows,i+1,j+1,size)
	);
	return sum;
}

int main(int argc,char *argv[]){
	int *rows[ROWS];
	int i,j;
	char s[ROWS*3];
	for(i=0;i<ROWS;i++){
		gets(s);
		rows[i]=get_numbers(s,i+1);
	}
 	//printf("The highest sum by recursion is %d\n",get_highest_sum_recursive(rows,0,0,ROWS));
	printf("The highest sum by bottom-up is %d\n",get_highest_sum(rows,ROWS));
	return 0;
}
