#include <stdio.h>


int main(void){

	int month, day, year;

	char monthname[16], line[256];


	while (fgets(line, sizeof(line), stdin) > 0) 

	{

		if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)

			printf("valid: %s\n", line); /* 25 Dec 1988 form */

		else if (sscanf(line, "%d/%d/%d", &day, &month, &year) == 3)

			if (month = 1){
				monthname = "Janeiro";
			}else if(month = 2){
				monthname = "Fevereiro";
			}else if(month = 3){
				monthname = "Março";
			}else if (month = 4){
				monthname = "Abril";
			}else if (month = 5){
				monthname = "Maio";
			}else if (month = 6){
				monthname = "Junho";
			}else if (month = 7){
				monthname = "Julho";
			}else if (month = 8){
				monthname = "Agosto"
			}else if (month = 9){
				monthname = "Setembro"
			}else if (month = 10){
				monthname = "Outubro"
			}else if (month = 11){
				monthname = "Novembro"
			}else if (month = 12){
				monthname = "Dezembro"
			}
			printf("valid: %s\n", day, monthname, year); /* mm/dd/yy form */

		else

			printf("invalid: %s\n", line); /* invalid form */

	}

}


// 15/03/2000
