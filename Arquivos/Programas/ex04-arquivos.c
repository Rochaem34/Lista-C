/*
4. A CETESP lhe contratou para implementar uma aplicação em C para manter em um arquivo
chamado “chuvas.dat”, o índice pluviométrico diário na região da Grande São Paulo. O
programa deve armazenar estruturas do tipo chuva , mostrada abaixo, neste arquivo. Além
de permitir esse cadastro, seu programa deve possuir uma opção que gere um arquivo do tipo
texto, chamado “dias_chuvosos.txt”, contendo, em cada linha, a data (no formato
dd/mm/aaaa) e o índice pluviométrico, separados por um espaço em branco, de todos os dias
de um determinado ano em que esse índice superou os 60 mm.
typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    data dt;
    int ind_pluviometrico;
} chuva;
*/

#include <stdio.h>
#include <ctype.h>

#define NOME_ARQ "chuvas.dat"
#define ARQ_CHUVOSOS "dias_chuvosos.txt"

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    data dt;
    int ind_pluviometrico;
} chuva;

void cadastrar_indice_pluviometrico(void);
void gerar_arquivo_dias_chuvosos(void);

int main()
{
    int op;
    do {
        printf("\n\nCETESP\n");
        printf("<1> Cadastrar indice pluviometrico\n");
        printf("<2> Gerar arquivo com dias chuvosos\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                cadastrar_indice_pluviometrico();
                break;
            case 2:
                gerar_arquivo_dias_chuvosos();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}

void cadastrar_indice_pluviometrico()
{
    FILE * arq;
    chuva c;
    char sn;
    if ((arq = fopen(NOME_ARQ, "ab")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ);
        return;
    }
    printf("\n\nCadastrar Indice Pluviometrico\n");
    do {
        printf("Data (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &c.dt.dia, &c.dt.mes, &c.dt.ano);
        printf("Indice pluviometrico (mm): ");
        scanf("%d", &c.ind_pluviometrico);
        fwrite(&c, sizeof(chuva), 1, arq);
        printf("\nIndice pluviometrico cadastrado com sucesso!\n");
        printf("\nCadastrar outro (S/N)? ");
        do {
            scanf(" %c", &sn);
            sn = toupper(sn);
        } while (sn != 'S' && sn != 'N');
    } while (sn == 'S');
    fclose(arq);
}

void gerar_arquivo_dias_chuvosos()
{
    FILE * in, * out;
    chuva c;
    int ano;
    if ((in = fopen(NOME_ARQ, "rb")) == NULL) {
        printf("\nNao ha' nenhum indice pluviometrico cadastrado!\n");
        return;
    }
    if ((out = fopen(ARQ_CHUVOSOS, "w")) == NULL) {
        printf("\nErro: nao foi possivel criar o arquivo %s\n", ARQ_CHUVOSOS);
        fclose(in);
        return;
    }
    printf("\n\nGerar arquivo de dias chuvosos\n");
    printf("Ano: ");
    scanf("%d", &ano);
    fprintf(out, "Dias chuvosos com mais de 60 mm no ano %d\n", ano);
    while (fread(&c, sizeof(chuva), 1, in) > 0) {
        if (c.dt.ano == ano && c.ind_pluviometrico > 60) {
            fprintf(out, "%02d/%02d/%4d %d mm\n", c.dt.dia, c.dt.mes, c.dt.ano, c.ind_pluviometrico);
        }
    }
    fclose(in);
    fclose(out);
    printf("\nArquivo %s gerado com sucesso!\n", ARQ_CHUVOSOS);
}