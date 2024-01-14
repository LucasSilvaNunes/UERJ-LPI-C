#include <stdio.h>
#include <ctype.h>

int main(void){
	int printchar=0, lines=0, allchar=0;
	char nome[30], c;
	FILE* txtfile = NULL;
	
	scanf("%s", nome);
	
	if ((txtfile = fopen(nome, "r"))== NULL){
		printf("Erro no arquivo %s", nome);
		return 1;
	}
	while ((c = fgetc(txtfile)) != EOF){
		if(isspace(c)){
			if(c == '\n'){
				lines++;
				allchar++;
			}else{
				allchar++;
				printchar++;
			}
		}else{
			printchar++;
			allchar++;
		}
		if(ferror(txtfile)){
			printf("Erro no arquivo %s", nome);
			return 2;
		}
	}
	if (fclose(txtfile) == EOF){
		printf("Erro no arquivo %s", nome);
		return 3;
	}
	printf("%d\n%d\n%d\n", allchar, printchar, lines);
	return 0;
}	

