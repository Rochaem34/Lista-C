/*
Considere as declarações a seguir para representar o cadastro de alunos de uma
disciplina e implemente uma função que imprima o número de matrícula, o nome, a
turma e a média de todos os alunos aprovados na disciplina.

typedef struct {
    char nome[40];
    int matricula;
    char turma;
    float provas[3];
} aluno;

Considere que o critério de aprovação é que a média
aritmética das 3 provas seja maior ou igual a 6.
A função deve receber como parâmetros o número de alunos
da disciplina e um vetor com os dados dos alunos.
*/

#include <stdio.h>

typedef struct {
    char nome[40];
    int matricula;
    char turma;
    float provas[3];
} aluno;

void aprovados(int, aluno []);

int main()
{
    int n;
    printf("Informe o numero de alunos da turma: ");
    scanf("%d", &n);
    aluno a[n];
    printf("Informe os dados dos %d alunos\n", n);
    for (int i = 0; i < n; i++) {
        printf("\n%do. aluno\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", a[i].nome);
        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        printf("Turma: ");
        scanf(" %c", &a[i].turma);
        for (int j = 0; j < 3; j++) {
            printf("Nota %da. prova: ", j + 1);
            scanf("%f", &a[i].provas[j]);
        }
    }
    aprovados(n, a);
    return 0;
}

void aprovados(int n, aluno a[])
{
    float media;
    printf("\n\tAlunos Aprovados\n");
    printf("----------------------------------------\n");
    printf("Matricula Nome               Turma Media\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        media = 0;
        for (int j = 0; j < 3; j++) {
            media += a[i].provas[j];
        }
        media /= 3;
        if (media >= 6) {
            printf("%09d %-20.20s  %c  %5.2f\n", a[i].matricula, 
                   a[i].nome, a[i].turma, media);
        }
    }
    printf("----------------------------------------\n");
}