#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct Funcionario{
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo [50];
    float salario;
}Funcionario;

int numeroFuncionarios = 0, total;

void lerFuncionariosArquivo(Funcionario VetorFuncionarios[]);
void ListaCompleta(Funcionario VetorFuncionarios[]);
void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);
void pesquisarFuncionario(Funcionario VetorFuncionarios[]);
void cadastrarFuncionario(Funcionario VetorFuncionarios[]);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opcao;
    Funcionario VetorFuncionarios[1000];
    lerFuncionariosArquivo(VetorFuncionarios);
    ListaCompleta(VetorFuncionarios);
    printf("\n 1 - para cadastrar um Funcionário: ");
    printf("\n 2 - para pesquisar um Funcionário: ");
    printf("\n\n Escolha uma opção: ");
    scanf("%d", &opcao);
    fflush(stdin);
    if (opcao == 1){
        cadastrarFuncionario(VetorFuncionarios);
    }
    if (opcao == 2){
        pesquisarFuncionario(VetorFuncionarios);
    }
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
            total = numeroFuncionarios;

        }


 void ListaCompleta(Funcionario VetorFuncionarios[])
        {
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

void cadastrarFuncionario(Funcionario VetorFuncionarios[]) {
    int i=0, qtd;
    Funcionario funcionario;
    FILE *cadastroFuncionarios = fopen("funcionarios.txt", "a");

    printf("Deseja cadastrar quantos? ");
    scanf("%d", &qtd);
    fflush(stdin);
    do
    {
    /*printf("Codigo: ");*/
    funcionario.codigo = total;
    printf("Nome: ");
    gets(funcionario.nome);
    printf("Cargo: ");
    gets(funcionario.cargo);
    printf("Telefone: ");
    gets(funcionario.telefone);
    printf("Salario: ");
    scanf("%f", &funcionario.salario);
    fflush(stdin);

    fprintf(cadastroFuncionarios, "\n%d;%s;%s;%s;%.2f", funcionario.codigo, funcionario.nome, funcionario.telefone, funcionario.cargo, funcionario.salario);
    i++;
    }while (i < qtd);

    fclose(cadastroFuncionarios);
}
pesquisarFuncionario(Funcionario VetorFuncionarios[]){

    char nomePesquisa[20];
    printf("Digite o nome do funcionário: ");
    gets(nomePesquisa);

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

            /*printf("Nome: %s", VetorFuncionarios[6].nome); teste*/
            /*printf("\nTotal de cadastros: %d\n", numeroFuncionarios);*teste*/

    for ( i=0 ; i < numeroFuncionarios ; i++)
    {
        if  (strcmp(nomePesquisa,VetorFuncionarios[i].nome)==0)
        {
                printf(" %d : %s : %s : %s : %.2f\n", VetorFuncionarios[i].codigo,
                                                      VetorFuncionarios[i].nome,
                                                      VetorFuncionarios[i].telefone,
                                                      VetorFuncionarios[i].cargo,
                                                      VetorFuncionarios[i].salario);
        }

    }
    printf("\n\nFim do programa aqui na pesquisa!\n\n");
}
