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




void vetorAleatorio(int *vetor, int tamanho);
int comparaqsort(const void * a, const void * b);
int sequencial(int vetor[], int tam, int chave);
int saltos(int vetor[], int tamanho, int chave);
int binaria(int vetor[], int tam, int chave);
void imprime(int *vetor, int tamanho);



int main(){

    double primeiroSeq[6], ultimoSeq[6], foraseq[6];
    double primeiroBin[6], ultimoBin[6], foraBin[6];
    double primeiroSal[6], ultimoSal[6], foraSal[6];

    for(float i = 0; i<6; i++){
        int tam = INDEX0 * (pow(2, i));
        int vetor[tam];
        printf("%d, ", tam);
        vetorAleatorio(vetor, tam);

        clock_t inicio = clock();
        sequencial(vetor, tam, vetor[0]);
        clock_t final = clock() - inicio;
        double tGasto = (((double)final) / CLOCKS_PER_SEC) * 100000000;
        primeiroSeq[(int)i] = tGasto;


        clock_t iniciou = clock();
        sequencial(vetor, tam, vetor[tam-1]);
        clock_t finalu = clock() - iniciou;
        double tGastou = (((double)finalu) / CLOCKS_PER_SEC) * 100000000;
        ultimoSeq[(int)i] = tGastou;


        clock_t iniciof = clock();
        sequencial(vetor, tam, (vetor[tam-1]*vetor[tam-1]));
        clock_t finalf = clock() - iniciof;
        double tGastof = (((double)finalf) / CLOCKS_PER_SEC) * 100000000;
        foraseq[(int)i] = tGastof;

        qsort(vetor, tam, sizeof(int), comparaqsort);



        clock_t iniciob = clock();
        binaria(vetor, tam, vetor[0]);
        clock_t finalb = clock() - iniciob;
        double tGastob = (((double)finalb) / CLOCKS_PER_SEC) * 100000000;
        primeiroBin[(int)i] = tGastob;


        clock_t inicioub = clock();
        binaria(vetor, tam, vetor[tam-1]);
        clock_t finalub = clock() - inicioub;
        double tGastoub = (((double)finalub) / CLOCKS_PER_SEC) * 100000000;
        ultimoBin[(int)i] = tGastoub;


        clock_t iniciofb = clock();
        binaria(vetor, tam, (vetor[tam-1]*vetor[tam-1]*vetor[tam-1]));
        clock_t finalfb = clock() - iniciofb;
        double tGastofb = (((double)finalfb) / CLOCKS_PER_SEC) * 100000000;
        foraBin[(int)i] = tGastofb;



        clock_t inicioj = clock();
        saltos(vetor, tam, vetor[0]);
        clock_t finalj = clock() - inicioj;
        double tGastoj = (((double)finalj) / CLOCKS_PER_SEC) * 100000000;
        primeiroSal[(int)i] = tGastoj;


        clock_t iniciouj = clock();
        saltos(vetor, tam, vetor[tam-1]);
        clock_t finaluj = clock() - iniciouj;
        double tGastouj = (((double)finalub) / CLOCKS_PER_SEC) * 100000000;
        ultimoSal[(int)i] = tGastouj;


        clock_t iniciofj = clock();
        saltos(vetor, tam, (vetor[tam-1]*vetor[tam-1]*vetor[tam-1]));
        clock_t finalfj = clock() - iniciofj;
        double tGastofj = (((double)finalfj) / CLOCKS_PER_SEC) * 100000000;
        foraSal[(int)i] = tGastofj;








    }

     printf("\n S s s s s s s s s s L \n ");
    for(int x = 0; x<6; x++){
        printf("%f, ", primeiroSeq[x]);
    }

    printf("\n S E Q U E N C I A L \n ");
    printf("\n no primeiro item\n ");
    imprime(primeiroSeq, 6);
    printf("\n no ultimo item\n ");
    imprime(ultimoSeq, 6);
    printf("\n  item fora\n ");
    imprime(foraseq, 6);
    printf("\n\n B I N A R I A \n ");
    imprime(primeiroBin, 6);
    printf("\n no ultimo item\n ");
    imprime(ultimoBin, 6);
    printf("\n  item fora\n ");
    imprime(foraBin, 6);
    printf("\n J U M P  \n ");
    printf("\n no primeiro item\n ");
    imprime(primeiroSal, 6);
    printf("\n no ultimo item\n ");
    imprime(ultimoSal, 6);
    printf("\n  item fora\n ");
    imprime(foraSal, 6);
    /*
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


        */


    printf("\n");
    return 0;
}




//  dkfbasdkjfakjsdhfkjasdhflkjadshflkajshfdlkjafhdlkjfhasldkjfasdjlhfaljsdhfg




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