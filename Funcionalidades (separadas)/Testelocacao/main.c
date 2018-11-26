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
int numeroLocacoes = 0;

void lerClientesArquivo(Cliente VetorClientes[]);
void lerFuncionariosArquivo(Funcionario VetorFuncionarios[]);
void lerVeiculosArquivo(Veiculo VetorVeiculos[]);
void lerLocacoesArquivo(Locacao VetorLocacoes[]);

void carregarClientes(Cliente VetorClientes[]);
void carregarFuncionarios(Funcionario VetorFuncionarios[]);
void carregarVeiculos(Veiculo VetorVeiculos[]);
void carregarLocacoes(Locacao VetorLocacoes[]);

void cadastrarLocacao();

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    int opcao;

    printf("***** LocaMais - Sistema de Registro de Locacoes *****\n\n");

    do{
        printf("Escolha uma opcao do menu:\n");
        printf("0 - Fechar o programa\n");
        printf("1 - Cadastrar uma locacao\n");
        printf("2 - Dar baixa em uma locacao\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                cadastrarLocacao();
                break;
            case 2:

                break;
            case 0:
                printf("\nFim do programa!\n");
                break;
        }
    } while(opcao != 0);
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

void lerFuncionariosArquivo(Funcionario VetorFuncionarios[])
        {

            FILE *arquivo;
            arquivo = fopen("funcionarios.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (!feof(arquivo))  /* Enquando n�o chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 150, arquivo);/*Leitura de uma linha do arquivo...*/
                strSplit(linha, informacoes_linha, ";",5); /*Separa os campos e os armazena no vetor de 3 posi��es chamado informacoes_linha*/
                /*Cada posi��o do vetor VetorEmpregados guarda n�o so uma mas tres informa��es.*/
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

void  lerLocacoesArquivo(Locacao VetorLocacoes[])
        {
            struct tm data_ret = { 0 };
            struct tm data_dev = { 0 };
            FILE *arquivo;
            arquivo = fopen("locacoes.txt", "r");
            char linha[200];
            char *result;
            char * informacoes_linha[7];
            char * vetor_data[3];

            int i = 0;
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
        }


 void carregarLocacoes(Locacao VetorLocacoes[])
        {
			printf("\n***** Cadastro de Locacoes *****\n\n");
			int i;
            for (i = 0; i < numeroLocacoes; i++)
            {
                struct tm * ret;
                struct tm * dev;
                char bufRet[150], bufDev[150];
                ret = localtime(&VetorLocacoes[i].retirada);
                strftime(bufRet, 150, "%d/%m/%Y", ret);
                dev = localtime(&VetorLocacoes[i].devolucao);
                strftime(bufDev, 150, "%d/%m/%Y", dev);

                printf(" %d : %.2f : %s : %s : %d : %d : %d \n", VetorLocacoes[i].codigo,
                                             VetorLocacoes[i].seguro,
                                             bufRet,
                                             bufDev,
                                             VetorLocacoes[i].quantidadeDias,
                                             VetorLocacoes[i].codigoCliente,
                                             VetorLocacoes[i].codigoVeiculo);
            }
        }

void cadastrarLocacao() {
    Locacao locacao;
    Veiculo listaVeiculos[500];
    Cliente listaClientes[500];
    int i, j, mes, ano, ocupantes, totalVeiculos, teste, id;
    char nomeCliente[100];
    struct tm data_ret = { 0 };
    struct tm data_dev = { 0 };

    i = 0;
    teste = 0;

    lerClientesArquivo(listaClientes);
    lerVeiculosArquivo(listaVeiculos);

    printf("\nEntre com o nome do cliente: ");
    gets(nomeCliente);
    gets(nomeCliente);

    while(i < numeroClientes) {
        if(strncmp(nomeCliente, listaClientes[i].nome, strlen(nomeCliente)) == 0) {
            teste = 1;
            locacao.codigoCliente = listaClientes[i].codigo;
        }
        i++;
    }
    printf("\nteste numero %d\n", teste); /*teste*/

    if(teste == 0) {
        printf("\nCliente nao cadastrado. Efetue primeiro o cadastro do cliente.\n\n");
    } else {
        printf("\nO cliente precisa do veiculo a partir de quando?");
        printf("\nDia: ");
        scanf("%d", &data_ret.tm_mday);
        printf("Mes: ");
        scanf("%d", &mes);
        data_ret.tm_mon = mes - 1;
        printf("Ano: ");
        scanf("%d", &ano);
        data_ret.tm_year = ano - 1900;
        printf("\nAte quando o cliente pretende alugar o veiculo?");
        printf("\nDia: ");
        scanf("%d", &data_dev.tm_mday);
        printf("Mes: ");
        scanf("%d", &mes);
        data_ret.tm_mon = mes - 1;
        printf("Ano: ");
        scanf("%d", &ano);
        data_ret.tm_year = ano - 1900;
        printf("\nO cliente precisa de um veiculo para quantos ocupantes? ");
        scanf("%d", &ocupantes);

        locacao.retirada = mktime(data_ret);
        locacao.devolucao = mktime(data_dev);
        locacao.quantidadeDias = (locacao.retirada - locacao.devolucao) / SEGUNDOS_EM_UM_DIA;

        printf("\nteste veic %d\n", numeroVeiculos); /*teste*/

        printf("\nteste acesso arry %d\n", strncmp(listaVeiculos[i].status, "Disponivel", 10)); /*teste*/
        printf("\nLista de Veiculos Disponiveis:\n");
        printf("\nID\tModelo\tCor\tDiaria\tQtde de assentos\n");

        i = 0;
        while(i < numeroVeiculos) {
            if(ocupantes <= listaVeiculos[i].ocupantes && ( strncmp(listaVeiculos[i].status, "Disponivel", 10) == 0 ) ) {

                printf("%d\t", listaVeiculos[i].codigo);
                printf("%s\t", listaVeiculos[i].modelo);
                printf("%s\t", listaVeiculos[i].cor);
                printf("%.2f\t", listaVeiculos[i].diaria);
                printf("%d\n", listaVeiculos[i].ocupantes);
            }
            i++;
        }

        i = 0;
        teste = 0;
        while(teste == 0) {
            printf("\n\nEscolha um veiculo pelo ID informado na tabela: ");
            scanf("%d", &id);
            while(i < numeroVeiculos) {
                if(ocupantes <= listaVeiculos[i].ocupantes && (strncmp(listaVeiculos[i].status, "Disponivel", 10) == 0) && (id == listaVeiculos[i].codigo)) {
                    teste = 1;
                }
                i++;
            }
            if(teste == 0) {
                printf("O ID informado nao consta na tabela. Favor inserir um dos IDs listados.");
            } else {
                if(teste == 1) {
                    locacao.codigoVeiculo = 1;
                }
            }
        }

        /*Adiciona 50 reais ao valor do seguro, se optado*/
        teste = 0;
        while(teste != 1 && teste != 0) {
            printf("Deseja contratar o seguro do veiculo por R$ 50,00? (1 = Sim / 0 = Nao) ");
            scanf("%d", &teste);
            if(teste != 1 && teste != 0) {
                printf("Entre com uma resposta valida.");
            } else {
                if(teste == 1) {
                locacao.seguro = 50.00;
                } else {
                    if(teste == 0) {
                        locacao.seguro = 0;
                    }
                }
            }
        }


    }


}
