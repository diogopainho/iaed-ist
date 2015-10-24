
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define PASSAGEIROS 500

struct sVoo{
    
    int codigov;
    int horap;
    char codigoap;
    int horac;
    char codigoac;
    int numpassageiros;
    Dia dia;
    
    struct sVoo *Ant, *Prox;
    
};

typedef struct sVoo Voo;


typedef struct {
    
    int dd;
    int mm;
    int aaaa;
  
    
    
}Dia;

typedef struct sDia Dia;


struct sReserva {
    
    Dia dia;
    Voo voo;
    int codigor;
    int lugar;
    char *passageiro;
    
    struct sReserva *Ant, *Prox;
    
};

typedef struct sReserva Reserva;


int inserirVoo(Voo** voo, int codigov, int numpassageiros, int data, int horap, int codigoap, int horac, int codigoac){
       
    Voo *aux = *voo;
    /* Se a lista estiver vazia, aloca-se memoria*/
    
    if((*voo) == NULL)
    {
        (*voo) = (Voo*)malloc(sizeof(Voo));
        (*voo)->Ant = NULL;
        (*voo)->Prox = NULL;
        (*voo)->codigov = codigov;
        (*voo)->numpassageiros = numpassageiros;
        (*voo)->horap = horap;
        (*voo)->codigoap = codigoap;
        (*voo)->horac = horac;
        (*voo)->codigoac = codigoac;
        return 0;
    }
                   
  /* Novo no da lista*/
    
    Voo *newV = (Voo*)malloc(sizeof(Voo));
    
    
    
    newV->codigov = codigov;
    newV->numpassageiros = numpassageiros;
    newV->horap = horap;
    newV->codigoap = codigoap;
    newV->horac = horac;
    newV->codigoac = codigoac;
    newV->Prox = NULL;
    
    
    /*Percorrer a lista com o aux*/
    
    while (aux->Prox != NULL)
        aux = aux->Prox;
    
    if(aux == NULL)
        return -1;
    
    /*Se a alocacao foi bem feita, ja estamos no final da lista e vamos adicionar o "newNo"*/
    
    aux->Prox =newV;
    newV->Ant = aux;
    
}

/* Funcao que adiociona o voo numa determinada data*/

int inserirVoo_em_Data ( int codigov, int numpassageiros, int data, int horap, int codigoap, int horac, int codigoac){
    
    
    
    
}


void procurarVoo(int data, int codigoap, int codigoac){
    
    
    
}




void cancelarVoo(int data, int codigovoo){
    
    
    
}


void efectuarReserva(Reserva **reserva, int data, int codigor, int codigov, char* passageiro){
    
    Reserva *aux = *reserva;
    
    if(*reserva == NULL)
    {
        (*reserva) = (Reserva*)malloc(sizeof(Reserva));
        (*reserva)->Ant = NULL;
        (*reserva)->Prox = NULL;
        (*reserva)->codigor = codigor; /*Associar isto ha funcao do enunciado*/
        (*reserva)->passageiro = passageiro;
        (*reserva)->lugar += 1;
        return 0;
        
    }
    
Reserva *newR = (Reserva*)malloc(sizeof(Reserva));
    
    newR->Prox = NULL;
    newR->codigor = codigor; /*Associar isto ha funcao do enunciado*/
    newR->passageiro = passageiro;
    newR->lugar += 1;
    
    while(aux->Prox != NULL)
        aux = aux->Prox;
    
    
    if(aux == NULL)
        return 1;
    
    
    aux->Prox = newR;
    newR->Ant = aux;
}

void inserirReserva_em_Voo(Voo *voo, int data, int codigor, int codigov, char* passageiro){
    
    
    return efectuarReserva(&voo->reserva , data, codigor, codigov, passageiro); /*Ver como inserir a reserva num voo*/
}

void consultarReserva(int dia, int codigor){
    
    
}


void cancelarReserva(int codigor){
    
    
    
}


void listarPassageiros(int data, int codigov){
    
    
    
    
}








int main ()
{
    int operacao;
    int codigov;
    int numpassageiros;
    int dia; /*ver isto bem */
    int horap;
    int codigoap;
    int horac;
    int codigoac;
    char passageiro[41];
    int codigor;


    do
    {
        operacao = getchar();  /*Para ler o caracter e o espaco, tudo o resto que e dado no comando e lido nas respectivas funcoes*/
                
        switch (operacao) /*Consoante o comando selecciona as funcoes associadas*/
        
        {
            case 'r':
                scanf("%d %d %d %d %d %d %d", &codigov, &numpassageiros, &dia, &horap, &codigoap, &horac, &codigoac);
                inserirVoo(Dia* Dia, codigov, numpassageiros, dia, horap, codigoap, horac, codigoac)
                break;
                
            case 'f':
                scanf("%d %d %d", &dia, &codigoap, &codigoac);
                procurarVoo(dia, codigoap, codigoac);
                break;
            
            case 'b':
                scanf("%d %d %s", &dia, &codigov, passageiro);
                efectuarReserva(dia, codigov, passageiro);
                break;
            
            case 'v':
                scanf("%d", &codigor);
                consultarReserva(dia, codigor);
                break;
                
           
            case 'c':
                scanf("%d", &codigor);
                cancelarReserva(codigor);
                break;
            
            case 'l':
                scanf("%d %d", &dia, &codigor);
                consultarReserva(dia, codigor);
                break;
                
            case 'x':
                scanf("%d %d", &dia, &codigov);
                cancelarVoo(dia, codigov);
                break;
        }
        
               
        
    }
    while(operacao != EOF); /*Vai fazendo o ciclo ate ao fim do ficheiro*/

    return 0;
}

