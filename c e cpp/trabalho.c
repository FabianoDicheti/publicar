# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <math.h>
#define INDEX0 1024
#define INDEX1 2048
#define INDEX2 4096
#define INDEX3 8192
#define INDEX4 16384
#define INDEX5 32768
#define AMOSTRA 100


int comparaqsort(const void * a, const void * b);

int sequencial(int vetor[], int tam, int chave);

int saltos(int vetor[], int tamanho, int chave);

int binaria(int vetor[], int tam, int chave);

int particiona(int *vetor, int esquerda, int direita);

void quicksort(int *vetor, int esquerda, int direita); // pior

void vetorAleatorio(int *vetor, int tamanho);

void imprime(int *vetor, int tamanho);

float desvioPadrao(float vetor[]){
    double soma = 0.0, media, desvio = 0.0;
    for (int i = 0; i < AMOSTRA; ++i) {
        soma += (double)vetor[i];
    }
    media = soma / (double)AMOSTRA;
    for (int i = 0; i < AMOSTRA; ++i) {
        desvio += pow((double)vetor[i] - media, 2);
    }
    return sqrt(desvio / (double)AMOSTRA);
}




int main(){

    double mediaSequencial0 = 0, mediaSequencial1 = 0, mediaSequencial2 = 0;
    double mediaSequencial3 = 0, mediaSequencial4 = 0, mediaSequencial5 = 0;
    double LDS0[AMOSTRA], LDS1[AMOSTRA], LDS2[AMOSTRA], LDS3[AMOSTRA], LDS4[AMOSTRA], LDS5[AMOSTRA];

    double mediaSaltos0 = 0, mediaSaltos1 = 0, mediaSaltos2 = 0;
    double mediaSaltos3 = 0, mediaSaltos4 = 0, mediaSaltos5 = 0;
    double LDJ0[AMOSTRA], LDJ1[AMOSTRA], LDJ2[AMOSTRA], LDJ3[AMOSTRA], LDJ4[AMOSTRA], LDJ5[AMOSTRA];
    double custoSalto0 = 0, custoSalto1 = 0, custoSalto2 = 0;
    double custoSalto3 = 0, custoSalto4 = 0, custoSalto5 = 0;


    double mediaBinaria0 = 0, mediaBinaria1 = 0, mediaBinaria2 = 0;
    double mediaBinaria3 = 0, mediaBinaria4 = 0, mediaBinaria5 = 0;
    double LDB0[AMOSTRA], LDB1[AMOSTRA], LDB2[AMOSTRA], LDB3[AMOSTRA], LDB4[AMOSTRA], LDB5[AMOSTRA];
    double custoBinaria0 = 0, custoBinaria1 = 0, custoBinaria2 = 0;
    double custoBinaria3 = 0, custoBinaria4 = 0, custoBinaria5 = 0;

    double mediaSeqOrd0 = 0, mediaSeqOrd1 = 0, mediaSeqOrd2 = 0;
    double mediaSeqOrd3 = 0, mediaSeqOrd4 = 0, mediaSeqOrd5 = 0;
    double LDO0[AMOSTRA], LDO1[AMOSTRA], LDO2[AMOSTRA], LDO3[AMOSTRA], LDO4[AMOSTRA], LDO5[AMOSTRA];
    double custoSO0 = 0, custoSO1 = 0, custoSO2 = 0;
    double custoSO3 = 0, custoSO4 = 0, custoSO5 = 0;
    
    int cont = 10;
    for(int i = 0; i < AMOSTRA; i++){
        
        int vetor[INDEX0];

        vetorAleatorio(vetor, INDEX0);
        clock_t inicS = clock();
        sequencial(vetor, INDEX0, vetor[cont]);
        clock_t finalS = clock() - inicS;
        double tGastoS = (((double)finalS) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial0 = mediaSequencial0 + tGastoS;
        LDS0[i] = tGastoS;
        
        vetorAleatorio(vetor, INDEX0);
        clock_t inicCJ = clock();
        qsort(vetor, INDEX0, sizeof(int), comparaqsort);
        clock_t finalCJ = clock() - inicCJ;
        double tGastoCJ = (((double)finalCJ) / CLOCKS_PER_SEC) * 1000000;
        custoSalto0 = custoSalto0 + tGastoCJ;
        clock_t inicJ = clock();
        saltos(vetor, INDEX0, vetor[cont]);
        clock_t finalJ = clock() - inicJ;
        double tGastoJ = (((double)finalJ) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos0 = mediaSaltos0 + tGastoJ;
        LDJ0[i] = tGastoJ;

        vetorAleatorio(vetor, INDEX0);
        clock_t inicCB = clock();
        qsort(vetor, INDEX0, sizeof(int), comparaqsort);
        clock_t finalCB = clock() - inicCB;
        double tGastoCB = (((double)finalCB) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria0 = custoBinaria0 + tGastoCB;  
        clock_t inicB = clock();
        binaria(vetor, INDEX0, vetor[cont]);
        clock_t finalB = clock() - inicB;
        double tGastoB = (((double)finalB) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria0 = mediaBinaria0 + tGastoB;
        LDB0[i] = tGastoB;

        vetorAleatorio(vetor, INDEX0);
        clock_t inicCSO = clock();
        qsort(vetor, INDEX0, sizeof(int), comparaqsort);
        clock_t finalCSO = clock() - inicCSO;
        double tGastoCSO = (((double)finalCSO) / CLOCKS_PER_SEC) * 1000000;
        custoSO0 = custoSO0 + tGastoCSO;  
        clock_t inicO = clock();
        sequencial(vetor, INDEX0, vetor[cont]);
        clock_t finalO = clock() - inicO;
        double tGastoO = (((double)finalO) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd0 = mediaSeqOrd0 + tGastoO;
        LDO0[i] = tGastoO;


        cont = cont + 10;
    }

// INDEX 1

    cont = 20;
    for(int i = 0; i < AMOSTRA; i++){
        
        int vetor1[INDEX1];

        vetorAleatorio(vetor1, INDEX1);
        clock_t inicS1 = clock();
        sequencial(vetor1, INDEX1, vetor1[cont]);
        clock_t finalS1 = clock() - inicS1;
        double tGastoS1 = (((double)finalS1) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial1 = mediaSequencial1 + tGastoS1;
        LDS1[i] = (double)tGastoS1;

        vetorAleatorio(vetor1, INDEX1);
        clock_t inicCB1 = clock();
        qsort(vetor1, INDEX1, sizeof(int), comparaqsort);
        clock_t finalCB1 = clock() - inicCB1;
        double tGastoCB1 = (((double)finalCB1) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria1 = custoBinaria1 + tGastoCB1;
        clock_t inicB1 = clock();
        binaria(vetor1, INDEX1, vetor1[cont]);
        clock_t finalB1 = clock() - inicB1;
        double tGastoB1 = (((double)finalB1) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria1 = mediaBinaria1 + tGastoB1;
        LDB1[i] = tGastoB1;
        
        vetorAleatorio(vetor1, INDEX1);
        clock_t inicCJ1 = clock();
        qsort(vetor1, INDEX1, sizeof(int), comparaqsort);
        clock_t finalCJ1 = clock() - inicCJ1;
        double tGastoCJ1 = (((double)finalCJ1) / CLOCKS_PER_SEC) * 1000000;
        custoSalto1 = custoSalto1 + tGastoCJ1;
        clock_t inicJ1 = clock();
        saltos(vetor1, INDEX1, vetor1[cont]);
        clock_t finalJ1 = clock() - inicJ1;
        double tGastoJ1 = (((double)finalJ1) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos1 = mediaSaltos1 + tGastoJ1;
        LDJ1[i] = tGastoJ1;

        vetorAleatorio(vetor1, INDEX1);
        clock_t inicCSO1 = clock();
        qsort(vetor1, INDEX1, sizeof(int), comparaqsort);
        clock_t finalCSO1 = clock() - inicCSO1;
        double tGastoCSO1 = (((double)finalCSO1) / CLOCKS_PER_SEC) * 1000000;
        custoSO1 = custoSO1 + tGastoCSO1;
        clock_t inicO1 = clock();
        sequencial(vetor1, INDEX1, vetor1[cont]);
        clock_t finalO1 = clock() - inicO1;
        double tGastoO1 = (((double)finalO1) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd1 = mediaSeqOrd1 + tGastoO1;
        LDO1[i] = tGastoO1;
        
        cont = cont + 20;



    }

// INDEX 2

    cont = 40;
    for(int i = 0; i < AMOSTRA; i++){
        int vetor2[INDEX2];

        vetorAleatorio(vetor2, INDEX2);
        clock_t inicS2 = clock();
        sequencial(vetor2, INDEX2, vetor2[cont]);
        clock_t finalS2 = clock() - inicS2;
        double tGastoS2 = (((double)finalS2) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial2 = mediaSequencial2 + tGastoS2;
        LDS2[i] = (double)tGastoS2;

        vetorAleatorio(vetor2, INDEX2);
        clock_t inicCB2 = clock();
        qsort(vetor2, INDEX2, sizeof(int), comparaqsort);
        clock_t finalCB2 = clock() - inicCB2;
        double tGastoCB2 = (((double)finalCB2) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria2 = custoBinaria2 + tGastoCB2;
        clock_t inicB2 = clock();
        binaria(vetor2, INDEX2, vetor2[cont]);
        clock_t finalB2 = clock() - inicB2;
        double tGastoB2 = (((double)finalB2) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria2 = mediaBinaria2 + tGastoB2;
        LDB2[i] = tGastoB2;

        vetorAleatorio(vetor2, INDEX2);
        clock_t inicCJ2 = clock();
        qsort(vetor2, INDEX2, sizeof(int), comparaqsort);
        clock_t finalCJ2 = clock() - inicCJ2;
        double tGastoCJ2 = (((double)finalCJ2) / CLOCKS_PER_SEC) * 1000000;
        custoSalto2 = custoSalto2 + tGastoCJ2;
        clock_t inicJ2 = clock();
        saltos(vetor2, INDEX2, vetor2[cont]);
        clock_t finalJ2 = clock() - inicJ2;
        double tGastoJ2 = (((double)finalJ2) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos2 = mediaSaltos2 + tGastoJ2;
        LDJ2[i] = tGastoJ2;

        vetorAleatorio(vetor2, INDEX2);
        clock_t inicCSO2 = clock();
        qsort(vetor2, INDEX2, sizeof(int), comparaqsort);
        clock_t finalCSO2 = clock() - inicCSO2;
        double tGastoCSO2 = (((double)finalCSO2) / CLOCKS_PER_SEC) * 1000000;
        custoSO2 = custoSO2 + tGastoCSO2;
        clock_t inicO2 = clock();
        sequencial(vetor2, INDEX2, vetor2[cont]);
        clock_t finalO2 = clock() - inicO2;
        double tGastoO2 = (((double)finalO2) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd2 = mediaSeqOrd2 + tGastoO2;
        LDO2[i] = tGastoO2;



        cont = cont + 40;
    }

// INDEX 3

    cont = 80;
    for(int i = 0; i < AMOSTRA; i++){
        int vetor3[INDEX3];

        vetorAleatorio(vetor3, INDEX3);
        clock_t inicS3 = clock();
        sequencial(vetor3, INDEX3, vetor3[cont]);
        clock_t finalS3 = clock() - inicS3;
        double tGastoS3 = (((double)finalS3) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial3 = mediaSequencial3 + tGastoS3;
        LDS3[i] = mediaSequencial3;

        vetorAleatorio(vetor3, INDEX3);
        clock_t inicCB3 = clock();
        qsort(vetor3, INDEX3, sizeof(int), comparaqsort);
        clock_t finalCB3 = clock() - inicCB3;
        double tGastoCB3 = (((double)finalCB3) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria3 = custoBinaria3 + tGastoCB3;
        clock_t inicB3 = clock();
        binaria(vetor3, INDEX3, vetor3[cont]);
        clock_t finalB3 = clock() - inicB3;
        double tGastoB3 = (((double)finalB3) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria3 = mediaBinaria3 + tGastoB3;
        LDB3[i] = tGastoB3;


        vetorAleatorio(vetor3, INDEX3);
        clock_t inicCJ3 = clock();
        qsort(vetor3, INDEX3, sizeof(int), comparaqsort);
        clock_t finalCJ3 = clock() - inicCJ3;
        double tGastoCJ3 = (((double)finalCJ3) / CLOCKS_PER_SEC) * 1000000;
        custoSalto3 = custoSalto3 + tGastoCJ3;
        clock_t inicJ3 = clock();
        saltos(vetor3, INDEX3, vetor3[cont]);
        clock_t finalJ3 = clock() - inicJ3;
        double tGastoJ3 = (((double)finalJ3) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos3 = mediaSaltos3 + tGastoJ3;
        LDJ3[i] = tGastoJ3;

        vetorAleatorio(vetor3, INDEX3);
        clock_t inicCSO3 = clock();
        qsort(vetor3, INDEX3, sizeof(int), comparaqsort);
        clock_t finalCSO3 = clock() - inicCSO3;
        double tGastoCSO3 = (((double)finalCSO3) / CLOCKS_PER_SEC) * 1000000;
        custoSO3 = custoSO3 + tGastoCSO3;
        clock_t inicO3 = clock();
        sequencial(vetor3, INDEX3, vetor3[cont]);
        clock_t finalO3 = clock() - inicO3;
        double tGastoO3 = (((double)finalO3) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd3 = mediaSeqOrd3 + tGastoO3;
        LDO3[i] = tGastoO3;


        cont = cont + 80;
    }



// INDEX 4
    cont = 160;
    for(int i = 0; i < AMOSTRA; i++){
        int vetor4[INDEX4];

        vetorAleatorio(vetor4, INDEX4);
        clock_t inicS4 = clock();
        sequencial(vetor4, INDEX4, vetor4[cont]);
        clock_t finalS4 = clock() - inicS4;
        double tGastoS4 = (((double)finalS4) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial4 = mediaSequencial4 + tGastoS4;
        LDS4[i] = mediaSequencial4;

        vetorAleatorio(vetor4, INDEX4);
        clock_t inicCB4 = clock();
        qsort(vetor4, INDEX4, sizeof(int), comparaqsort);
        clock_t finalCB4 = clock() - inicCB4;
        double tGastoCB4 = (((double)finalCB4) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria4 = custoBinaria4 + tGastoCB4;
        clock_t inicB4 = clock();
        binaria(vetor4, INDEX4, vetor4[cont]);
        clock_t finalB4 = clock() - inicB4;
        double tGastoB4 = (((double)finalB4) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria4 = mediaBinaria4 + tGastoB4;
        LDB4[i] = tGastoB4;


        vetorAleatorio(vetor4, INDEX4);
        clock_t inicCJ4 = clock();
        qsort(vetor4, INDEX4, sizeof(int), comparaqsort);
        clock_t finalCJ4 = clock() - inicCJ4;
        double tGastoCJ4 = (((double)finalCJ4) / CLOCKS_PER_SEC) * 1000000;
        custoSalto4 = custoSalto4 + tGastoCJ4;
        clock_t inicJ4 = clock();
        saltos(vetor4, INDEX0, vetor4[cont]);
        clock_t finalJ4 = clock() - inicJ4;
        double tGastoJ4 = (((double)finalJ4) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos4 = mediaSaltos4 + tGastoJ4;
        LDJ4[i] = tGastoJ4;

        vetorAleatorio(vetor4, INDEX4);
        clock_t inicCSO4 = clock();
        qsort(vetor4, INDEX4, sizeof(int), comparaqsort);
        clock_t finalCSO4 = clock() - inicCSO4;
        double tGastoCSO4 = (((double)finalCSO4) / CLOCKS_PER_SEC) * 1000000;
        custoSO4 = custoSO4 + tGastoCSO4;
        clock_t inicO4 = clock();
        sequencial(vetor4, INDEX4, vetor4[cont]);
        clock_t finalO4 = clock() - inicO4;
        double tGastoO4 = (((double)finalO4) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd4 = mediaSeqOrd4 + tGastoO4;
        LDO4[i] = tGastoO4;
        
        
        cont = cont + 160;
    }

// INDEX 5
    cont = 320;
    for(int i = 0; i < AMOSTRA; i++){
        
        int vetor5[INDEX5];


        vetorAleatorio(vetor5, INDEX5);
        clock_t inicS5 = clock();
        sequencial(vetor5, INDEX5, vetor5[cont]);
        clock_t finalS5 = clock() - inicS5;
        double tGastoS5 = (((double)finalS5) / CLOCKS_PER_SEC) * 1000000;
        mediaSequencial5 = mediaSequencial5 + tGastoS5;
        LDS5[i] = mediaSequencial5;

        vetorAleatorio(vetor5, INDEX5);
        clock_t inicCJ5 = clock();
        qsort(vetor5, INDEX5, sizeof(int), comparaqsort);
        clock_t finalCJ5 = clock() - inicCJ5;
        double tGastoCJ5 = (((double)finalCJ5) / CLOCKS_PER_SEC) * 1000000;
        custoSalto5 = custoSalto5 + tGastoCJ5;
        clock_t inicJ5 = clock();
        saltos(vetor5, INDEX5, vetor5[cont]);
        clock_t finalJ5 = clock() - inicJ5;
        double tGastoJ5 = (((double)finalJ5) / CLOCKS_PER_SEC) * 1000000;
        mediaSaltos5 = mediaSaltos5 + tGastoJ5;
        LDJ5[i] = tGastoJ5;
        

        vetorAleatorio(vetor5, INDEX5);
        clock_t inicCB5 = clock();
        qsort(vetor5, INDEX5, sizeof(int), comparaqsort);
        clock_t finalCB5 = clock() - inicCB5;
        double tGastoCB5 = (((double)finalCB5) / CLOCKS_PER_SEC) * 1000000;
        custoBinaria5 = custoBinaria5 + tGastoCB5;
        clock_t inicB5 = clock();
        binaria(vetor5, INDEX5, vetor5[cont]);
        clock_t finalB5 = clock() - inicB5;
        double tGastoB5 = (((double)finalB5) / CLOCKS_PER_SEC) * 1000000;
        mediaBinaria5 = mediaBinaria5 + tGastoB5;
        LDB5[i] = tGastoB5;
    


        vetorAleatorio(vetor5, INDEX5);
        clock_t inicCSO5 = clock();
        qsort(vetor5, INDEX5, sizeof(int), comparaqsort);
        clock_t finalCSO5 = clock() - inicCSO5;
        double tGastoCSO5 = (((double)finalCSO5) / CLOCKS_PER_SEC) * 1000000;
        custoSO5 = custoSO5 + tGastoCSO5;
        clock_t inicO5 = clock();
        sequencial(vetor5, INDEX5, vetor5[cont]);
        clock_t finalO5 = clock() - inicO5;
        double tGastoO5 = (((double)finalO5) / CLOCKS_PER_SEC) * 1000000;
        mediaSeqOrd5 = mediaSeqOrd5 + tGastoO5;
        LDO5[i] = tGastoO5;


        cont = cont + 320;
    }


    float desvioS0 = desvioPadrao(LDS0);
    float desvioS1 = desvioPadrao(LDS1);
    float desvioS2 = desvioPadrao(LDS2);
    float desvioS3 = desvioPadrao(LDS3);
    float desvioS4 = desvioPadrao(LDS4);
    float desvioS5 = desvioPadrao(LDS5);
    printf("\nbusca sequencial 2^10: %f", mediaSequencial0);
    printf("\nbusca sequencial 2^11: %f", mediaSequencial1);
    printf("\nbusca sequencial 2^12: %f", mediaSequencial2);
    printf("\nbusca sequencial 2^13: %f", mediaSequencial3);
    printf("\nbusca sequencial 2^14: %f", mediaSequencial4);
    printf("\nbusca sequencial 2^15: %f", mediaSequencial5);
    printf("\ndesvio padrao busca sequencial 2^10 =  %f", desvioS0);
    printf("\ndesvio padrao busca sequencial 2^11 =  %f", desvioS1);
    printf("\ndesvio padrao busca sequencial 2^12 =  %f", desvioS2);
    printf("\ndesvio padrao busca sequencial 2^13 =  %f", desvioS3);
    printf("\ndesvio padrao busca sequencial 2^14 =  %f", desvioS4);
    printf("\ndesvio padrao busca sequencial 2^15 =  %f", desvioS5);
    printf("\n");
    float desvJ0 = desvioPadrao(LDJ0);
    float desvJ1 = desvioPadrao(LDJ1);
    float desvJ2 = desvioPadrao(LDJ2);
    float desvJ3 = desvioPadrao(LDJ3);
    float desvJ4 = desvioPadrao(LDJ4);
    float desvJ5 = desvioPadrao(LDJ5);
    printf("\nbusca 'Jump search' 2^10: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos0, custoSalto0, desvJ0);
    printf("\nbusca 'Jump search' 2^11: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos1, custoSalto1, desvJ1);
    printf("\nbusca 'Jump search' 2^12: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos2, custoSalto2, desvJ2);
    printf("\nbusca 'Jump search' 2^13: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos3, custoSalto3, desvJ3);
    printf("\nbusca 'Jump search' 2^14: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos4, custoSalto4, desvJ4);
    printf("\nbusca 'Jump search' 2^15: %f + %f da ordenacao, desvio padrao de %f", mediaSaltos5, custoSalto5, desvJ5);
    printf("\n");
    float desvB0 = desvioPadrao(LDB0);
    float desvB1 = desvioPadrao(LDB1);
    float desvB2 = desvioPadrao(LDB2);
    float desvB3 = desvioPadrao(LDB3);
    float desvB4 = desvioPadrao(LDB4);
    float desvB5 = desvioPadrao(LDB5);
    printf("\nbusca binaria 2^10: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria0, custoBinaria0, desvB0);
    printf("\nbusca binaria 2^11: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria1, custoBinaria1, desvB1);  
    printf("\nbusca binaria 2^12: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria2, custoBinaria2, desvB2);
    printf("\nbusca binaria 2^13: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria3, custoBinaria3, desvB3);
    printf("\nbusca binaria 2^14: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria4, custoBinaria4, desvB4);
    printf("\nbusca binaria 2^15: %f + %f da ordenacao, desvio padrao de %f", mediaBinaria5, custoBinaria5, desvB5);
    printf("\n");
    float desvO0 = desvioPadrao(LDO0);
    float desvO1 = desvioPadrao(LDO1);
    float desvO2 = desvioPadrao(LDO2);
    float desvO3 = desvioPadrao(LDO3);
    float desvO4 = desvioPadrao(LDO4);
    float desvO5 = desvioPadrao(LDO5);
    printf("\nbusca Sequencial Ordenada 2^10: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd0, custoSO0, desvO0);
    printf("\nbusca Sequencial Ordenada 2^11: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd1, custoSO1, desvO1);
    printf("\nbusca Sequencial Ordenada 2^12: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd2, custoSO2, desvO2);
    printf("\nbusca Sequencial Ordenada 2^13: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd3, custoSO3, desvO3);
    printf("\nbusca Sequencial Ordenada 2^14: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd4, custoSO4, desvO4);
    printf("\nbusca Sequencial Ordenada 2^15: %f + %f da ordenacao, desvio padrao de %f", mediaSeqOrd5, custoSO5, desvO5);
    printf("\n");


   




/*

    int tam = INDEX0;
    int vetor[tam];
    int chaves[AMOSTRA];
    vetorAleatorio(vetor, tam);
    
*/
    printf("\n");
    return 0;
}


void vetorAleatorio(int *vetor, int tamanho){
    
    srand(time(0)); //seed
    int aux;
    for(int i = 0; i<tamanho; i++){
        aux = rand();
        vetor[i] = aux;
    
    }

}

int comparaqsort(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int particiona(int *vetor, int esquerda, int direita) {
    int pivo = vetor[esquerda];
    int i = esquerda, f = direita;
    while (i < f) {
        while (i < f && vetor[f] >= pivo)
            f--;
        if (i < f)
            vetor[i] = vetor[f];
        while (i < f && vetor[i] <= pivo)
            i++;
        if (i < f)
            vetor[f] = vetor[i];
            
    }
    vetor[i] = pivo;
    return i;

}



void quicksort(int *vetor, int esquerda, int direita) {
    int i;
    if(direita <= esquerda) return;
    i = particiona(vetor, esquerda, direita);
    quicksort(vetor, esquerda, i-1);
    quicksort(vetor, i+1, direita);

}


int sequencial(int vetor[], int tam, int chave){

    int posicao;

    for(int i = 0; i<tam; i++)
        if(vetor[i] == chave){
            return i;
        }

    return -1;
}

int saltos(int vetor[], int tamanho, int chave) {
   int i = 0;
   int bloco = sqrt(tamanho);

   while(vetor[bloco] <= chave && bloco < tamanho) { 
      i = bloco; 
      bloco += sqrt(tamanho);
      if(bloco > tamanho - 1)
         return -1; 
   }

   for(int j = i; j < bloco; j++) {// sequencial dentro do bloco
      if(vetor[j] == chave)
         return j;
   }
   return -1;

}



int binaria(int vetor[], int tam, int chave){

    int posIni = 0, posFim = tam-1, posMeio;

    //qsort(vetor, tam, sizeof(int), comparaqsort);

    while(posIni <= posFim){
        posMeio = (posIni + posFim) /2;
        if(vetor[posMeio] == chave)
            return posMeio;
        else if(vetor[posMeio] > chave)
            posFim = posMeio -1;
        else
            posIni = posMeio +1;

    }

    return 0;
}


void imprime(int *vetor, int tamanho){
    for(int j = 0; j<tamanho; j++){
        printf(" %d, ", vetor[j]);
    }
}