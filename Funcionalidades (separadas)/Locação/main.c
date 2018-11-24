#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct Cliente{
   int codigo;
   char nome[100];
   char endereco[100];
   char telefone [20];
}Cliente;

typedef struct Funcionario{
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo [50];
    float salario;
}Funcionario;

typedef struct Veiculo{
    int codigo;
    char descricao[20];
    char modelo[20];
    char cor [20];
    char placa [10];
    float diaria;
    int ocupantes;
    char status [15];
} Veiculo;

typedef struct Locacao{
    int codigo;
    time_t retirada; /* atributos do tipo time_t sao atributos de DATA */
    time_t devolucao;
    float seguro;
    int quantidadeDias;
    int codigoCliente;
    int codigoVeiculo;
} Locacao;

int numeroClientes = 0;
int numeroFuncionarios = 0;
int numeroVeiculos = 0;

void lerClientesArquivo(Cliente VetorClientes[]);
void lerFuncionariosArquivo(Funcionario VetorFuncionarios[]);
void lerVeiculosArquivo(Veiculo VetorVeiculos[]);

void carregarClientes(Cliente VetorClientes[]);
void carregarFuncionarios(Funcionario VetorFuncionarios[]);
void carregarVeiculos(Veiculo VetorVeiculos[]);

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    Cliente VetorClientes[1000];
    lerClientesArquivo(VetorClientes);
    carregarClientes(VetorClientes);

    Funcionario VetorFuncionarios[1000];
    lerFuncionariosArquivo(VetorFuncionarios);
    carregarFuncionarios(VetorFuncionarios);

    Veiculo VetorVeiculos[1000];
    lerVeiculosArquivo(VetorVeiculos);
    carregarVeiculos(VetorVeiculos);

    printf("Fim do programa!\n");
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

void  lerFuncionariosArquivo(Funcionario VetorFuncionarios[])
        {

            FILE *arquivo;
            arquivo = fopen("funcionarios.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",5); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                VetorFuncionarios[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorFuncionarios[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(VetorFuncionarios[i].telefone, (const char*)(informacoes_linha[2]) );
                strcpy(VetorFuncionarios[i].cargo, (const char*)(informacoes_linha[3]) );
                VetorFuncionarios[i].salario = atof(informacoes_linha[4]);

                i++;
            }
            numeroFuncionarios = i;
        }


 void carregarFuncionarios(Funcionario VetorFuncionarios[])
        {
			printf("\n***** Cadastro de Funcionarios *****\n\n");
			int i;
            for (i = 0; i < numeroFuncionarios; i++)
            {
                printf(" %d : %s : %s : %s : %.2f\n", VetorFuncionarios[i].codigo,
                                                      VetorFuncionarios[i].nome,
                                                      VetorFuncionarios[i].telefone,
                                                      VetorFuncionarios[i].cargo,
                                                      VetorFuncionarios[i].salario);
            }
        }

void  lerVeiculosArquivo(Veiculo VetorVeiculos[])
        {

            FILE *arquivo;
            arquivo = fopen("veiculos.txt", "r");
            char linha[150];
            char *result;
            char * informacoes_linha[8];
            int i = 0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",8); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                VetorVeiculos[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorVeiculos[i].descricao, (const char*)(informacoes_linha[1]) );
                strcpy(VetorVeiculos[i].modelo, (const char*)(informacoes_linha[2]) );
                strcpy(VetorVeiculos[i].cor, (const char*)(informacoes_linha[3]) );
                strcpy(VetorVeiculos[i].placa, (const char*)(informacoes_linha[4]) );
                VetorVeiculos[i].diaria = atof(informacoes_linha[5]);
                VetorVeiculos[i].ocupantes = atoi(informacoes_linha[6]);
                strcpy(VetorVeiculos[i].status, (const char*)(informacoes_linha[7]) );

                i++;
            }
            numeroVeiculos = i;
        }


 void carregarVeiculos(Veiculo VetorVeiculos[])
        {
			printf("\n***** Cadastro de Veiculos *****\n\n");
			int i;
            for (i = 0; i < numeroVeiculos; i++)
            {
                printf(" %d : %s : %s : %s : %s : %.2f : %d : %s \n", VetorVeiculos[i].codigo,
                                             VetorVeiculos[i].descricao,
                                             VetorVeiculos[i].modelo,
                                             VetorVeiculos[i].cor,
                                             VetorVeiculos[i].placa,
                                             VetorVeiculos[i].diaria,
                                             VetorVeiculos[i].ocupantes,
                                             VetorVeiculos[i].status);
            }
        }
