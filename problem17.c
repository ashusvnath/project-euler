#include <stdio.h>
#include <string.h>

char *units[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char *low_tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *high_tens[]= {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char words[33];

char *get_word(int i){
  /* printf("%d ",i); */
  if(i<=9) return units[i-1];
  if(i<20) return low_tens[i-10];
  i=i/10;
  return high_tens[i-2]; 
}

char *in_words(int i){
	int temp=i;
	words[0]='\0';
	if(temp>=100){
		strcat(words, get_word(temp/100));
		strcat(words, " hundred");
    if(temp%100>0) strcat(words, " and ");
	}
	temp=temp%100;
	if(temp==0) return words;
	if(temp>0 && temp<=20){
		strcat(words, get_word(temp));
		return words;
	}
	strcat(words, get_word((temp/10)*10));
	temp=temp%10;
  if(temp==0) return words;
  strcat(words, "-");
	strcat(words, get_word(temp));				
	return words;
}

int main(int argc,char *argv[]){
	int i;
	for(i=1;i<1000;i++)
		printf("%s\n",in_words(i));
	return 0;
}
