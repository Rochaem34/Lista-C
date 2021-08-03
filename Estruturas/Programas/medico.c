/* medico.c 
   Implementação das funções do tipo medico.
   Ciro C. Trindade
*/

#include "medico.h"
#include <stdio.h>

void cadastrar_medico(int * n_medicos, medico medicos[])
{
    if (*n_medicos < MAX_MEDICOS) {
        printf("\nNovo medico\n");
        medicos[*n_medicos].cod_medico = *n_medicos + 1;
        printf("Codigo: %d\n", medicos[*n_medicos].cod_medico);
        printf("Nome: ");
        scanf(" %40[^\n]", medicos[*n_medicos].nome);
        printf("Especialidade: ");
        scanf(" %30[^\n]", medicos[*n_medicos].especialidade);
        (*n_medicos)++;
        printf("\nMedico castrado com sucesso!\n");
    }
    else {
        printf("\nErro: nao e' possivel cadastrar mais nenhum medico!\n");
    }
}


void listar_medicos(int n_medicos, const medico medicos[])
{
    printf("\n\t\tMedicos cadastrados\n");
    printf("---------------------------------------------\n");
    printf("Cod. Nome                      Especialidade\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n_medicos; i++) {
        printf("%04d %-25.25s %-15.15s\n", medicos[i].cod_medico,
               medicos[i].nome, medicos[i].especialidade);
    }
    printf("---------------------------------------------\n");
}
