/* consulta.h
   Definição do tipo consulta e protótipo de suas operações.
   Ciro C. Trindade
*/

#ifndef _CONSULTA_H
#define _CONSULTA_H

#include "my_date.h"
#include "paciente.h"
#include "medico.h"
#include <stdbool.h>

#define MAX_CONSULTAS 100

typedef struct {
    int num_prontuario;
    data data_consulta;
    horario hora_consulta;
    int cod_medico;
    int cod_paciente;
} consulta;

/* função para cadastrar uma consulta */
void cadastrar_consulta(int *, consulta [], int, const medico [], int, const paciente []);

/* função para mostrar as consultas de um medico numa data/horario */
void listar_consultas(int, const consulta [], int, const medico [], int, const paciente []);

/* função que valida a data e o horário de uma consulta */
static bool valida_data_horario(int, const consulta [], consulta);

#endif