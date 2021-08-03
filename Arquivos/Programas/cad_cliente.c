#include <stdio.h>

#define NOME_ARQ "conta.dat"

typedef struct {
    int num_conta;
    char nome[60];
    float saldo;
} cliente;

void cadastrar_cliente(void);
void listar_clientes(void);
void depositar(void);

int main()
{
    int op;
    do {
        printf("\nCADASTRO DE CLIENTES\n");
        printf("<1> Cadastrar um cliente\n");
        printf("<2> Listar clientes\n");
        printf("<3> Realizar um deposito\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                cadastrar_cliente();
                break;
            case 2:
                listar_clientes();
                break;
            case 3:
                depositar();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}

void depositar()
{
    int num_conta;
    float valor;
    cliente c;
    FILE * arq;
    if ((arq = fopen(NOME_ARQ, "r+b")) == NULL) {
        printf("\nNao ha' nenhuma conta cadastrada!\n");
        return;
    }
    printf("\n\nDeposito\n");
    printf("Numero da conta: ");
    scanf("%d", &num_conta);
    fseek(arq, (num_conta - 1) * sizeof(cliente), SEEK_SET);
    fread(&c, sizeof(cliente), 1, arq);
    if (num_conta > 0 && !feof(arq)) {
        printf("Nome do cliente: %s\n", c.nome);
        printf("Saldo da conta.: R$ %.2f\n", c.saldo);
        printf("Valor do deposito: R$ ");
        scanf("%f", &valor);
        c.saldo += valor;
        fseek(arq, -sizeof(cliente), SEEK_CUR); // volta o indicador de posição para a estrutura anterior
        fwrite(&c, sizeof(cliente), 1, arq);
        printf("\nDeposito realizado com sucesso!\nSaldo atual: R$ %.2f\n", c.saldo);
    }
    else {
        printf("\nErro: nao ha' nenhuma conta com esse numero (%d)!\n", num_conta);
    }
    fclose(arq);    
}

void cadastrar_cliente()
{
    cliente c;
    FILE * arq;
    if ((arq = fopen(NOME_ARQ, "ab")) == NULL) {
        fprintf(stderr, "\nErro de abertura do arquivo %s!\n", NOME_ARQ);
        return;
    }
    fseek(arq, 0, SEEK_END); // leva o indicador de posição para o final do arquivo
    c.num_conta = ftell(arq) / sizeof(cliente) + 1;
    printf("\n\nNovo Cliente\n");
    printf("Numero da conta: %d\n", c.num_conta);
    printf("Nome do cliente: ");
    scanf(" %59[^\n]", c.nome);
    printf("Saldo da conta.: R$ ");
    scanf("%f", &c.saldo);
    fwrite(&c, sizeof(cliente), 1, arq);
    fclose(arq);
    printf("\nCliente cadastrado com sucesso!\n");
}

void listar_clientes()
{
    cliente c;
    FILE * arq;
    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        printf("\nNao há nenhum cliente cadastrado!\n");
        return;
    }
    printf("\n\n\tClientes Cadastrados\n");
    printf("-------------------------------------------\n");
    printf("#Conta Nome do Cliente            Saldo\n");
    printf("-------------------------------------------\n");
    while (fread(&c, sizeof(cliente), 1, arq) > 0) {
        printf("%06d %-25.25s %10.2f\n", c.num_conta, c.nome, c.saldo);
    }
    printf("-------------------------------------------\n");
    fclose(arq);
}