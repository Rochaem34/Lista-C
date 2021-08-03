#include <stdio.h>

struct funcionario {
    char nome[41];
    int departamento;
    float salario;
};

int main()
{
    struct funcionario func;
    printf("Informe os dados do funcionario:\n");
    printf("Nome: ");
    scanf(" %40[^\n]", func.nome);
    printf("Departamento: ");
    scanf("%d", &func.departamento);
    printf("Salario: R$ ");
    scanf("%f", &func.salario);
    printf("\n\nDados do funcionario\n");
    printf("Nome: %s\n", func.nome);
    printf("Departamento: %d\n", func.departamento);
    printf("Salario: R$ %.2f\n", func.salario);
    return 0;
}

void fun(void) {
    struct funcionario f;    
}