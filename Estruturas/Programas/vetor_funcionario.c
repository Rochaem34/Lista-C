#include <stdio.h>

struct funcionario {
    char nome[41];
    int departamento;
    float salario;
};

int main()
{
    int n;
    printf("Informe o numero de funcionarios da empresa: ");
    scanf("%d", &n);
    struct funcionario func_array[n];
    printf("Informe os dados dos %d funcionario:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\n%do. funcionario:\n", i + 1);
        printf("Nome: ");
        scanf(" %40[^\n]", func_array[i].nome);
        printf("Departamento: ");
        scanf("%d", &func_array[i].departamento);
        printf("Salario: R$ ");
        scanf("%f", &func_array[i].salario);
    }

    printf("\n\nDados dos funcionario\n");
    printf("------------------------------------------------\n");
    printf("Nome                           Dpto.    Salario\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30.30s %04d %10.2f\n", func_array[i].nome, 
               func_array[i].departamento, func_array[i].salario);
    }
    printf("------------------------------------------------\n");
    return 0;
}
