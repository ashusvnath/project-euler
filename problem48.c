#include <stdio.h>

int main(int argc, char *argv[]){
  unsigned long num, temp, count;
  unsigned long sum;
  for(num = 1; num < 1001; num++){
    temp = 1; count = num;
    while(count){ temp = (temp*num) % 1000000000000; count--;}
    sum += temp;
  }
  printf("The answer is : %lu\n", sum);
  return 0;
}
