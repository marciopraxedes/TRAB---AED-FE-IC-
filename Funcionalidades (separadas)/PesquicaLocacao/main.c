#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define SEGUNDOS_EM_UM_DIA 86400

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

typedef struct Locacao{
    int codigo;
    time_t retirada; /* atributos do tipo time_t sao atributos de DATA */
    time_t devolucao;
    float seguro;
    int quantidadeDias;
    int codigoCliente;
    int codigoVeiculo;
} Locacao;

    int numeroLocacoes = 0;
    int numeroVeiculos = 0;
    int numeroClientes = 0;

    void pesquisarLocacao(Locacao VetorLocacoes[]);
    void lerClientesArquivo(Cliente VetorClientes[]);
    void carregarClientes(Cliente VetorClientes[]);
    void lerLocacoesArquivo(Locacao VetorLocacoes[]);
    void carregarLocacoes(Locacao VetorLocacoes[]);
    void lerVeiculosArquivo(Veiculo VetorVeiculos[]);
    void carregarVeiculos(Veiculo VetorVeiculos[]);

    void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    setlocale(LC_ALL, "portuguese");
    Locacao VetorLocacoes[1000];
    Cliente VetorClientes[1000];
    Veiculo VetorVeiculos[1000];

    lerClientesArquivo(VetorClientes);
    carregarClientes(VetorClientes);
    pesquisarLocacao(VetorLocacoes);


    printf("\n\nFim do programa!");
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

void pesquisarLocacao(Locacao VetorLocacoes[]){

    int i,codigoPesquisa;

    printf("\n\n\nDigite o CODIGO do cliente para pesquisar: ");
    scanf("%d", &codigoPesquisa);

            struct tm data_ret = { 0 };
            struct tm data_dev = { 0 };
            FILE *arquivo;
            arquivo = fopen("locacoes.txt", "r");
            char linha[200];
            char *result;
            char * informacoes_linha[7];
            char * vetor_data[3];

            i = 0;
            while (!feof(arquivo))  /* Enquando n�o chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 200, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",7); /*Separa os campos e os armazena no vetor de 3 posi��es chamado informacoes_linha*/
                /*Cada posi��o do vetor VetorEmpregados guarda n�o so uma mas tres informa��es.*/
                VetorLocacoes[i].codigo = atoi(informacoes_linha[0]);
                VetorLocacoes[i].seguro = atof(informacoes_linha[1]);
                /*Criacao de uma instancia de data de retirada*/
                strSplit(informacoes_linha[2], vetor_data, "/", 3);
                data_ret.tm_mday = atoi(vetor_data[0]);
                data_ret.tm_mon = atoi(vetor_data[1]) - 1;
                data_ret.tm_year = atoi(vetor_data[2]) - 1900;
                VetorLocacoes[i].retirada = mktime(&data_ret);
                /*Criacao de uma instancia de data de devolucao*/
                strSplit(informacoes_linha[3], vetor_data, "/", 3);
                data_dev.tm_mday = atoi(vetor_data[0]);
                data_dev.tm_mon = atoi(vetor_data[1]) - 1;
                data_dev.tm_year = atoi(vetor_data[2]) - 1900;
                VetorLocacoes[i].devolucao = mktime(&data_dev);

                VetorLocacoes[i].quantidadeDias = atoi(informacoes_linha[4]);
                VetorLocacoes[i].codigoCliente = atoi(informacoes_linha[5]);
                VetorLocacoes[i].codigoVeiculo = atoi(informacoes_linha[6]);

                i++;
            }
            numeroLocacoes = i;
    printf("\n");
    for ( i=0 ; i < numeroLocacoes ; i++)
    {
       if (codigoPesquisa == VetorLocacoes[i].codigoCliente)
       {
                struct tm * ret;
                struct tm * dev;
                char bufRet[150], bufDev[150];
                ret = localtime(&VetorLocacoes[i].retirada);
                strftime(bufRet, 150, "%d/%m/%Y", ret);
                dev = localtime(&VetorLocacoes[i].devolucao);
                strftime(bufDev, 150, "%d/%m/%Y", dev);

                printf("%d   %.2f\t%s\t%s\t%d\t%d\t%d\n", VetorLocacoes[i].codigo,
                                             VetorLocacoes[i].seguro,
                                             bufRet,
                                             bufDev,
                                             VetorLocacoes[i].quantidadeDias,
                                             VetorLocacoes[i].codigoCliente,
                                             VetorLocacoes[i].codigoVeiculo);
       }
    }
    printf("\n\nFim do programa na pesquisa!");
}


void  lerVeiculosArquivo(Veiculo VetorVeiculos[])
        {

            FILE *arquivo;
            arquivo = fopen("veiculos.txt", "r");
            char linha[150];
            char *result;
            char * informacoes_linha[8];
            int i = 0;
            while (!feof(arquivo))  /* Enquando n�o chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",8); /*Separa os campos e os armazena no vetor de 3 posi��es chamado informacoes_linha*/
                /*Cada posi��o do vetor VetorEmpregados guarda n�o so uma mas tres informa��es.*/
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


void lerClientesArquivo(Cliente VetorClientes[])
        {
            FILE *arquivo;
            char linha[100];
            char *result;
            char * informacoes_linha[4];
            int i =0;
            arquivo = fopen("clientes.txt", "r");
            while (!feof(arquivo))  /* Enquando n�o chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",4); /*Separa os campos e os armazena no vetor de 3 posi��es chamado informacoes_linha*/
                /*Cada posi��o do vetor VetorEmpregados guarda n�o so uma mas tres informa��es.*/
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
			int i;
			printf("\n***** Cadastro de Clientes *****\n\n");

            for (i = 0; i < numeroClientes; i++)
            {
                printf(" %d : %s : %s : %s\n", VetorClientes[i].codigo, VetorClientes[i].nome,VetorClientes[i].endereco, VetorClientes[i].telefone);
            }
}
