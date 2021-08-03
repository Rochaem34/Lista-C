/* paciente.c */

#include "paciente.h"
#include <ctype.h>
#include <stdio.h>

void cadastrar_paciente(int * n_pacientes, paciente pacientes[])
{
    if (*n_pacientes < MAX_PACIENTES) {
        printf("\nNovo paciente\n");
        pacientes[*n_pacientes].cod_paciente = *n_pacientes + 1;
        printf("Codigo: %d\n", pacientes[*n_pacientes].cod_paciente);
        printf("Nome: ");
        scanf(" %40[^\n]", pacientes[*n_pacientes].nome);
        printf("Sexo (M|F): ");
        scanf(" %c", &pacientes[*n_pacientes].sexo);
        pacientes[*n_pacientes].sexo = toupper(pacientes[*n_pacientes].sexo);
        while (pacientes[*n_pacientes].sexo != 'M' && pacientes[*n_pacientes].sexo != 'F') {
            printf("Erro: sexo invalido!\n");
            printf("Sexo (M|F): ");
            scanf(" %c", &pacientes[*n_pacientes].sexo);
            pacientes[*n_pacientes].sexo = toupper(pacientes[*n_pacientes].sexo);
        }
        printf("Idade: ");
        scanf("%d", &pacientes[*n_pacientes].idade);
        (*n_pacientes)++;
        printf("\nPaciente castrado com sucesso!\n");
    }
    else {
        printf("\nErro: nao e' possivel cadastrar mais nenhum paciente!\n");
    }
}


void listar_pacientes(int n_pacientes, const paciente pacientes[])
{
    printf("\n\t\tPacientes cadastrados\n");
    printf("----------------------------------------\n");
    printf("Cod. Nome                     Sexo Idade\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < n_pacientes; i++) {
        printf("%04d %-25.25s  %c  %3d\n", pacientes[i].cod_paciente,
               pacientes[i].nome, pacientes[i].sexo, pacientes[i].idade);
    }
    printf("----------------------------------------\n");    
}
