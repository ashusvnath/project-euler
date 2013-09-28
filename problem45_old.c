#include <stdio.h>
/* #define LIST_SIZE 1000000000 */

/* unsigned long tn[LIST_SIZE] = {0}, num_tn = 0; */
/* unsigned long triangular(unsigned long n){ */
/*   return n*(n + 1)/2; */
/* } */
/*  */
/* unsigned long pn[LIST_SIZE] = {0}, num_pn = 0; */
/* unsigned long pentagonal(unsigned long n){ */
/*   return n*(3*n - 1)/2; */
/* } */
/*  */
/* unsigned long hn[LIST_SIZE] = {0}, num_hn = 0; */
/* unsigned long hexagonal(unsigned long n){ */
/*   return n*(2*n - 1); */
/* } */
/*  */
/* void find_kind_upto(unsigned long n, unsigned long *list, unsigned long *highest_index, unsigned long (*next)(unsigned long)){ */
/*    while(*(list + *highest_index) < n){ */
/*      *(list + *highest_index) = (*next)(*highest_index + 1); */
/*      (*highest_index)++; */
/*    } */
/* } */

/* void find_triangular_upto(unsigned long n){ */
/*    while(tn[num_tn] < n){ */
/*      tn[num_tn] = triangular(num_tn+1); */
/*      num_tn++; */
/*    } */
/*   #<{(| find_kind_upto(n, tn, &num_tn, triangular); |)}># */
/* } */
/*  */
/* void find_pentagonal_upto(unsigned long n){ */
/*    while(pn[num_pn] < n){ */
/*      pn[num_pn] = triangular(num_pn+1); */
/*      num_pn++; */
/*    } */
/*   #<{(| find_kind_upto(n, pn, &num_pn, pentagonal); |)}># */
/* } */
/*  */
/* void find_hexagonal_upto(unsigned long n){ */
/*    while(hn[num_hn] < n){ */
/*      hn[num_hn] = triangular(num_hn+1); */
/*      num_hn++; */
/*    } */
/*   #<{(| find_kind_upto(n, hn, &num_hn, hexagonal); |)}># */
/* } */
/*  */
/* void find_all_upto(unsigned long n){ */
/*   find_triangular_upto(n); */
/*   find_pentagonal_upto(n); */
/*   find_hexagonal_upto(n); */
/* } */

int main(int argc, char *argv[]){
  unsigned long ti=1, pi=1, hi=1;
  unsigned long tn, pn, hn;
  unsigned long found = 0;
  tn=triangular(ti);
  pn=pentagonal(pi);
  hn=hexagonal(hi);
  do{
    while(pn < hn) pi++;
    if(pi > num_pn) { pi = num_pn; find_all_upto(pn[num_pn]*3); continue;}
    if(hn[hi] < pn[pi]) { hi++; printf("."); continue;}
    ti = pi;
    while(tn[ti] < pn[pi]) ti++;
    if(ti > num_tn) { ti = num_tn; find_all_upto(tn[num_tn]*3); continue;}
    if(pn[pi] < tn[ti]) { pi++; printf(","); continue;}
    if(pn[pi] == hn[hi] && hn[hi] == tn[ti]) {
      found++;
      hi++; printf("\n%lu %lu %lu %lu\n", tn[ti], ti, pi, hi);
    }
  } while(found<2)
  return 0;
}
