#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DATA 1000
#define MOV_DATA 100
#define NUMCHAR 61


typedef struct {  /*Estrutura que define o tipo Movimento*/

    char tipo;
    int montante;
    char descricao[NUMCHAR];


}Movimento;

typedef struct {   /*Estrutura que define a data como sendo uma array da estrutura movimentos*/


    Movimento mov[MOV_DATA];
    int count;

} Dia;

Dia datas[MAX_DATA];  /*Array que guarda os dias*/


void adicionarMov(int montante,char tipo,char* descricao,int data) /* Funcao auxiliar do inserirMovimento (foi criada para nao haver repeticao de codigo) */
{
    int indice;

    Movimento m;
    m.montante=montante;
    m.tipo = tipo;
    strcpy(m.descricao, descricao);

    indice =  datas[data].count;
    datas[data].mov[indice]=m;
    datas[data].count++;

}

void inserirMovimento (int montante, int data, int periodicidade, char tipo, char descricao[NUMCHAR])
{
    adicionarMov(montante,tipo,descricao,data); /* Adiciona o movimento a respectiva data */

    if (periodicidade>0)
    {
        data+=periodicidade; /* Incrementa a data + periodo de forma a adicionar nas respectivas datas */
        while (data<MAX_DATA)
        {
            adicionarMov(montante, tipo, descricao, data);
            data+=periodicidade;
        }
    }

}


void listarMovimentos(int data)
{
    int i;

    for(i=0; i<datas[data].count; i++)
    {
        printf("%d %d %c %s \n" , i, datas[data].mov[i].montante, datas[data].mov[i].tipo, datas[data].mov[i].descricao);   /* Para o numero de movimentos(count)lista os movimentos de uma dada data */
    }

}

void removerMovimento (int data, int indice) /* Ao retirar o moviemento de valor indice copia o movimento seguinte para o movimento de valor indice, fazendo-o recursivamente*/
{
    int i;
    if (indice > datas[data].count - 1)
        printf("O indice indicado nao existe\n"); /*Pode estar aqui?*/
    else
    {
        /*printf("Count: %d indice: %d\n", datas[data].count, indice);*/
        datas[data].count = datas[data].count - 1;
        for (i=indice; i<datas[data].count; i++)
        {
            datas[data].mov[i]=datas[data].mov[i+1];
        }
    }

}

int calcularBalanco (int data) /* Calcula o balanco dos movimentos existentes naquela data guiando-se pelo count*/
{
    int balanco=0;
    int i;


    for (i=0; i<datas[data].count; i++)
    {

            if(datas[data].mov[i].tipo == 'r')
            {
                balanco += datas[data].mov[i].montante;

            }
            else if (datas[data].mov[i].tipo == 'd')
            {
                balanco -= datas[data].mov[i].montante;
            }
    }
    return balanco;
}


int validadeOrcamento (int valorminimo)   /* Está com um problema. Supostamente deve verificar o v entre todos os balancos por exemplo se o balanco do dia 1 mais*/
{                                         /* o balanco do dia 2 é maior que o valorminimo se o 1 e 2 mais o 3 e maior que o valorminimo e por ai adiante. */
    int i;
    int balancototal=0;

    for(i=0; i <MAX_DATA; i++)
    {
        balancototal += calcularBalanco(i);
    }

    if(balancototal>=valorminimo)
       {
           return 1;
       }
    else
        {
            return 0;
        }
}

int alterarMinimo()
{
    int valorminimo;
    scanf("%d", &valorminimo); /* Altera o valor minimo visto que e uma variavel global VER!!*/

    return valorminimo;
}

void dataComportavel(int data, int despesa, int valorminimo)
{
    int i;
    int balancoData=0;

    for(i=0; i <=data; i++)
    {
        balancoData += calcularBalanco(i);
    }
     if (balancoData - despesa >= valorminimo)
    printf ("%d\n", balancoData-despesa);
    else
    printf("Incomportavel\n");

}

void inicializarEstrutura() /* Serve para colocar o count/indice a 0 */
{
    int i;
    for (i=0; i<MAX_DATA; i++)
    {
        datas[i].count=0;
    }
}

int main()
{
    int valorminimo; /*Variavel global com o valor minimo que permite ser acedida por diversas funcoes*/
    char operacao; /*Variavel que guarda o comando introduzido pelo utilizador*/
    int montante;
    int data;
    int periodicidade;
    char tipo;
    char descricao[NUMCHAR];
    int indice;
    int despesa;

    int semPar;

    inicializarEstrutura();

    printf("Tem as seguintes opcoes:\n");
    printf("Inserir Movimento: i  montante | Data | Periodicidade | r/d | Descricao\n");
    printf("Listar movimentos numa data: l Data\n");
    printf("Remover um movimento: r  Data | Indice-do-Movimento\n");
    printf("Calcular balanco numa data: b Data\n");
    printf("Alterar o valor minimo do balanco: m Novo-Valor\n");
    printf("Verificar validade do orcamento: v\n");
    printf("Data em que uma determinada despesa se torna comportavel: w Data-a-considerar | Valor-da-despesa\n");
    printf("Digite o comando que pretende:\n");

    do
    {
        operacao = getchar();  

        semPar = getchar() == '\n';

        switch (operacao)

        {
            case 'i':
                scanf("%d %d %d %c %s", &montante, &data, &periodicidade, &tipo, descricao);
                inserirMovimento(montante, data, periodicidade, tipo, descricao);
                break;

            case 'l':
                scanf("%d", &data);
                listarMovimentos(data);
                break;
            case 'r':
                scanf("%d %d", &data, &indice);

                removerMovimento(data, indice);

                break;
            case 'b':
                scanf("%d", &data);
                printf("%d\n", calcularBalanco(data));
                break;

            case 'm':
                printf("Entrou no m.....\n");
                valorminimo = alterarMinimo();
                break;

            case 'v':
                if(validadeOrcamento(valorminimo) == 1)
                    printf("Valido \n");
                else
                    printf("Invalido \n");
                break;

            case 'w':
                scanf("%d", &data);
                scanf("%d", &despesa);
                dataComportavel(data, despesa, valorminimo);
                break;
        }

        if(!semPar)
            operacao=getchar();


    }
    while(operacao != EOF);


    return 0;
}
