#include<stdio.h>
#include<string.h>

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
 * Mostra na tela os atributos de um vetor de structs Cliente
 * Retorno: void
 * Parametro: vetor de structs Cliente com atributos preenchidos
 */
void carregarClientes(Cliente *c, int tamanho) {
    int i;

    if(c != NULL) {
        for(i = 0; i < tamanho; i++) {
            printf("\nCadastro no. %d", i);
            printf("\nCliente: %s\n", c[i].nome);
            printf("Codigo: %s\n", c[i].codigo);
            printf("Endereco: %s\n", c[i].endereco);
            printf("Telefone: %s\n\n", c[i].telefone);
        }
    } else {
        printf("Cadastro vazio ou não existente.");
    }
}

/*
 * Grava num arquivo chamado "clientes.txt" um struct cliente com atributos digitados pelo usu�rio
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
 * Carrega um struct Cliente de um arquivo formatado
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

/*
 * Carrega um vetor de structs Cliente de um arquivo formatado
 * Retorno: um vetor de structs Cliente preenchido com structs Cliente carregados do arquivo
 * Parametro: um ponteiro que referencia um vetor vazio de structs Cliente
 */
Cliente carregarClientesDoArquivo(Cliente *c) {
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

/*
 * Cadastra um struct Cliente ao final do arquivo "cliente.txt"
 * Retorno: void
 */
void cadastrarCliente() {
    FILE *reader = fopen("cliente.txt", "r");
    FILE *writer = fopen("cliente.txt", "a");
    Cliente c;
    Cliente d;
    int i = 0;

    if(reader == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        printf("\n***** Cadastro de Clientes *****\n");
        printf("Codigo do novo cliente: ");
        scanf("%d", &c.codigo);

        /* conta quantas linhas tem o arquivo */
        while( (fscanf(reader, "%d %s %s %s", &d.codigo, &d.nome, &d.endereco, &d.telefone))!=EOF  ) {
            i++;
        }
        fclose(reader);
        /* cria um vetor de structs Cliente com um tamanho igual ao numero de linhas do arquivo */
        Cliente e[i];
        /* le o arquivo novamente, dessa vez capturando as informações contidas nele */
        reader = fopen("cliente.txt", "r");
        i = 0;
        while( (fscanf(reader, "%d %s %s %s", &e[i].codigo, &e[i].nome, &e[i].endereco, &e[i].telefone))!=EOF ) {
            i++;
        }
        /* compara os codigos dos clientes do cadastro com o codigo inserido pelo usuario */
        int j;
        int teste = 0;
        for(j = 0; j < i; j++) {
            if(c.codigo == e[j].codigo) {
                teste = 1;
                j = i;
            }
        }
        /* salva o funcionario novo apenas se o teste for false */
        if(teste == 0) {
            printf("Entre com o nome: ");
            scanf("%s", &c.nome);
            printf("\nEntre com o endereco(use o simbolo '_' ao inves de 'espaco': ");
            scanf("%s", &c.endereco);
            printf("\nEntre com o telefone: ");
            scanf("%s", &c.telefone);

            fprintf(writer, "\n%d %s %s %s", c.codigo, c.nome, c.endereco, c.telefone);
        } else {
            printf("ERRO! O codigo informado ja foi cadastrado");
        }
        fclose(writer);
    }
}

/*
 * Recebe um nome do usuario e procura ele no cadastro salvo no arquivo
 * retorno: void
 */
void pesquisaCliente() {
    FILE *reader = fopen("cliente.txt", "r");
    Cliente c, d;
    int i = 0;

    if(reader == NULL) {
        printf("Nao foi possivel abrir o arquivo");
    }
    else {
        printf("\n***** Pesquisar Cliente *****\n");
        printf("Entre com o nome do cliente: ");
        scanf("%s", &c.nome);

        /* conta quantas linhas tem o arquivo */
        while( (fscanf(reader, "%d %s %s %s", &d.codigo, &d.nome, &d.endereco, &d.telefone))!=EOF  ) {
            i++;
        }
        fclose(reader);
        /* cria um vetor de structs Cliente com um tamanho igual ao numero de linhas do arquivo */
        Cliente e[i];
        /* le o arquivo novamente, dessa vez capturando as informações contidas nele */
        reader = fopen("cliente.txt", "r");
        i = 0;
        while( (fscanf(reader, "%d %s %s %s", &e[i].codigo, &e[i].nome, &e[i].endereco, &e[i].telefone))!=EOF ) {
            i++;
        }
        /* compara os nomes dos clientes do cadastro com o nome inserido pelo usuario */
        int j = 0, teste = 0;
        while(j < i) {
            /* se os nomes forem iguais, para o loop */
            if(strncmp(c.nome, e[j].nome, strlen(c.nome)) == 0) {
                teste = 1;
                printf("\nCodigo: %d\n", e[j].codigo);
                printf("Nome: %s\n", e[j].nome);
                printf("Endereco: %s\n", e[j].endereco);
                printf("Telefone: %s\n", e[j].telefone);
                j = i;
            } else {
                j++;
            }
        }
        /* se o teste for false, exibe mensagem de erro */
        if(teste == 0) {
            printf("\nERRO! O nome procurado nao consta no cadastro.\n");
        }
    }
}

int main() {
    pesquisaCliente();
    return 0;
}
