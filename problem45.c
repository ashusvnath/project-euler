#include <stdio.h>
#define triangular(n) (n)*((n)+1)/2
#define pentagonal(n) (n)*(3*(n)-1)/2
#define hexagonal(n) (n)*(2*(n)-1)

int main(int argc, char *argv[]){
  unsigned long ti=1, pi=1, hi=1;
  unsigned long tn, pn, hn;
  unsigned long found = 0;
  tn=triangular(ti);
  pn=pentagonal(pi);
  hn=hexagonal(hi);
  do{
    while(pn < hn) { pi++; pn = pentagonal(pi); }
    if(hn < pn) { hi++; hn = hexagonal(hi); continue; }
    while(tn < pn) { ti++; tn = triangular(ti); }
    if(pn < tn) { pi++; pn = pentagonal(pi); continue; }
    if(tn == pn && pn == hn) { found++; printf("\n%lu %lu %lu %lu", tn, ti, pi, hi); hi++; hn = triangular(hi); }
    else printf(".");
  } while(found<3);
  return 0;
}
