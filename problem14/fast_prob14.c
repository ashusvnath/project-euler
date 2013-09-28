#include <stdio.h>

int main(int argc, char *argv[]){
  int longest = 0;
  int terms = 0;
  int i;
  unsigned long j;
  for (i = 1; i <= 1000000; i++){
    j = i;
    int this_terms = 1;
    while (j != 1){
      this_terms++;      
      if (j % 2 == 0) j = j / 2;
      else j = 3 * j + 1;      
  	}
  	if(this_terms > terms){
	  terms = this_terms;
	  longest = i;
  	}
  }
  printf("longest: %d (%d)\n", longest, terms);
  return 0;
}
