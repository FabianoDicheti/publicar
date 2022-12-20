#include<stdio.h>
#include<stdlib.h>
# include <time.h>
# include <math.h>
#define INDEX0 1024
#define INDEX1 2048
#define INDEX2 4096
#define INDEX3 8192
#define INDEX4 16384
#define INDEX5 32768
#define AMOSTRA 100



float desvioPadrao(double vetor[]){
    double soma = 0.0, media, desvio = 0.0;
    for (int i = 0; i < AMOSTRA; ++i) {
        soma += (double)vetor[i];
    }
    media = soma / (double)AMOSTRA;
    for (int i = 0; i < AMOSTRA; ++i) {
        desvio += pow((double)vetor[i] - media, 2);
    }
    return sqrt(desvio / (double)AMOSTRA);
};



void vetorAleatorio(int *vetor, int tamanho){
    
    srand(time(0)); //seed
    int aux;
    for(int i = 0; i<tamanho; i++){
        aux = rand();
        vetor[i] = aux;
    
    }

};


struct noh{
    struct noh *prox;
    int valor;
    
} *primeiro = NULL;

void convListLigada(int vetor[], int tamanhoDaLista){
    struct noh *aux;
    struct noh *ultimo;
    primeiro = (struct noh *)malloc(sizeof(struct noh));
    primeiro->valor = vetor[0];
    primeiro->prox = NULL;
    ultimo = primeiro;
    
    for (int i = 1; i<tamanhoDaLista; i++){
        aux = (struct noh *)malloc(sizeof(struct noh));
        aux->valor = vetor[i];
        aux->prox = NULL;
        ultimo->prox = aux;
        ultimo = aux;
    }
};

void confere(struct noh *p){
    while(p != NULL){
        printf("%d ", p->valor);
        p = p->prox;
    }
};


void buscaSeqLigada(int chave, struct noh *primeiro){
    struct noh *p = primeiro;
    int cont = 0;
    while(p != NULL){
        if(p->valor == chave){
            printf("itm %d ,  ", cont);
            break;
        }
        cont++;
        p = p->prox;
    }
};



int main(){
    
    
    double mediaBusca0 = 0, mediaBusca1 = 0, mediaBusca2 = 0;
    double mediaBusca3 = 0, mediaBusca4 = 0, mediaBusca5 = 0;
    double TBusca0[AMOSTRA], TBusca1[AMOSTRA], TBusca2[AMOSTRA], TBusca3[AMOSTRA], TBusca4[AMOSTRA], TBusca5[AMOSTRA];
    
    printf("\n");
    printf("\n");
    int cont = INDEX0-1;
    for(int i = 0; i < AMOSTRA; i++){
        
        int vetor[INDEX0];
        vetorAleatorio(vetor, INDEX0);
        clock_t inicS = clock();
        convListLigada(vetor,INDEX0);
        
        clock_t finalS = clock() - inicS;
        buscaSeqLigada(9999999, primeiro);
        
        double tGastoS = (((double)finalS) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca0 = mediaBusca0 + tGastoS;
        TBusca0[i] = tGastoS;
        cont = cont + 10;
    };
    
    printf("\n");
    printf("\n");
    int cont2 = INDEX1-1;
    for(int j = 0; j < AMOSTRA; j++){
        
        int vetor1[INDEX1];
        vetorAleatorio(vetor1, INDEX1);
        clock_t inicS1 = clock();
        convListLigada(vetor1,INDEX1);
        clock_t finalS1 = clock() - inicS1;
        
        buscaSeqLigada(9999999, primeiro);
        
        double tGastoS1 = (((double)finalS1) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca1 = mediaBusca1 + tGastoS1;
        TBusca1[j] = (double)tGastoS1;
        //cont2 = cont2 + 20;

    };
    printf("\n");
    printf("\n");
    
    int cont3 = INDEX2-1;
    for(int j = 0; j < AMOSTRA; j++){
        
        int vetor2[INDEX2];
        vetorAleatorio(vetor2, INDEX2);
        clock_t inicS2 = clock();
        convListLigada(vetor2,INDEX2);
        clock_t finalS2 = clock() - inicS2;
        
        buscaSeqLigada(9999999, primeiro);
        
        double tGastoS2 = (((double)finalS2) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca2 = mediaBusca2 + tGastoS2;
        TBusca2[j] = (double)tGastoS2;
        //cont3 = cont3 + 40;

    };
    
    printf("\n");
    printf("\n");
    
    int cont4 = INDEX3-1;
    for(int j = 0; j < AMOSTRA; j++){
        
        int vetor3[INDEX3];
        vetorAleatorio(vetor3, INDEX3);
        clock_t inicS3 = clock();
        convListLigada(vetor3,INDEX3);
        clock_t finalS3 = clock() - inicS3;
        
        buscaSeqLigada(9999999, primeiro);
        double tGastoS3 = (((double)finalS3) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca3 = mediaBusca3 + tGastoS3;
        TBusca3[j] = (double)tGastoS3;
        //cont4 = cont4 + 80;

    };
    
    printf("\n");
    printf("\n");
    
    int cont5 = INDEX4-1;
    for(int j = 0; j < AMOSTRA; j++){
        
        int vetor4[INDEX4];
        vetorAleatorio(vetor4, INDEX4);
        
        clock_t inicS4 = clock();
        convListLigada(vetor4,INDEX4);
        clock_t finalS4 = clock() - inicS4;
        
        
        buscaSeqLigada(9999999, primeiro);
        
        double tGastoS4 = (((double)finalS4) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca4 = mediaBusca4 + tGastoS4;
        TBusca4[j] = (double)tGastoS4;
        //cont5 = cont5 + 160;

    };
    
    
    printf("\n");
    printf("\n");
    
    int cont6 = INDEX5-1;
    for(int j = 0; j < AMOSTRA; j++){
        
        int vetor5[INDEX5];
        vetorAleatorio(vetor5, INDEX5);
        
        
        clock_t inicS5 = clock();
        convListLigada(vetor5,INDEX5);
        clock_t finalS5 = clock() - inicS5;
        
        
        buscaSeqLigada(9999999, primeiro);
        
        double tGastoS5 = (((double)finalS5) / CLOCKS_PER_SEC) * 1000000;
        mediaBusca5 = mediaBusca5 + tGastoS5;
        TBusca5[j] = (double)tGastoS5;
        //cont6 = cont6 + 320;

    };
    
    float desvioS0 = desvioPadrao(TBusca0);
    float desvioS1 = desvioPadrao(TBusca1);
    float desvioS2 = desvioPadrao(TBusca2);
    float desvioS3 = desvioPadrao(TBusca3);
    float desvioS4 = desvioPadrao(TBusca4);
    float desvioS5 = desvioPadrao(TBusca5);
    printf("\nconversao 2^10: %f", mediaBusca0);
    printf("\nnconversao 2^11: %f", mediaBusca1);
    printf("\nnconversao 2^12: %f", mediaBusca2);
    printf("\nnconversao 2^13: %f", mediaBusca3);
    printf("\nnconversao 2^14: %f", mediaBusca4);
    printf("\nconversao 2^15: %f", mediaBusca5);
    printf("\ndesvio  2^10 =  %f", desvioS0);
    printf("\ndesvio  2^11 =  %f", desvioS1);
    printf("\ndesvio  2^12 =  %f", desvioS2);
    printf("\ndesvio  2^13 =  %f", desvioS3);
    printf("\ndesvio  2^14 =  %f", desvioS4);
    printf("\ndesvio  2^15 =  %f", desvioS5);
    printf("\n");
    

    return 0;
}
