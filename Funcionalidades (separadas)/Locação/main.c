#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

 typedef struct Funcionarios{
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo [50];
    float salario;
 }Funcionarios;

  typedef struct Clientes{
    int codigo;
    char nome[100];
    char endereco[100];
    char telefone [20];
 }Clientes;

  typedef struct Veiculos{
    int codigo;
    char descricao[15];
    char modelo[20];
    char cor [15];
    char placa [10];
    char ocupantes [8];
    char status [15];
 }Veiculos;

    int numeroFuncionarios = 0;
    int numeroClientes = 0;
    int numeroVeiculos = 0;

    void carregarFuncionarios(Funcionarios vetorFuncionarios[]);
    void carregarClientes (Clientes vetorClientes[]);
    void carregarVeiculos (Veiculos vetorVeiculos[]);

    void ListaFuncionarios(Funcionarios vetorFuncionarios[]);
    void ListaClientes(Clientes vetorClientes[]);

    void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    Funcionarios vetorFuncionarios[1000];
    Clientes vetorClientes[1000];
    carregarFuncionarios(vetorFuncionarios);
    ListaFuncionarios(vetorFuncionarios);
    ListaClientes(vetorClientes);
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
void  carregarFuncionarios(Funcionarios vetorFuncionarios[])
        {

            FILE *arquivoFuncionario;
            arquivoFuncionario = fopen("funcionarios.txt", "r");
            char linha[200];
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (!feof(arquivoFuncionario))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 200, arquivoFuncionario);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",5); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                vetorFuncionarios[i].codigo = atoi(informacoes_linha[0]);
                strcpy(vetorFuncionarios[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(vetorFuncionarios[i].telefone, (const char*)(informacoes_linha[2]) );
                strcpy(vetorFuncionarios[i].cargo, (const char*)(informacoes_linha[3]) );
                vetorFuncionarios[i].salario = atof(informacoes_linha[4]);
                i++;
            }
            numeroFuncionarios = i;
            fclose(arquivoFuncionario);
        }

void  carregarClientes(Clientes vetorClientes[])
        {

            FILE *arquivoCliente;
            arquivoCliente = fopen("clientes.txt", "r");
            char linha[200];
            char *result;
            char * informacoes_linha[4];
            int i =0;
            while (!feof(arquivoCliente))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 200, arquivoCliente);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",4); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                vetorClientes[i].codigo = atoi(informacoes_linha[0]);
                strcpy(vetorClientes[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(vetorClientes[i].endereco, (const char*)(informacoes_linha[2]) );
                strcpy(vetorClientes[i].telefone, (const char*)(informacoes_linha[3]) );
                i++;
            }
            numeroClientes = i;
            fclose(arquivoCliente);
        }

 void ListaFuncionarios(Funcionarios vetorFuncionarios[])
        {
			int i;
            for (i = 0; i < numeroFuncionarios; i++)
            {
                printf("%d : %s : %s : %s : %.2f \n", vetorFuncionarios[i].codigo, vetorFuncionarios[i].nome, vetorFuncionarios[i].telefone,vetorFuncionarios[i].cargo, vetorFuncionarios[i].salario);
            }
        }
 void ListaClientes(Clientes vetorClientes[])
        {
			int i;
            for (i = 0; i < numeroClientes; i++)
            {
                printf("%d : %s : %s : %s \n", vetorClientes[i].codigo, vetorClientes[i].nome, vetorClientes[i].endereco,vetorClientes[i].telefone);
            }
        }
