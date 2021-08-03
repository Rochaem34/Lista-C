/*
3. Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo os
seguintes campos:
- marca : string de tamanho 30
- ano : inteiro
- cor : string de tamanho 15
- preco : real
a) Escrever a definição da estrutura carro .
b) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20.
Crie um menu para:
c) Cadastrar um carro no vetor vetcarros .
d) Listar todos os carros com preço menor ou igual a um valor fornecido pelo usuário;
e) Listar todos os carros de uma determinada marca fornecida pelo usuário;
*/

#include <stdio.h>
#include <string.h>

#define MAX_CARROS 20

struct carro{
    char marca[31];
    int ano;
    char cor[16];
    double preco;
};

int main(){
    struct carro vetcarros[MAX_CARROS];
    int opcao = 10, i = 0;
    char search_marca[31];
    double search_preco;
    while (opcao != 0){
        printf("1 - Cadastrar Novo Veiculo\n2 - Procurar veiculos por preco");
        printf("\n3 - Procurar veiculos por marca\n0 - Para sair do programa\n");
        printf("\nSelecione a opcao -> ");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            if (i < MAX_CARROS) {
                printf("\nInforme a marca do carro: ");
                scanf(" %30[^\n]", vetcarros[i].marca);
                printf("Informe o ano do carro: ");
                scanf("%d", &vetcarros[i].ano);
                printf("Informe a cor do carro: ");
                scanf(" %15[^\n]", vetcarros[i].cor);
                printf("Informe o preco do carro: R$ ");
                scanf("%lf", &vetcarros[i].preco);
                printf("\n\n");
                i++;
            }
            else {
                printf("\nErro: nao e' possivel cadastrar mais nenhum carro!\n");
            }
            break;
        case 2:
            printf("\nInforme o preco do carro: R$ ");
            scanf("%lf", &search_preco);
            for(int j = 0; j < i; j++){
                if(vetcarros[j].preco <= search_preco){
                    printf("Marca: %s\n", vetcarros[j].marca);
                    printf("Ano: %d\n", vetcarros[j].ano);
                    printf("Cor: %s\n", vetcarros[j].cor);
                    printf("Preco: R$ %.2lf\n", vetcarros[j].preco);
                    printf("\n");
                }
            }
            printf("-------------------------------------");
            printf("\n");
            break;
        case 3:
            printf("\nInforme a marca do carro: ");
            scanf(" %30[^\n]", search_marca);
            for(int j = 0; j < i; j++){
                if(strcasecmp(search_marca, vetcarros[j].marca) == 0){
                    printf("Marca: %s\n", vetcarros[j].marca);
                    printf("Ano: %d\n", vetcarros[j].ano);
                    printf("Cor: %s\n", vetcarros[j].cor);
                    printf("Preco: R$ %.2lf\n", vetcarros[j].preco);
                    printf("\n");
                }
            }
            printf("-------------------------------------");
            printf("\n");
            break;
        case 0:
            printf("Programa Encerrado\n");
            break;
        default:
            printf("\nSelecione uma opcao valida!!\n\n");
        }
    }
    return 0;
}