/*
5. Considere que exista uma estrutura com os seguintes membros: codigo_cliente e
nome_cliente e uma outra estrutura com os seguintes membros: num_compra ,
valor_compra , codigo_cliente . Faça um programa que:
Inclua clientes, não permitindo que dois clientes possuam o mesmo código;
Inclua compras, verificando se o código do cliente informado já está cadastrado. Caso não
esteja, não permita a inclusão. O número da compra deve ser um número sequencial gerado
pelo programa;
Liste todos os clientes cadastrados;
Liste todas as compras de um determinado cliente, dado seu código;
Remova um determinado cliente. Antes de executar a remoção, verifique se o cliente possui
alguma compra. Se possuir, mostrar a mensagem “Exclusão não permitida”. Caso contrário,
proceder a exclusão.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_CLIENTES 10
#define MAX_COMPRAS 100

typedef struct {
    int codigo_cliente;
    char nome_cliente[41];
} cliente;

typedef struct {
    int num_compra;
    float valor_compra;
    int codigo_cliente;
} compra;

int procurar_cliente(int, const cliente [], int);
void cadastrar_cliente(int *, cliente []);
void cadastrar_compra(int *, compra [], int, const cliente []);
void listar_clientes(int, const cliente []);
void listar_compras_cliente(int, const compra [], int, const cliente []);
bool cliente_comprou(int, const compra [], int);
void remover_cliente(int *, cliente [], int, const compra []);

int main()
{
    int op, num_clientes = 0, num_compras = 0;
    cliente clientes[MAX_CLIENTES];
    compra compras[MAX_COMPRAS];
    do {
        printf("\n\tPonto de Venda\n");
        printf("<1> Cadastrar um cliente\n");
        printf("<2> Listar os clientes\n");
        printf("<3> Cadastrar uma compra\n");
        printf("<4> Listar compras do cliente\n");
        printf("<5> Remover um cliente\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                cadastrar_cliente(&num_clientes, clientes);
                break;
            case 2:
                listar_clientes(num_clientes, clientes);
                break;
            case 3:
                cadastrar_compra(&num_compras, compras, num_clientes, clientes);
                break;
            case 4:
                listar_compras_cliente(num_compras, compras, num_clientes, clientes);
                break;
            case 5:
                remover_cliente(&num_clientes, clientes, num_compras, compras);
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}

int procurar_cliente(int n_cliente, const cliente clientes[], int cod_cliente)
{
    for (int i = 0; i < n_cliente; i++) {
        if (clientes[i].codigo_cliente == cod_cliente) {
            return i;
        }
    }
    return -1;
}

void cadastrar_cliente(int * n_clientes, cliente clientes[])
{
    if (*n_clientes < MAX_CLIENTES) {
        printf("\nNovo Cliente\n");
        printf("Codigo: ");
        scanf("%d", &clientes[*n_clientes].codigo_cliente);
        if (procurar_cliente(*n_clientes, clientes, clientes[*n_clientes].codigo_cliente) == -1) {
            printf("Nome..: ");
            scanf(" %40[^\n]", clientes[*n_clientes].nome_cliente);
            (*n_clientes)++;
            printf("\nCliente cadastrado com sucesso!\n");
        }
        else {
            printf("\nErro: ja' existe um cliente cadastrado com esse codigo!\n");
        }
    }
    else {
        printf("\nErro: nao e' possivel cadastrar mais nenhum cliente!\n");
    }
}

void cadastrar_compra(int * n_compras, compra compras[], int n_clientes, const cliente clientes[])
{
    if (*n_compras < MAX_COMPRAS) {
        int index;
        printf("\nNova Compra\n");
        compras[*n_compras].num_compra = *n_compras + 1;
        printf("Numero da compra: %d\n", compras[*n_compras].num_compra);
        printf("Codigo do cliente: ");
        scanf("%d", &compras[*n_compras].codigo_cliente); 
        while ((index = procurar_cliente(n_clientes, clientes, compras[*n_compras].codigo_cliente)) == -1) {
            printf("Erro: nao existe nenhum cliente cadastrado com este codigo!\n");
            printf("Codigo do cliente (-1 p/ cancelar): ");
            scanf("%d", &compras[*n_compras].codigo_cliente); 
            if (compras[*n_compras].codigo_cliente == -1) {
                return;
            }
        }
        printf("Nome do cliente: %s\n", clientes[index].nome_cliente);
        printf("Valor da compra: R$ ");
        scanf("%f", &compras[*n_compras].valor_compra);
        (*n_compras)++;
        printf("\nCompra cadastrada com sucesso!\n");
    }
    else {
        printf("\nErro: nao e' possivel cadastrar mais nenhuma compra!\n");
    }
}

void listar_clientes(int n_clientes, const cliente clientes[])
{
    printf("\n\tClientes cadastrados\n");
    printf("-------------------------------------\n");
    printf("Codigo Nome\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < n_clientes; i++) {
        printf("%06d %-30.30s\n", clientes[i].codigo_cliente, 
                clientes[i].nome_cliente);
    }
    printf("-------------------------------------\n");
}

void listar_compras_cliente(int n_compras, const compra compras[], 
                            int n_clientes, const cliente clientes[])
{
    if (n_compras > 0) {
        int cod_cliente, index;
        printf("\nListar compra por cliente\n");
        printf("Codigo do cliente: ");
        scanf("%d", &cod_cliente);
        while ((index = procurar_cliente(n_clientes, clientes, cod_cliente)) == -1) {
            printf("Erro: nao existe nenhum cliente cadastrado com este codigo!\n");
            printf("Codigo do cliente (-1 p/ cancelar): ");
            scanf("%d", &cod_cliente); 
            if (cod_cliente == -1) {
                return;
            }
        }
        printf("\nCompras de cliente: %s\n", clientes[index].nome_cliente);
        if (cliente_comprou(n_compras, compras, cod_cliente)) {
            printf("------------------------\n");
            printf("Numero     Valor\n");
            printf("------------------------\n");
            for (int i = 0; i < n_compras; i++) {
                if (compras[i].codigo_cliente == cod_cliente) {
                    printf("%06d %10.2f\n", compras[i].num_compra, compras[i].valor_compra);
                }
            }
            printf("------------------------\n");
        }
        else {
            printf("\nEste cliente nao fez nenhuma compra!\n");
        }
    }
    else {
        printf("\nErro: nao ha' nenhuma compra castrada!\n");
    }

}

bool cliente_comprou(int n_compras, const compra compras[], int cod_cliente)
{
    for (int i = 0; i < n_compras; i++) {
        if (compras[i].codigo_cliente == cod_cliente) {
            return true;
        }
    }
    return false;
}

void remover_cliente(int * n_clientes, cliente clientes[],
                     int n_compras, const compra compras[])
{
    if (*n_clientes > 0) {
        int cod_cliente, index;
        printf("\nRemover um cliente\n");
        printf("Codigo do cliente: ");
        scanf("%d", &cod_cliente);
        while ((index = procurar_cliente(*n_clientes, clientes, cod_cliente)) == -1) {
            printf("Erro: nao existe nenhum cliente cadastrado com este codigo!\n");
            printf("Codigo do cliente (-1 p/ cancelar): ");
            scanf("%d", &cod_cliente); 
            if (cod_cliente == -1) {
                return;
            }
        }
        printf("Nome de cliente: %s\n", clientes[index].nome_cliente);
        if (!cliente_comprou(n_compras, compras, cod_cliente)) {
            for (int i = index; i < *n_clientes - 1; i++) {
                clientes[i] = clientes[i + 1];
            }
            (*n_clientes)--;
            printf("\nCliente removido com sucesso!\n");
        }
        else {
            printf("\nErro: nao e' possivel remover este cliente, pois ele fez compras!\n");
        }
    }
    else {
        printf("\nErro: nao ha' nenhum cliente cadastrado!\n");
    }    
}
