/*
6. Faça um programa que utilize as seguintes informações:
Médicos: Código do médico, Nome, Especialidade

Pacientes: Código do paciente, Nome do paciente, Sexo, Idade

Consultas: Número do Prontuário, Data da consulta, Horário da consulta, Código do médico, Código do paciente

- Crie rotinas para realizar a inclusão no cadastro de médicos e pacientes;
- Crie rotinas para listar todos os médicos e pacientes cadastrados;
- Crie uma rotina para cadastrar uma consulta. Verifique se o código do médico e do paciente
existem. Não permita que duas ou mais consultas sejam marcadas no mesmo dia e horário
para o mesmo médico;
- Crie uma rotina para mostrar todas as consultas realizadas por um médico numa data
qualquer, escolhidos pelo usuário.
*/

#include <stdio.h>
#include "medico.h"
#include "paciente.h"
#include "consulta.h"

enum opcoes_menu { SAIR, 
                   CADASTRAR_MEDICO, 
                   LISTAR_MEDICOS, 
                   CADASTRAR_PACIENTE, 
                   LISTAR_PACIENTES, 
                   CADASTRAR_CONSULTA, 
                   LISTAR_CONSULTAS };

int main()
{
    int op, num_medicos = 0, num_pacientes = 0, num_consultas = 0;
    medico medicos[MAX_MEDICOS];
    paciente pacientes[MAX_PACIENTES];
    consulta consultas[MAX_CONSULTAS];

    do {
        printf("\nCONSULTORIO MEDICO\n");
        printf("<%d> Cadastrar um medico\n", CADASTRAR_MEDICO);
        printf("<%d> Listar todos os medicos\n", LISTAR_MEDICOS);
        printf("<%d> Cadastrar um paciente\n", CADASTRAR_PACIENTE);
        printf("<%d> Listar todos os pacientes\n", LISTAR_PACIENTES);
        printf("<%d> Cadastrar uma consulta\n", CADASTRAR_CONSULTA);
        printf("<%d> Listar as consultas de um medico\n", LISTAR_CONSULTAS);
        printf("<%d> Sair do programa\n", SAIR);
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case CADASTRAR_MEDICO:
                cadastrar_medico(&num_medicos, medicos);
                break;
            case LISTAR_MEDICOS:
                listar_medicos(num_medicos, medicos);
                break;
            case CADASTRAR_PACIENTE:
                cadastrar_paciente(&num_pacientes, pacientes);
                break;
            case LISTAR_PACIENTES:
                listar_pacientes(num_pacientes, pacientes);
                break;
            case CADASTRAR_CONSULTA:
                cadastrar_consulta(&num_consultas, consultas, num_medicos,
                                   medicos, num_pacientes, pacientes);
                break;
            case LISTAR_CONSULTAS:
                listar_consultas(num_consultas, consultas, num_medicos,
                                 medicos, num_pacientes, pacientes);
                break;
            case SAIR:
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != SAIR);
    return 0;
}