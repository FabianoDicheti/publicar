#include <stdio.h>
#include <stdlib.h>

int* alocaVmemoria(int tamanho){
 
    int *auxiliar;

    auxiliar = (int*) malloc(tamanho * sizeof(int));

    return auxiliar;
}


int main(){

    int *casos, quant, q;

    scanf("%d", &quant);

    casos = alocaVmemoria(quant);

    for(q=0; q<quant; q++){
        fflush(stdin);
        scanf("%d", &casos[q]);
    }

    int t;
    for(t=0; t<quant; t++){

        int fiboN, *vetorfibo, cont1 = 0, cont2 = 1;
        int chamada = 0, c, conta;

        fiboN = casos[t];

        if(fiboN == 1){
            chamada = 1;
            conta = 1;
        } else if(fiboN == 2){
            chamada = 2;
            conta = 1;
        }else{

            vetorfibo = alocaVmemoria(fiboN);

            int i, aux;
            for(i=0; i<fiboN; i++){
            vetorfibo[i] = cont1 + cont2;
            aux = cont2;
            cont2 = cont1 + cont2;
            cont1 = aux;
            }
            vetorfibo[fiboN-1] = vetorfibo[fiboN-3];

            for(c=0; c<fiboN; c++){
                chamada = chamada + vetorfibo[c];
            }

            conta = vetorfibo[fiboN-2];

        }

        printf("fib(%d) = %d calls = %d\n",fiboN, chamada, conta);

        
    }

    return 0;

}