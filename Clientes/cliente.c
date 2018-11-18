#include<stdio.h>

typedef struct Cliente {
    int codigo;
    char nome[250];
    char endereco[300];
    char telefone[10];
} Cliente;

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

void carregarCliente(Cliente C) {
    printf("\nCliente: %s\n", C.nome);
    printf("Codigo: %s\n", C.codigo);
    printf("Endereco: %s\n", C.endereco);
    printf("Telefone: %s\n\n", C.telefone);
}

Cliente gravarClienteNoArquivo(Cliente C) {
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

int main() {
    Cliente Cliente;

    Cliente = gravarClienteNoArquivo(Cliente);
    printf("\n---------\nCliente salvo com sucesso!!\n---------\n");
    carregarClienteDoArquivo(Cliente);
    printf("\n---------\nCliente carregado com sucesso!!\n---------\n");
    return 0;
}
