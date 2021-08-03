/*
5. Escreva uma aplicação em C que crie um cadastro contendo o nome, telefone e e-mail de
seus amigos. Essas informações são representadas pela estrutura amigo mostrada a seguir.
Todo amigo cadastrado recebe um id sequencial e gerado automaticamente pelo sistema. A
aplicação deve possuir opções para cadastrar um novo amigo, listar todos os amigos
cadastrados, alterar o telefone ou e-mail de um amigo dado seu id ou nome e consultar um
amigo dado seu id ou nome.
typedef struct {
    int id; // identificador do amigo
    char nome[40];
    char fone[14];
    char email[30];
} amigo;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NOME_ARQ "amigos.dat"

typedef struct {
    int id; // identificador do amigo
    char nome[40];
    char fone[14];
    char email[30];
} amigo;

void cadastrar_amigo(void);
void listar_amigos(void);
void alterar_amigo(bool);
void consultar_amigo(bool);

int main()
{
    int op, tipo;
    do {
        printf("\n\nAGENDA DE AMIGOS\n");
        printf("<1> Cadastrar um amigo\n");
        printf("<2> Listar os amigos\n");
        printf("<3> Alterar um amigo\n");
        printf("<4> Consultar um amigo\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                cadastrar_amigo();
                break;
            case 2:
                listar_amigos();
                break;
            case 3:
                printf("\nAlterar um Amigo\n");
                printf("Procurar por id (1) ou nome (2): ");
                do {
                    scanf("%d", &tipo);
                } while (tipo != 1 && tipo != 2);
                alterar_amigo(tipo == 1);
                break;
            case 4:
                printf("\nConsultar um Amigo\n");
                printf("Procurar por id (1) ou nome (2): ");
                do {
                    scanf("%d", &tipo);
                } while (tipo != 1 && tipo != 2);
                consultar_amigo(tipo == 1);
                break;
            default:
                break;
        }
    } while (op != 0);
    return 0;
}   

void cadastrar_amigo()
{
    FILE * arq;
    amigo a;
    if ((arq = fopen(NOME_ARQ, "ab")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ);
        return;
    }
    printf("\n\nNovo Amigo\n");
    fseek(arq, 0, SEEK_END);    
    a.id = ftell(arq) / sizeof(amigo) + 1;
    printf("Id: %d\n", a.id);
    printf("Nome: ");
    scanf(" %39[^\n]", a.nome);
    printf("Telefone: ");
    scanf(" %13[^\n]", a.fone);
    printf("E-mail: ");
    scanf(" %29[^\n]", a.email);
    fwrite(&a, sizeof(amigo), 1, arq);
    fclose(arq);
    printf("\nAmigo cadastrado com sucesso!\n");
}

void listar_amigos()
{
    FILE * arq;
    amigo a;
    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        printf("\nNao ha' nenhum amigo cadastrado\n");
        return;
    }
    printf("\n\nAmigos Cadastrados\n");
    printf("-----------------------------------------------------------\n");
    printf("Id  Nome                 Telefone         E-mail\n");
    printf("-----------------------------------------------------------\n");
    while (fread(&a, sizeof(amigo), 1, arq) > 0) {
        printf("%03d %-20.20s %-13s %s\n", a.id, a.nome, a.fone, a.email);
    }
    printf("-----------------------------------------------------------\n");
    fclose(arq);
}

void alterar_amigo(bool buscar_por_id)
{
    FILE * arq;
    amigo a;
    if ((arq = fopen(NOME_ARQ, "r+b")) == NULL) {
        printf("\nNao ha' nenhum amigo cadastrado!\n");
        return;
    }
    printf("\n\nAlterar um Amigo\n");    
    if (buscar_por_id) {
        int id;
        printf("Id: ");
        scanf("%d", &id);
        fseek(arq, (id - 1) * sizeof(amigo), SEEK_SET);
        fread(&a, sizeof(amigo), 1, arq);
        if (id < 1 || feof(arq)) {
            printf("\nErro: id nao encotrado (%d)!\n", id);
            return;
        }     
        printf("Nome: %s\n", a.nome);
    }
    else {
        char nome[40];
        printf("Nome: ");
        scanf(" %39[^\n]", nome);
        while (fread(&a, sizeof(amigo), 1, arq) > 0) {
            if (strcasecmp(a.nome, nome) == 0) {
                break;
            }
        }
        if (feof(arq)) {
            printf("Erro: nome nao encontrado (%s)!\n", nome);
            return;
        }
    }
    printf("Telefone atual: %s\n", a.fone);
    printf("Novo telefone: ");
    scanf(" %13[^\n]", a.fone);
    printf("E-mail atual: %s\n", a.email);
    printf("Novo e-mail: ");
    scanf(" %29[^\n]", a.email);
    fseek(arq, -sizeof(amigo), SEEK_CUR);
    fwrite(&a, sizeof(amigo), 1, arq);
    printf("\nAmigo atualizado com sucesso!\n");
    fclose(arq);
}


void consultar_amigo(bool buscar_por_id)
{
    FILE * arq;
    amigo a;
    if ((arq = fopen(NOME_ARQ, "r+b")) == NULL) {
        printf("\nNao ha' nenhum amigo cadastrado!\n");
        return;
    }
    printf("\n\nConsultar um Amigo\n");    
    if (buscar_por_id) {
        int id;
        printf("Id: ");
        scanf("%d", &id);
        fseek(arq, (id - 1) * sizeof(amigo), SEEK_SET);
        fread(&a, sizeof(amigo), 1, arq);
        if (id < 1 || feof(arq)) {
            printf("\nErro: id nao encotrado (%d)!\n", id);
            return;
        }  
        printf("Nome: %s\n", a.nome);
        printf("Telefone: %s\n", a.fone);
        printf("E-mail: %s\n", a.email);              
    }
    else {
        char nome[40];
        printf("Nome: ");
        scanf(" %39[^\n]", nome);
        printf("Amigos que comecam com nome %s\n", nome);
        printf("-----------------------------------------------------------\n");
        printf("Id  Nome                 Telefone         E-mail\n");
        printf("-----------------------------------------------------------\n");
        while (fread(&a, sizeof(amigo), 1, arq) > 0) {
            if (strncasecmp(a.nome, nome, strlen(nome)) == 0) {
                printf("%03d %-20.20s %-13s %s\n", a.id, a.nome, a.fone, a.email);                
            }
        }
        printf("-----------------------------------------------------------\n");
    }
    fclose(arq);
}
