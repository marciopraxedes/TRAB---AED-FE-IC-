#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Cliente{
   int codigo;
   char nome[100];
   char endereco[100];
   char telefone [20];
}Cliente;

int numeroClientes = 0;
int total;

void lerClientesArquivo(Cliente VetorClientes[]);
void carregarClientes(Cliente VetorClientes[]);
void pesquisarCliente(Cliente VetorClientes[]);
void cadastrarCliente(Cliente VetorClientes[]);

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opcao;
    Cliente VetorClientes[1000];
    lerClientesArquivo(VetorClientes);
    carregarClientes(VetorClientes);
    printf("\n 1 - para cadastrar um Cliente: ");
    printf("\n 2 - para pesquisar um Cliente: ");
    printf("\n\n Escolha uma opção: ");
    scanf("%d", &opcao);
    fflush(stdin);
    if (opcao == 1){
        cadastrarCliente(VetorClientes);
    }
    if (opcao == 2){
        pesquisarCliente(VetorClientes);
    }
    printf("\nFim do programa!\n");
    return 0;
}

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr)
        {
            int i = 0;
            char * pch;

            pch = strtok (strTOsplit,strSeparet);
            for(i = 0;i < nArr;i++)
            {
                strArr[i] = pch;
                pch = strtok (NULL,strSeparet);
            }
        }

void  lerClientesArquivo(Cliente VetorClientes[])
        {

            FILE *arquivo;
            arquivo = fopen("clientes.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[4];
            int i =0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",4); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                VetorClientes[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorClientes[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(VetorClientes[i].endereco, (const char*)(informacoes_linha[2]) );
                strcpy(VetorClientes[i].telefone, (const char*)(informacoes_linha[3]) );

                i++;
            }
            numeroClientes = i;
            total = numeroClientes;
        }
void carregarClientes(Cliente VetorClientes[])
        {
			printf("\n***** Cadastro de Clientes *****\n\n");
			int i;
            for (i = 0; i < numeroClientes; i++)
            {
                printf(" %d : %s : %s : %s\n", VetorClientes[i].codigo, VetorClientes[i].nome,VetorClientes[i].endereco, VetorClientes[i].telefone);
            }
        }

cadastrarCliente()
{
    int i=0, qtd;
    Cliente cliente;
    FILE *cadastroClientes = fopen("clientes.txt", "a");

    printf("Deseja cadastrar quantos? ");
    scanf("%d", &qtd);
    fflush(stdin);
    do
    {
    /*printf("Codigo: ");*/
    cliente.codigo = total;
    printf("Nome: ");
    gets(cliente.nome);
    printf("Endereço: ");
    gets(cliente.endereco);
    printf("Telefone: ");
    gets(cliente.telefone);

    fprintf(cadastroClientes, "\n%d;%s;%s;%s;", cliente.codigo,
                                                    cliente.nome,
                                                    cliente.endereco,
                                                    cliente.telefone);
    i++;
    }while (i < qtd);

    fclose(cadastroClientes);
}

pesquisarCliente(Cliente VetorClientes[]){

    char nomePesquisa[20];
    printf("\n\nDigite o nome do cliente: ");
    gets(nomePesquisa);

            FILE *arquivo;
            arquivo = fopen("clientes.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[4];
            int i =0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",4); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                VetorClientes[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorClientes[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(VetorClientes[i].endereco, (const char*)(informacoes_linha[2]) );
                strcpy(VetorClientes[i].telefone, (const char*)(informacoes_linha[3]) );

                i++;
            }
            numeroClientes = i;

    for ( i=0 ; i < numeroClientes ; i++)
    {
        if  (strcmp(nomePesquisa,VetorClientes[i].nome)==0)
        {
                printf("\n %d : %s : %s : %s\n", VetorClientes[i].codigo,
                                                VetorClientes[i].nome,
                                                VetorClientes[i].endereco,
                                                VetorClientes[i].telefone);
        }

    }
    printf("\n\nFim do programa aqui na pesquisa!\n\n");
}

