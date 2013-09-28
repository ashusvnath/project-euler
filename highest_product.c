#include<stdio.h>

int row_prod(int num[20][20],int i,int j) {
  if(j>16) return -1;
  printf("%d:%d->%d:%d",i,j,i,j+3);
  return num[i][j]*num[i][j+1]*num[i][j+2]*num[i][j+3];
}

int column_prod(int num[20][20],int i,int j) {
  if(i>16) return -1;
  printf("%d:%d->%d:%d",i,j,i+3,j);
  return num[i][j]*num[i+1][j]*num[i+2][j]*num[i+3][j];
}

int principal_diagonal_prod(int num[20][20],int i,int j) {
  if(i>16 || j>16) return -1;
  printf("%d:%d->%d:%d",i,j,i+3,j+3);
  return num[i][j]*num[i+1][j+1]*num[i+2][j+2]*num[i+3][j+3];
}

int secondary_diagonal_prod(int num[20][20],int i,int j) {
  if(i<3 || j>16) return -1;
  printf("%d:%d->%d:%d",i,j,i-3,j+3);
  return num[i][j]*num[i-1][j+1]*num[i-2][j+2]*num[i-3][j+3];
}

int main(int argc,char *argv[]) {
  int num[20][20];
  int i,j,a,max=-1;
  for(i=0; i<20; i++)
    for(j=0; j<20; j++)
      scanf("%d",&num[i][j]);
  for(i=0; i<20; i++)
    for(j=0; j<20; j++)
    {
     a=row_prod(num,i,j);
     printf("=%d,",a);
     if(a>max) max=a;
     a=column_prod(num,i,j);
     printf("=%d,",a);
     if(a>max) max=a;
     a=principal_diagonal_prod(num,i,j);
     printf("=%d,",a);
     if(a>max) max=a;
     a=secondary_diagonal_prod(num,i,j);
     printf("=%d\n",a);
     if(a>max) max=a;
    }
  printf("The maximum product is : %d\n", max);
  return 0;
}
