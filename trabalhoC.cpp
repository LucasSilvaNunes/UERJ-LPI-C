#include <stdio.h>

int main(void){
	
	int dia, mes, ano, diaDoAno, somaDosMeses, contadorDeMeses;

		
	scanf("%d %d %d", &dia, &mes, &ano);
	
	diaDoAno = 0;
	
	if (ano % 100 == 0){ // ano terminado em 00
		if (ano % 400 == 0){
			} if (mes > 02){
				diaDoAno = diaDoAno + 1;
			}
			
		}else if(ano % 4 == 0){ // checagem ano bissexto
				if (mes > 02){
					diaDoAno = diaDoAno + 1;
				}
		}
	contadorDeMeses = 1 ;
	somaDosMeses = 0 ;
	while (contadorDeMeses < mes){
		
		if((contadorDeMeses < 8) && (contadorDeMeses % 2 == 0) && (contadorDeMeses != 2)){
			
			somaDosMeses = somaDosMeses + 30;
			contadorDeMeses = contadorDeMeses + 1;
				
		}else if(contadorDeMeses == 2){
				
			somaDosMeses = somaDosMeses + 28;
			contadorDeMeses = contadorDeMeses + 1;
				
		}else if((contadorDeMeses < 8) && (contadorDeMeses % 2 != 0)){
				
			somaDosMeses = somaDosMeses + 31;
			contadorDeMeses = contadorDeMeses + 1;
				
		}else if((contadorDeMeses < 12) && (contadorDeMeses % 2 == 0)){
				
			somaDosMeses = somaDosMeses + 31;
			contadorDeMeses = contadorDeMeses + 1;
			
		}else{
				
			somaDosMeses = somaDosMeses + 30;
			contadorDeMeses = contadorDeMeses + 1;
			
		}
			
	}
	
	diaDoAno = diaDoAno + dia + somaDosMeses;
	printf("%d", diaDoAno);
	return 0;
	
}
