/* paciente.h
   Define o tipo paciente e o protótipo de suas operações.
   Ciro C. Trindade
*/

#ifndef _PACIENTE_H
#define _PACIENTE_H

#define MAX_PACIENTES 20

typedef struct {
    int cod_paciente;
    char nome[41];
    char sexo;
    int idade;
} paciente;

/* função para cadastrar um paciente */
void cadastrar_paciente(int *, paciente []);

/* função para listar todos os pacientes */
void listar_pacientes(int, const paciente []);

#endif