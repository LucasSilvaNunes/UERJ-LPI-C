#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	scanf("%d", &i); //tamanho do vetor
	float vet1[i], *ptr, aux;
	
	ptr = (float*) malloc(sizeof(vet1)); //alocação de memória dinâmica.
	
	for(int n=0; n<i; n++){ //leitura dos elementos alocados em memória dinâmica
		scanf("%f", &ptr[n]);
	}
	
	for(int n=i-1; n>=0; n--){ //bubblesort inverso
		for(int j=i-1; j>0; j--){
			if(ptr[j] > ptr[j-1]){
				aux = ptr[j-1];
				ptr[j-1] = ptr[j];
				ptr[j] = aux;
			}
		}
	}
	
	for(int n=0; n<i; n++){
		printf("%g \t", ptr[n]);
	}
		
	free (ptr);
	return 0;
}
