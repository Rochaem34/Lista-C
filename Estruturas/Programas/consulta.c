/* consulta.c
*/

#include "consulta.h"
#include <stdbool.h>
#include <stdio.h>


static bool valida_data_horario(int n_consultas, const consulta consultas[], consulta c)
{
    for (int i = 0; i < n_consultas; i++) {
        if ((consultas[i].cod_medico == c.cod_medico || consultas[i].cod_paciente == c.cod_paciente) 
            && compara_data_horario(consultas[i].data_consulta, consultas[i].hora_consulta,
                                    c.data_consulta, c.hora_consulta) == 0) {
            return false;
        }
    }
    return true;
} 

void cadastrar_consulta(int * n_consultas, consulta consultas[], 
                        int n_medicos, const medico medicos[], 
                        int n_pacientes, const paciente pacientes[])
{
    if (*n_consultas < MAX_CONSULTAS) {
        if (n_medicos > 0) {
            if (n_pacientes > 0) {
                int cod_medico, cod_paciente, sair;
                printf("\nNova consulta\n");
                consultas[*n_consultas].num_prontuario = *n_consultas + 1;
                printf("Numero do prontuario: %d\n", consultas[*n_consultas].num_prontuario);
                printf("Codigo do medico (1 a %d): ", n_medicos);
                scanf("%d", &cod_medico);
                while (cod_medico < 1 || cod_medico > n_medicos) {
                    printf("Erro: codigo invalido!\n");
                    printf("Codigo do medico (1 a %d ou -1 p/ cancelar): ", n_medicos);
                    scanf("%d", &cod_medico);
                    if (cod_medico == -1) {
                        return;
                    }
                }
                consultas[*n_consultas].cod_medico = cod_medico;
                printf("Nome do medico: %s\n", medicos[cod_medico - 1].nome);
                printf("Codigo do paciente (1 a %d): ", n_pacientes);
                scanf("%d", &cod_paciente);
                while (cod_paciente < 1 || cod_paciente > n_pacientes) {
                    printf("Erro: codigo invalido!\n");
                    printf("Codigo do paciente (1 a %d ou -1 p/ cancelar): ", n_medicos);
                    scanf("%d", &cod_paciente);
                    if (cod_paciente == -1) {
                        return;
                    }
                }
                consultas[*n_consultas].cod_paciente = cod_paciente;
                printf("Nome do paciente: %s\n", pacientes[cod_paciente - 1].nome);
                le_data_horario("Informe a data e horario da consulta", 
                                 &consultas[*n_consultas].data_consulta, 
                                 &consultas[*n_consultas].hora_consulta);
                while (!valida_data_horario(*n_consultas, consultas, consultas[*n_consultas])) {
                    printf("Erro: ja' existe uma consulta para este medico ou paciente neste horario!\n");
                    printf("Digite -1 p/ encerrar: ");
                    scanf("%d", &sair);
                    if (sair == -1) {
                        return;
                    }                    
                    le_data_horario("Informe a data e horario da consulta", &consultas[*n_consultas].data_consulta, &consultas[*n_consultas].hora_consulta);
                }
                (*n_consultas)++;
                printf("\nConsulta cadastrada com sucesso!\n");
            }
            else {
                printf("\nErro: nao ha' nenhum paciente cadastrado!\n");
            }
        }
        else {
            printf("\nErro: nao ha' nenhum medico cadatrado!\n");
        }
    }
    else {
        printf("\nErro: nao e' possivel cadastrar mais nenhum consulta!\n");
    }
}

void listar_consultas(int n_consultas, const consulta consultas[], 
                      int n_medicos, const medico medicos[], 
                      int n_pacientes, const paciente pacientes[])
{
    if (n_consultas > 0) {
        int cod_medico;
        data dt;
        printf("\nConsultas de um medico\n");
        printf("Codigo do medico (1 a %d): ", n_medicos);
        scanf("%d", &cod_medico);
        while (cod_medico < 1 || cod_medico > n_medicos) {
            printf("Erro: codigo invalido!\n");
            printf("Codigo do medico (1 a %d ou -1 p/ cancelar): ", n_medicos);
            scanf("%d", &cod_medico);
            if (cod_medico == -1) {
                return;
            }
        }
        printf("Nome do medico: %s\n", medicos[cod_medico - 1].nome);
        le_data("Data das consultas", &dt);
        printf("\nConsultas de %s no dia ", medicos[cod_medico - 1].nome);
        imprime_data(dt);
        printf("\n-----------------------------------\n");
        printf("#Pront. Paciente            Horario\n");
        printf("-----------------------------------\n");
        for (int i = 0; i < n_consultas; i++) {
            if (consultas[i].cod_medico == cod_medico 
                && compara_data(consultas[i].data_consulta, dt) == 0) {
                printf("%06d  %-20.20s ", consultas[i].num_prontuario,
                pacientes[consultas[i].cod_paciente - 1].nome);
                imprime_horario(consultas[i].hora_consulta);
                printf("\n");
            }
        }
        printf("-----------------------------------\n");
    }   
    else {
        printf("\nErro: nao ha' nenhuma consulta cadastrada!\n");
    } 
}                      
