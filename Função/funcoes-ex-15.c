/*
15. Escreva uma função de protótipo void init_vetor(int n, int a[], int val); que
inicialize o vetor a com n elementos com o valor de val.
*/

#include <stdio.h>

void init_vetor(int, int *, int);
void imprime_vetor(int, int *);

int main()
{
    int n, val;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    printf("Informe o valor: ");
    scanf("%d", &val);
    init_vetor(n, vet, val);
    imprime_vetor(n, vet);
    return 0;
}


void imprime_vetor(int n, int a[])
{
    //printf("\nNumero de bytes de a: %zd bytes\n", sizeof(a));
    printf("\nConteudo do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void init_vetor (int n, int a[], int val){
    int i;
    for(i = 0; i < n; i++){        
        a[i] = val;
    }
}