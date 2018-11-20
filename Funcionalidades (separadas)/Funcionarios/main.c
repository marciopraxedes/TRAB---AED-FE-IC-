#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <iostream>

int main()
{

    setlocale(LC_ALL,"Portuguese");
    /*Esse programa irá executar toda parte de cadastro
    e leitura de dados de funcionários. Irá usar um banco de dados
    funcionarios.txt na pasta raiz do programa*/


    /*inicio - varíaveis do programa*/
    int i=0, qtd, codigo=0;
    char charCodigo[4]={0}, teste[10], nome[100], telefone[20], cargo[100], salario[20], algo[2];
    FILE *dbFunc;
    /*fim - varíaveis do programa*/

    /*abertura do programa para atualização a partir do final*/
    dbFunc = fopen("db-Funcionarios.txt","a+"); /*arquivo db.txt aberto modo gravação*/

    printf("Quantos funcionário deseja cadastrar? ");
    scanf("%d", &qtd);
    gets(algo);
    do
    {

    /*inicio-código*/

    fputs("Código: ", dbFunc);
    itoa(codigo, charCodigo, 10);
    /*Verifica se o código já existe*/
    teste = strcat("FU",codigo);

    if (teste == )

    fputs("FU", dbFunc);
    fputs(charCodigo, dbFunc);
    codigo++;
    /*fim-código*/
    fputc('\n',dbFunc);

    /*inicio-nome*/
    fputs("Nome do funcionário: ", dbFunc);
    printf("Digite o nome do funcionário: ");
    gets(nome);
    fputs(nome, dbFunc);
    /*fim-nome*/
    fputc('\n',dbFunc);

    /*inicio-telefone*/
    fputs("Telefone: ", dbFunc);
    printf("Digite o número do telefone: ");
    gets(telefone);
    fputs(telefone, dbFunc);
    /*fim-telefone*/

    fputc('\n',dbFunc);

    /*inicio-cargo*/
    fputs("Cargo: ", dbFunc);
    printf("Digite o cargo: ");
    gets(cargo);
    fputs(cargo, dbFunc);
    /*fim-cargo*/

    fputc('\n',dbFunc);

    /*inicio-salario*/
    fputs("Salário: ", dbFunc);
    printf("Digite o salário: ");
    gets(salario);
    fputs(salario, dbFunc);
    /*fim-cargo*/

    printf("\n\n");

    fputc('\n',dbFunc);
    fputc('\n',dbFunc);

    i++;
    } while ( i<qtd );
    return 0;
}
