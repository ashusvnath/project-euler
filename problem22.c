#include<stdio.h>
#include<string.h>
unsigned long get_score(char *s){
	unsigned long sum=0;
	int i=0;
	while(*(s+i)!='\0'&&*(s+i)!='\n'){
		sum += 1 + (unsigned long)(*(s+i)-'A');
		i++;
	}
	return sum;
}

int main(int argc, char *argv[]){
	FILE *f;
	char name[50];
	unsigned long count=0;
	double sum=0.0e0;
	f=fopen("prob22_names_sorted.txt","r");
	do{
		fscanf(f,"%s",name);
		count++;
		sum += get_score(name)*count;
		printf("%s,%lu,%lu,%lu\n",name,count,get_score(name),count*get_score(name));
	}while(!feof(f));
	printf("Total Count: %lu\n",count);
	printf("%lf\n",sum);
}
