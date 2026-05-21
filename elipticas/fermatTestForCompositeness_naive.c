/*
 * Naive Fermat Test for Compositeness
 * Compile: $ gcc -Wall fermatTestForCompositeness_naive.c -o fermatTestForCompositeness.x
 * Run: $ ./fermatTestForCompositeness.x n
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int mod_exp(long long int a, long long int n, long long int mod){
	if (n == 0)
		return 1;

	long long int x = mod_exp(a, n / 2, mod);

	x = (x * x) % mod;

	if(n % 2)
		x = (x * a) % mod;

	return x;
}


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Error. Run: $ ./fermatTestForCompositeness_naive.x n\n");
		exit(1);
	}

	long long int n = strtoll(argv[1], NULL, 10);

	for(long long int i=2; i<n; i++){
		if(mod_exp(i, n-1, n) != 1){
			printf("Fermat witness: %lld\n", i);
			return 1;
		}
	}

	printf("Probably prime\n");

	return 0;
}
