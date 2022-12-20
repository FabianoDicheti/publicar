# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <math.h>



int sequencial(int vetor[], int tam, int chave);

int saltos(int vetor[], int tamanho, int chave);

int binaria(int vetor[], int tam, int chave);

int particiona(int *vetor, int esquerda, int direita);

void quicksort(int *vetor, int esquerda, int direita);





int main(){

int IND0 = 1024, IND1 = 2048, IND2 = 4096, IND3 = 8192, IND4 = 16384, IND5 = 32768;

// 0 - CRIANDO AS LISTAS ALEATORIAS

    int lista0[IND0], lista1[IND1], lista2[IND2], lista3[IND3], lista4[IND4], lista5[IND5];

    srand(time(0)); //seed
    printf("\n\n\n");
    int aux;
    for(int i = 0; i<IND5; i++){
        aux = rand();
        lista5[i] = aux;
        if(i<IND4){
            lista4[i] = aux;
        }
        if(i<IND3){
            lista3[i] = aux;
        }
        if(i<IND2){
            lista2[i] = aux;
        }
        if(i<IND1){
            lista1[i] = aux;
        }
        if(i<IND0){
            lista0[i] = aux;
        }
    }

// 1 - DEFININDO OS 100 NUMEROS A SEREM BUSCADOS EM CADA LISTA

    int amostra1024[100], amostra2048[100], amostra4096[100];
    int amostra8192[100], amostra16384[100], amostra32768[100];

    int b0 = 20;
    for(int a0 =0; a0<100; a0++){
            amostra1024[a0] = lista0[b0];
            printf("%d, ",lista0[b0]);
            b0 = b0+10;
            
    }

    int b1 = 8;
    for(int a1 =0; a1<100; a1++){
            amostra2048[a1] = lista1[b1];
            b1 = b1+20;
    }

    int b2 = 16;
    for(int a2 =0; a2<100; a2++){
            amostra4096[a2] = lista2[b2];
            b2 = b2+40;
    }


   int b3 = 32;
    for(int a3 =0; a3<100; a3++){
            amostra8192[a3] = lista3[b3];
            b3 = b3+80;
    }

    int b4 = 64;
    for(int a4 =0; a4<100; a4++){
            amostra16384[a4] = lista4[b4];
            b4 = b4+160;
    }

   int b5 = 128;
    for(int a5 =0; a5<100; a5++){
            amostra32768[a5] = lista5[b5];
            b5 = b5+320;
    }


// 2 - REGISTRANDO OS 100 TEMPOS QUE CADA METODO GASTOU

    // 2.0 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 1024 ITENS

    float tempoSequencial0[100], tempoSaltos0[100], tempoBinaria0[100], tempoOrd0[100];

    for(int t=0; t<100; t++){
        
        
        //2.0.0 - busca sequencial
        clock_t inic = clock();

        sequencial(lista0, IND0, amostra1024[t]);

        clock_t final = clock() - inic;
        double tGasto = (((double)final) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial0[t] = tGasto;
       
        
        //2.0.1 - jump search
        clock_t inicS = clock();

        saltos(lista0, IND0, amostra1024[t]);

        clock_t finalS = clock() - inicS;
        double tGastoS = (((double)finalS) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos0[t] = tGastoS;
    

        //2.0.2 - busca binaria
        clock_t inicB = clock();

         binaria(lista0, IND0, amostra1024[t]);

        clock_t finalB = clock() - inicB;
        double tGastoB = (((double)finalB) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria0[t] = tGastoB;  

         
        //2.0.3 - busca sequencial ordenada
        clock_t inicO = clock();
        
        int esquerda = 512, direita = 514;

        quicksort(lista0, esquerda, direita);

        sequencial(lista0, IND0, amostra1024[t]);

        clock_t finalO = clock() - inicO;
        double tGastoO = (((double)finalO) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd0[t] = tGastoO;  


    }

    // 2.1 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 2048 ITENS

    float tempoSequencial1[100], tempoSaltos1[100], tempoBinaria1[100], tempoOrd1[100];

    for(int t1=0; t1<100; t1++){
        
        
        // 2.1.0 - busca sequencial
        clock_t inic1 = clock();

        sequencial(lista1, IND1, amostra2048[t1]);

        clock_t final1 = clock() - inic1;
        double tGasto1 = (((double)final1) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial1[t1] = tGasto1;
       
        
        // 2.1.1 - jump search
        clock_t inicS1 = clock();

        saltos(lista1, IND1, amostra2048[t1]);

        clock_t finalS1 = clock() - inicS1;
        double tGastoS1 = (((double)finalS1) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos1[t1] = tGastoS1;
    

        // 2.1.2 - busca binaria
        clock_t inicB1 = clock();

         binaria(lista1, IND1, amostra2048[t1]);

        clock_t finalB1 = clock() - inicB1;
        double tGastoB1 = (((double)finalB1) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria1[t1] = tGastoB1;  
         

        //2.1.3 - busca sequencial ordenada
        clock_t inicO1 = clock();
        
        int esquerda1 = IND0, direita1 = 1026;
        quicksort(lista1, esquerda1, direita1);
        sequencial(lista1, IND1, amostra2048[t1]);

        clock_t finalO1 = clock() - inicO1;
        double tGastoO1 = (((double)finalO1) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd1[t1] = tGastoO1;  


    }


    // 2.2 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 4096 ITENS

    float tempoSequencial2[100], tempoSaltos2[100], tempoBinaria2[100], tempoOrd2[100];

    for(int t2=0; t2<100; t2++){
        
        
        // 2.2.0 - busca sequencial
        clock_t inic2 = clock();

        sequencial(lista2, IND2, amostra4096[t2]);

        clock_t final2 = clock() - inic2;
        double tGasto2 = (((double)final2) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial2[t2] = tGasto2;
       
        
        // 2.2.1 - jump search
        clock_t inicS2 = clock();

        saltos(lista2, IND2, amostra4096[t2]);

        clock_t finalS2 = clock() - inicS2;
        double tGastoS2 = (((double)finalS2) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos2[t2] = tGastoS2;
    

        // 2.2.2 - busca binaria
        clock_t inicB2 = clock();

         binaria(lista2, IND2, amostra4096[t2]);

        clock_t finalB2 = clock() - inicB2;
        double tGastoB2 = (((double)finalB2) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria2[t2] = tGastoB2;  
         

        // 2.2.3 - busca sequencial ordenada
        clock_t inicO2 = clock();
        
        int esquerda2 = IND1, direita2 = 2050;
        quicksort(lista2, esquerda2, direita2);
        sequencial(lista1, IND2, amostra4096[t2]);

        clock_t finalO2 = clock() - inicO2;
        double tGastoO2 = (((double)finalO2) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd2[t2] = tGastoO2;  


    }


    // 2.3 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 8192 ITENS

    float tempoSequencial3[100], tempoSaltos3[100], tempoBinaria3[100], tempoOrd3[100];

    for(int t3=0; t3<100; t3++){
        
        
        // 2.3.0 - busca sequencial
        clock_t inic3 = clock();

        sequencial(lista3, IND3, amostra8192[t3]);

        clock_t final3 = clock() - inic3;
        double tGasto3 = (((double)final3) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial3[t3] = tGasto3;
       
        
        // 2.3.1 - jump search
        clock_t inicS3 = clock();

        saltos(lista3, IND3, amostra8192[t3]);

        clock_t finalS3 = clock() - inicS3;
        double tGastoS3 = (((double)finalS3) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos3[t3] = tGastoS3;
    

        // 2.3.2 - busca binaria
        clock_t inicB3 = clock();

        binaria(lista3, IND3, amostra8192[t3]);

        clock_t finalB3 = clock() - inicB3;
        double tGastoB3 = (((double)finalB3) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria3[t3] = tGastoB3;  
         
        
        // 2.3.3 - busca sequencial ordenada
        clock_t inicO3 = clock();
        
        int esquerda3 = IND2, direita3 = 4098;
        quicksort(lista3, esquerda3, direita3);
        sequencial(lista3, IND3, amostra8192[t3]);

        clock_t finalO3 = clock() - inicO3;
        double tGastoO3 = (((double)finalO3) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd3[t3] = tGastoO3;  

    }


     //2.4 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 16384 ITENS

    float tempoSequencial4[100], tempoSaltos4[100], tempoBinaria4[100], tempoOrd4[100];

    for(int t4=0; t4<100; t4++){
        
        
        // 2.4.0 - busca sequencial
        clock_t inic4 = clock();

        sequencial(lista4, IND4, amostra16384[t4]);

        clock_t final4 = clock() - inic4;
        double tGasto4 = (((double)final4) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial4[t4] = tGasto4;
       
        
        // 2.4.1 - jump search
        clock_t inicS4 = clock();

        saltos(lista4, IND4, amostra16384[t4]);

        clock_t finalS4 = clock() - inicS4;
        double tGastoS4 = (((double)finalS4) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos4[t4] = tGastoS4;
    

        // 2.4.2 - busca binaria
        clock_t inicB4 = clock();

         binaria(lista4, IND4, amostra16384[t4]);

        clock_t finalB4 = clock() - inicB4;
        double tGastoB4 = (((double)finalB4) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria4[t4] = tGastoB4;  

        // 2.4.3 - busca sequencial ordenada
        clock_t inicO4 = clock();
        
        int esquerda4 = IND3, direita4 = 8194;
        quicksort(lista4, esquerda4, direita4);
        sequencial(lista4, IND4, amostra16384[t4]);

        clock_t finalO4 = clock() - inicO4;
        double tGastoO4 = (((double)finalO4) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd4[t4] = tGastoO4;  


    }


     // 2.5 REGISTROS DE TEMPO PARA 100 AMOSTRAS DE 32768 ITENS

    float tempoSequencial5[100], tempoSaltos5[100], tempoBinaria5[100], tempoOrd5[100];

    for(int t5=0; t5<100; t5++){
        
        
        // 2.5.0 - busca sequencial
        clock_t inic5 = clock();

        sequencial(lista5, IND5, amostra32768[t5]);

        clock_t final5 = clock() - inic5;
        double tGasto5 = (((double)final5) / CLOCKS_PER_SEC) * 1000000;
        tempoSequencial5[t5] = tGasto5;
       
        
        // 2.5.1 - jump search
        clock_t inicS5 = clock();

        saltos(lista5, IND5, amostra32768[t5]);

        clock_t finalS5 = clock() - inicS5;
        double tGastoS5 = (((double)finalS5) / CLOCKS_PER_SEC) * 1000000;
        tempoSaltos5[t5] = tGastoS5;
    

        // 2.5.2 - busca binaria
        clock_t inicB5 = clock();

        binaria(lista5, IND5, amostra32768[t5]);

        clock_t finalB5 = clock() - inicB5;
        double tGastoB5 = (((double)finalB5) / CLOCKS_PER_SEC) * 1000000;
        tempoBinaria5[t5] = tGastoB5;  


        // 2.5.3 - busca sequencial ordenada
        clock_t inicO5 = clock();
        
        int esquerda5 = IND4, direita5 = 16386;
        quicksort(lista5, esquerda5, direita5);
        sequencial(lista5, IND5, amostra32768[t5]);

        clock_t finalO5 = clock() - inicO5;
        double tGastoO5 = (((double)finalO5) / CLOCKS_PER_SEC) * 1000000;
        tempoOrd5[t5] = tGastoO5;  
         


    }





    // 3 - MEDIA DOS TEMPOS

    // 3.0 - media dos tempos da busca sequencial
    float mediaSequencial0 = 0, mediaSequencial1 = 0, mediaSequencial2 = 0;
    float mediaSequencial3 = 0, mediaSequencial4 = 0, mediaSequencial5 = 0;
    float somaS0 = 0, somaS1 = 0, somaS2 = 0, somaS3 = 0, somaS4 = 0, somaS5 = 0;

    for(int s = 0; s<100; s++){
        somaS0 = somaS0 + tempoSequencial0[s];
        somaS1 = somaS1 + tempoSequencial1[s];
        somaS2 = somaS2 + tempoSequencial2[s];
        somaS3 = somaS3 + tempoSequencial3[s];
        somaS4 = somaS4 + tempoSequencial4[s];
        somaS5 = somaS5 + tempoSequencial5[s];

    }
    mediaSequencial0 = somaS0 / 100;
    mediaSequencial1 = somaS1 / 100;
    mediaSequencial2 = somaS2 / 100;
    mediaSequencial3 = somaS3 / 100;
    mediaSequencial4 = somaS4 / 100;
    mediaSequencial5 = somaS5 / 100;

    printf(" \nBusca Sequencial 2^10, tempo medio: %f", mediaSequencial0);
    printf(" \nBusca Sequencial 2^11, tempo medio: %f", mediaSequencial1);
    printf(" \nBusca Sequencial 2^12, tempo medio: %f", mediaSequencial2);
    printf(" \nBusca Sequencial 2^13, tempo medio: %f", mediaSequencial3);
    printf(" \nBusca Sequencial 2^14, tempo medio: %f", mediaSequencial4);
    printf(" \nBusca Sequencial 2^15, tempo medio: %f", mediaSequencial5);

    printf("\n\n");

    // 3.1 - media dos tempod da busca Jump Search
    float mediaSaltos0 = 0, mediaSaltos1 = 0, mediaSaltos2 = 0;
    float mediaSaltos3 = 0, mediaSaltos4 = 0, mediaSaltos5 = 0;
    float somaJ0 = 0, somaJ1 = 0, somaJ2 = 0, somaJ3 = 0, somaJ4 = 0, somaJ5 = 0;

    for(int j = 0; j<100; j++){
        somaJ0 = somaJ0 + tempoSaltos0[j];
        somaJ1 = somaJ1 + tempoSaltos1[j];
        somaJ2 = somaJ2 + tempoSaltos2[j];
        somaJ3 = somaJ3 + tempoSaltos3[j];
        somaJ4 = somaJ4 + tempoSaltos4[j];
        somaJ5 = somaJ5 + tempoSaltos5[j];

    }
    mediaSaltos0 = somaJ0 / 100;
    mediaSaltos1 = somaJ1 / 100;
    mediaSaltos2 = somaJ2 / 100;
    mediaSaltos3 = somaJ3 / 100;
    mediaSaltos4 = somaJ4 / 100;
    mediaSaltos5 = somaJ5 / 100;

    printf(" \nBusca Jump Search 2^10, tempo medio: %f", mediaSaltos0);
    printf(" \nBusca Jump Search 2^11, tempo medio: %f", mediaSaltos1);
    printf(" \nBusca Jump Search 2^12, tempo medio: %f", mediaSaltos2);
    printf(" \nBusca Jump Search 2^13, tempo medio: %f", mediaSaltos3);
    printf(" \nBusca Jump Search 2^14, tempo medio: %f", mediaSaltos4);
    printf(" \nBusca Jump Search 2^15, tempo medio: %f", mediaSaltos5);


    printf("\n\n");



// 3.2 - media dos tempos da busca Binaria
    float mediaBinaria0 = 0, mediaBinaria1 = 0, mediaBinaria2 = 0;
    float mediaBinaria3 = 0, mediaBinaria4 = 0, mediaBinaria5 = 0;
    float somaB0 = 0, somaB1 = 0, somaB2 = 0, somaB3 = 0, somaB4 = 0, somaB5 = 0;

    for(int s = 0; s<100; s++){
        somaB0 = somaB0 + tempoBinaria0[s];
        somaB1 = somaB1 + tempoBinaria1[s];
        somaB2 = somaB2 + tempoBinaria2[s];
        somaB3 = somaB3 + tempoBinaria3[s];
        somaB4 = somaB4 + tempoBinaria4[s];
        somaB5 = somaB5 + tempoBinaria5[s];

    }
    mediaBinaria0 = somaB0 / 100;
    mediaBinaria1 = somaB1 / 100;
    mediaBinaria2 = somaB2 / 100;
    mediaBinaria3 = somaB3 / 100;
    mediaBinaria4 = somaB4 / 100;
    mediaBinaria5 = somaB5 / 100;

    printf(" \nBusca Binaria 2^10, tempo medio: %f", mediaBinaria0);
    printf(" \nBusca Binaria 2^11, tempo medio: %f", mediaBinaria1);
    printf(" \nBusca Binaria 2^12, tempo medio: %f", mediaBinaria2);
    printf(" \nBusca Binaria 2^13, tempo medio: %f", mediaBinaria3);
    printf(" \nBusca Binaria 2^14, tempo medio: %f", mediaBinaria4);
    printf(" \nBusca Binaria 2^15, tempo medio: %f", mediaBinaria5);

    printf("\n\n");

    // 3.3 - media dos tempod da busca Sequencial Ordenada 
    float mediaOrd0 = 0, mediaOrd1 = 0, mediaOrd2 = 0;
    float mediaOrd3 = 0, mediaOrd4 = 0, mediaOrd5 = 0;
    float somaO0 = 0, somaO1 = 0, somaO2 = 0, somaO3 = 0, somaO4 = 0, somaO5 = 0;

    for(int o = 0; o<100; o++){
        somaO0 = somaO0 + tempoOrd0[o];
        somaO1 = somaO1 + tempoOrd1[o];
        somaO2 = somaO2 + tempoOrd2[o];
        somaO3 = somaO3 + tempoOrd3[o];
        somaO4 = somaO4 + tempoOrd4[o];
        somaO5 = somaO5 + tempoOrd5[o];

    }
    mediaOrd0 = somaO0 / 100;
    mediaOrd1 = somaO1 / 100;
    mediaOrd2 = somaO2 / 100;
    mediaOrd3 = somaO3 / 100;
    mediaOrd4 = somaO4 / 100;
    mediaOrd5 = somaO5 / 100;

    printf(" \nBusca Sequencial Ordenada 2^10, tempo medio: %f", mediaOrd0);
    printf(" \nBusca Sequencial Ordenada 2^11, tempo medio: %f", mediaOrd1);
    printf(" \nBusca Sequencial Ordenada 2^12, tempo medio: %f", mediaOrd2);
    printf(" \nBusca Sequencial Ordenada 2^13, tempo medio: %f", mediaOrd3);
    printf(" \nBusca Sequencial Ordenada 2^14, tempo medio: %f", mediaOrd4);
    printf(" \nBusca Sequencial Ordenada 2^15, tempo medio: %f", mediaOrd5);


    printf("\n\n");





   

 
    return 0;





}
///    ##########  F  I  M     D  0     M  A  I  N #############

///    ##########  ##########  ##########  ##########  ########


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
    insertionSort(vetor, tam);
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


/*



    for(int j = 0; j<10; j++){
        printf(" %d, ", lista5[j]);

    }

    printf("\n\n\n");

    for(int k = 0; k<10; k++){
        printf(" %d, ", lista4[k]);

    }

    printf("\n\n\n");

    for(int l = 0; l<10; l++){
        printf(" %d, ", lista3[l]);

    }

    printf("\n\n\n");

    for(int k1 = 0; k1<10; k1++){
        printf(" %d, ", lista2[k1]);

    }

    printf("\n\n\n");

    for(int k2 = 0; k2<10; k2++){
        printf(" %d, ", lista0[k2]);

    }



*/