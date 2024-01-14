#include <stdio.h>
#include <string.h>

int main(){
	int length, i, j;
	char str[100];
	
	fgets(str, 100, stdin);
	length = strlen(str);
	str[length - 1] = '\0';
	
	for(i=0, j=length-1; i<=j; i++, j--){
		if(str[i] != str[j]){
			printf("NAO\n");
			return 0;
		}
	}
	printf("SIM\n");
	return 0;	
}
