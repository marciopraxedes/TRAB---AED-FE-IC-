#include<stdio.h>

typedef struct Cliente {
    int codigo;
    char nome[250];
    char endereco[300];
    char telefone[10];
} Cliente;

/*
 * Cria uma struct Cliente com entradas digitadas pelo usuario
 * Retorno: struct Cliente com atributos preenchidos
 * Parametro: struct Cliente vazio, com atributos nao preenchidos
 */
Cliente gravarCliente(Cliente C) {
    printf("\nEntre com o codigo do cliente: ");
    scanf("%d", &C.codigo);
    printf("\nEntre com o nome do cliente: ");
    gets(C.nome);
    gets(C.nome);
    printf("\nEntre com o endereco do cliente: ");
    gets(C.endereco);
    printf("\nEntre com o telefone do cliente: ");
    gets(C.telefone);
    return C;
}

/*
 * Mostra na tela os atributos de um struct Cliente
 * Retorno: void
 * Parametro: struct Cliente com atributos preenchidos
 */
void carregarCliente(Cliente C) {
    printf("\nCliente: %s\n", C.nome);
    printf("Codigo: %s\n", C.codigo);
    printf("Endereco: %s\n", C.endereco);
    printf("Telefone: %s\n\n", C.telefone);
}

/*
 * Grava num arquivo chamado "clientes.txt" um struct cliente com atributos digitados pelo usuário
 * Retorno: void
 * Parametro: um struct Cliente vazio, com atributos nao preenchidos
 */
void gravarClienteNoArquivo(Cliente C) {
    FILE *arquivo = fopen("cliente.txt", "w");

    if(arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        Cliente Cli = gravarCliente(C);
        fprintf(arquivo, "%d %s %s %s\n", Cli.codigo, Cli.nome, Cli.endereco, Cli.telefone);
        fclose(arquivo);
    }
}

/*
 * Carrega de um arquivo formatado
 * Retorno: um struct Cliente com atributos preenchidos
 * Parametro: um struct Cliente vazio, com atributos nao preenchidos
 */
void carregarClienteDoArquivo(Cliente C) {
    FILE *arquivo = fopen("cliente.txt", "r");

    if(arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        while( (fscanf(arquivo, "%s %s %s %s", C.codigo, C.nome, C.endereco, C.telefone))!=EOF ) {
            carregarCliente(C);
        }
        fclose(arquivo);
    }
}

void carregarClientesDoArquivo(Cliente *c) {
    FILE *arq = fopen("cliente.txt", "r");
    int i = 0;

    if(arq == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        while( (fscanf(arq, "%d %s %s %s", &c[i].codigo, &c[i].nome, &c[i].endereco, &c[i].telefone))!=EOF ) {
            i++;
        }
        fclose(arq);
    }
    return *c;
}

void cadastrarCliente() {
    FILE *arquivo = fopen("cliente.txt", "a");
    Cliente C;

    if(arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        Cliente Cli = gravarCliente(C);
        fprintf(arquivo, "%d %s %s %s\n", Cli.codigo, Cli.nome, Cli.endereco, Cli.telefone);
        fclose(arquivo);
    }
}

int main() {
    Cliente c[5];

    carregarClientesDoArquivo(c);
    /* Cliente = gravarClienteNoArquivo(Cliente);
    printf("\n---------\nCliente salvo com sucesso!!\n---------\n");
    carregarClienteDoArquivo(Cliente);
    printf("\n---------\nCliente carregado com sucesso!!\n---------\n"); */


    return 0;
}
