#include <stdio.h>

#define NOME_ARQ "alunos.txt"

void cadastrar_aluno(void);
void listar_alunos(void);

int main()
{
    int op;
    do {
        printf("\nCADASTRO DE ALUNOS\n");
        printf("<1> Cadastrar um aluno\n");
        printf("<2> Listar os alunos cadastrados\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cadastrar_aluno();
            break;
        case 2:
            listar_alunos();
            break;
        case 0:
            break;
        default:
            printf("\nErro: opcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}

void cadastrar_aluno()
{
    FILE * arq;
    int mat;
    char nome[41];
    printf("\nNovo aluno\n");
    printf("Matricula: ");
    scanf("%d", &mat);
    printf("Nome: ");
    scanf(" %40[^\n]", nome);
    if ((arq = fopen(NOME_ARQ, "a")) == NULL) {
        printf("\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ);
        return;
    }
    fprintf(arq, "%d %s\n", mat, nome);
    fclose(arq);
    printf("\nAluno cadastrado com sucesso!\n");
}

void listar_alunos()
{
    FILE * arq;
    int mat;
    char nome[41];
    if ((arq = fopen(NOME_ARQ, "r")) == NULL) {
        printf("\nErro: nao ha' nenhum aluno cadastrado!\n");
        return;
    }
    printf("\n\tAlunos cadastrados\n");
    printf("--------------------------------------\n");
    printf("Matricula Nome\n");
    printf("--------------------------------------\n");
    while (fscanf(arq, "%d %[^\n]", &mat, nome) > 0) {
        printf("%09d %s\n", mat, nome);
    }
    printf("--------------------------------------\n");
    fclose(arq);
}