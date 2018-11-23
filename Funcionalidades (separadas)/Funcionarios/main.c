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

    int numeroFuncionarios = 0;
    void carregarFuncionarios(Funcionarios vetorFuncionarios[]);
    void ListaCompleta(Funcionarios vetorFuncionarios[]);
    void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);

int main()
{
    Funcionarios vetorFuncionarios[1000];
    carregarFuncionarios(vetorFuncionarios);
    ListaCompleta(vetorFuncionarios);
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

            FILE *arquivo;
            arquivo = fopen("funcionarios.txt", "r");
            char linha[200];
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (!feof(arquivo))  /* Enquando não chegar no fim do arquivo..*/
            {
                result = *fgets (linha, 200, arquivo);/*Leitura de uma linha do arquivo...*/
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
        }


 void ListaCompleta(Funcionarios vetorFuncionarios[])
        {
			int i;
            for (i = 0; i < numeroFuncionarios; i++)
            {
                printf("%d : %s : %s : %s : %.2f \n", vetorFuncionarios[i].codigo, vetorFuncionarios[i].nome, vetorFuncionarios[i].telefone,vetorFuncionarios[i].cargo, vetorFuncionarios[i].salario);
            }
        }
