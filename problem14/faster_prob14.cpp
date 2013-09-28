#include<iostream>
int main(){
	int result = 1;
	int index  = 0;
	int lengths[1000000];
	lengths[1] = 1;
	for (int i = 1 ; i < 1000000;){
		if (lengths[i] > result){
			result = lengths[i];
			index = i;
		}
		i++;
		unsigned int n = i;
		int chainLen = 1;
		for(;;){
			if(n%2)
				n = 3 * n + 1;
			else{
				n >>= 1;
				if (n < i){
					lengths[i] = chainLen + lengths[n];
					break;
				}
			}
			chainLen++;
		}
	}
	std::cout << "#" << index << " result " << result << std::endl;
	return 0;
}
