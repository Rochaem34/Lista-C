/* medico.h
   Dedinição do tipo medico e protótipo de suas operações.
   Ciro C. Trindade
*/

#ifndef _MEDICO_H
#define _MEDICO_H

#define MAX_MEDICOS 5

typedef struct {
    int cod_medico;
    char nome[41];
    char especialidade[31];
} medico;

/* função para cadastrar um novo medico */
void cadastrar_medico(int *, medico []);

/* função para listar todos os médicos */
void listar_medicos(int, const medico []);

#endif