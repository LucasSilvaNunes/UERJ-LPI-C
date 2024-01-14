#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dados{ 
	char nome[51];
	char matricula[13];
	char endereco[66];
	char cpf[12];
	char banco[4];
	char agencia[6];
	char conta[9];
	float valor_hora;
	float valorTotal;
};

int compare(const void *a, const void *b){ //função de comparação dos nomes.
	struct dados* x = (struct dados*)a;
	struct dados* y = (struct dados*)b;
	
	if (strcmp(x->nome, y->nome) == 0){
		return 0;
	} else if(strcmp(x->nome, y->nome) < 0){
		return -1;
	} else{
		return 1;
	}	
}

int main(){
	float total;
	char c, d;
	int i=0,j=0;
	FILE* fPointer = NULL;
	FILE* nov = NULL;
	
	if((fPointer = fopen("Funcionarios.txt","r+")) == NULL){ //abertura dos arquivos
		perror("Erro ao abrir Funcionarios.txt");
		return 1;
	}
	if((nov = fopen("Novembro.txt","r")) == NULL){
		perror("Erro ao abrir Novembro.txt");
		return 2;
	}
	
	struct horas{
		char mat[13];
		int horaTrabalhada;
	};	
	
	struct horas func[10];
	
	struct dados emp[10];
	
	for(i=0; i<10; i++){//leitura e separação dos dados em struct para Funcionarios.txt
		while(j < 50){
			c=fgetc(fPointer);
			emp[i].nome[j] = c;
			if(j == 49){
				emp[i].nome[j+1] = '\0';
			}
			j++;
		}
		c=fgetc(fPointer);
		j=0;
		
		while((c=fgetc(fPointer)) != ' '){
			emp[i].matricula[j] = c;
			j++;
		}
		emp[i].matricula[j] = '\0';
		j=0;
		
		while(j < 65){
			c=fgetc(fPointer);
			emp[i].endereco[j]=c;
			if(j == 64){
				emp[i].endereco[j+1] = '\0';
			}
			j++;
		}
		c=fgetc(fPointer);
		j=0;
		
		while((c=fgetc(fPointer)) != ' '){
			emp[i].cpf[j] = c;
			j++;
		}
		emp[i].cpf[j] = '\0';
		j=0;
		
		while((c=fgetc(fPointer)) != ' '){
			emp[i].banco[j] = c;
			j++;
		}
		emp[i].banco[j] = '\0';
		j=0;
		
		while((c=fgetc(fPointer)) != ' '){
			emp[i].agencia[j] = c;
			j++;
		}
		emp[i].agencia[j] = '\0';
		j=0;
		
		while((c=fgetc(fPointer)) != ' '){
			emp[i].conta[j] = c;
			j++;
		}
		emp[i].conta[j] = '\0';
		fscanf(fPointer, "%f", &emp[i].valor_hora);
		c=fgetc(fPointer);
		j=0;
	}
	
	for(i=0; i<10; i++){//leitura e separação dos dados em struct para Novembro.txt
		while((d=fgetc(nov))!= '/'){
			func[i].mat[j] = d;
			j++;
		}
		func[i].mat[j] = '\0';
		j=0;
		if(d == '/'){
			fscanf(nov, "%d", &func[i].horaTrabalhada);
		}
		d=fgetc(nov);
	}
	
	for(i=0; i<10; i++){//cálculo do valor a ser pago para os funcionários e armazenamento dos dados.
		for(j=0; j<10; j++){
			if(strcmp(emp[i].matricula, func[j].mat) == 0){
				total = emp[i].valor_hora * func[j].horaTrabalhada;
				emp[i].valorTotal = total;
			}
		}
	}
	
	qsort(emp, 10, sizeof(struct dados), compare); //ordenação dos elementos da struct dados.

	for(i=0; i<10; i++){ //impressão da folha de pagamento
		printf("%s ", emp[i].nome);
		printf("%s ", emp[i].matricula);
		printf("%s ", emp[i].endereco);
		printf("%s ", emp[i].cpf);
		printf("%s ", emp[i].banco);
		printf("%s ", emp[i].agencia);
		printf("%s ", emp[i].conta);
		printf("%0.2f\n", emp[i].valor_hora);
	}
	
	fclose(fPointer);
	fclose(nov);
	return 0;		
}


