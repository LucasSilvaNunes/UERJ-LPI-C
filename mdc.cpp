#include <stdio.h>

int mdc(unsigned int, unsigned int);
int swap(unsigned int *, unsigned int *);

int main(){
	unsigned int a=0, b=0;
	
	scanf("%d %d", &a, &b);
	
	swap(&a, &b);
	
	mdc(a, b);
}

int swap(unsigned int *a, unsigned int *b){
		int aux;
		if (*b>*a){
			aux = *a;
			*a = *b;
			*b = aux;
		}
}

int mdc(unsigned int a, unsigned int b){
		if (a % b == 0){
		printf("%d", b);
		return 0;
	}
	for(int i=b-1; i>=1; i--){
		if (b % i == 0){
			if (a % i == 0){
				printf("%d", i);
				return 0;
			}
		}
	}
}

