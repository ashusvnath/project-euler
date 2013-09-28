#include "problem14.h" #define MILLION 1000000

extern unsigned int __node_count;

void initialize(){

  __init_tree();
  __init_stack();
}

int main(int argc,char *argv[]){

    unsigned int n=1U,tn;
    unsigned int sequence_length=0U;
    unsigned int max_sequence_length=0U, max_sequence_starting_number=0U;
    unsigned int *stack,len=0U;
    unsigned int start,length;
    long iter_count;
    STACK popped;
    initialize();
    while(n<MILLION){
        tn=n;
        sequence_length=1u;
        do
        {
                tn=(tn%2==0)?(tn/2):(3*tn+1);
                len=get_seq_len(tn);
                if(len>0){
                    sequence_length+=len;
                    break;
                }
                push(tn,sequence_length);
            sequence_length++;
        }while(tn!=1);
        if(sequence_length>max_sequence_length) {
            max_sequence_length=sequence_length;
            max_sequence_starting_number=n;
        }
        while((pop(&start,&length,sequence_length))!=0)
                add(start,length);
        n=n+1;
    }
    printf("\n%u produces a chain of lenght %u\n",max_sequence_starting_number,max_sequence_length);
    return 0;
}
