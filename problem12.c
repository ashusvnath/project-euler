#include<stdio.h>

#define list_SIZE 1000000
int prime_list[list_SIZE],no_of_primes;

void initialize_prime_list(){
    prime_list[0]=2;prime_list[1]=3;
    prime_list[2]=5;prime_list[3]=7;
    no_of_primes=3;
}

void push(int n){
    no_of_primes++;    
    prime_list[no_of_primes]=n;
}

int prime_list_contains(int n){
    int i;
    if(n>prime_list[no_of_primes]) return 0;
    for(i=0;i<=no_of_primes;i++)
        if(prime_list[i]==n) return 1;
    return 0;
}

int isprime(int n){
    int i;
    for(i=0;i<=no_of_primes;i++)
        if(n%prime_list[i]==0) return 0;
    push(n);
    return 1;
}

void find_all_primes_upto(int n){
    int i;
    for(i=prime_list[no_of_primes]; i<=n; i+=2)
       isprime(i);
}

int main(int argc, char *argv[]){
    int tn=1,n=0;
    int prime_div_count[list_SIZE];
    int count=0;
    int i,temp,num_div,num_to_inspect;
    initialize_prime_list();
    while(1){
        n=n+1;
        tn=(n*(n+1))/2;
        if(prime_list_contains(tn))
            continue;
        temp=tn;
        for(i=0;i<list_SIZE;i++) prime_div_count[i]=0;
        for(i=0;temp>1;i++){
            if(i>no_of_primes) find_all_primes_upto(temp);
            num_to_inspect=prime_list[i];
            if(temp%num_to_inspect==0)
            {
                count=0;
                while(temp%num_to_inspect==0){
                    temp=temp/num_to_inspect;
                    count++;
                }
                prime_div_count[i]=count;
            }
        }
        num_div=1;
        for(i--;i>=0;i--) {
            num_div*=(prime_div_count[i]+1);
        }
        if(num_div>500) break;
        
    }
    printf("The %dth triangular number %d has %d divisors\n",n,tn,num_div);
    return 0;
}
