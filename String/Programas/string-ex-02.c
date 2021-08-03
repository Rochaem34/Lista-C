#include <stdio.h>
#include <stdbool.h>

bool islowercase(char * str);

int main(){
	
	char crt[31];

    printf("Informe uma caracter: ");
    scanf(" %30[^\n]", crt);
    islowercase(crt);
}

bool islowercase(char * b){
	
    char str[31];
    int ind = 0, i;

    for(i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            ind++;
        }
    }
    if(ind > 1){
    	printf("false %d", ind);
	}else{
		printf("true %d", ind);
	}

    return 0;
}
