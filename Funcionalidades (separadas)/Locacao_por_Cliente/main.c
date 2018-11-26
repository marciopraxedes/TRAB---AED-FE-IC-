#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente{
   int codigo;
   char nome[100];
   char endereco[100];
   char telefone [20];
}Cliente;

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

typedef struct LocacaoPorCliente{
    char nomeCliente[100];
    char modeloVeiculo[20];
    char placa [10];
}LocacaoPorCliente;

    int numeroLocacoesClientes = 0;

    void lerLocacoesClienteArquivo(VetorLocacoesClientes);
    void ListaCompletaLocacoesClientes(VetorLocacoesClientes)

    void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    Funcionario VetorLocacoesClientes[1000];
    lerLocacoesClienteArquivo(VetorLocacoesClientes);
    ListaCompletaLocacoesClientes(VetorLocacoesClientes);
    printf("\nFim do programa!");
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
void  lerLocacoesClienteArquivo(LocacaoPorCliente VetorLocacoesClientes[])
        {

            FILE *arquivo;
            arquivo = fopen("LocacoesClientes.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[3];
            int i =0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",3); /*Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha*/
                /*Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.*/
                strcpy(VetorLocacoesClientes[i].nomeCliente, (const char*)(informacoes_linha[0]) );
                strcpy(VetorLocacoesClientes[i].modeloVeiculo, (const char*)(informacoes_linha[1]) );
                strcpy(VetorLocacoesClientes[i].placa, (const char*)(informacoes_linha[2]) );

                i++;
            }
            numeroLocacoesClientes = i;
            total = numeroLocacoesClientes;
        }
 void ListaCompletaLocacoesClientes(LocacaoPorCliente VetorLocacoesClientes[])
        {
			int i;
            for (i = 0; i < numeroFuncionarios; i++)
            {
                printf(" %d : %s : %s : %s : %.2f\n", VetorLocacoesClientes[i].nomeCliente,
                                                      VetorLocacoesClientes[i].modeloVeiculo,
                                                      VetorLocacoesClientes[i].placa)
            }
        }

