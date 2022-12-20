#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
# include <time.h>
#include <math.h>

int** alocaMmemoria(int linhas, int colunas){
    int **matriz;

    matriz = (int **) malloc(linhas * sizeof(int *));
    int i;
    for(i = 0; i<linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));

    }
    return matriz;

}

void Dijkstra(int **matriz, int tamanho) {
    
    int custo[tamanho][tamanho], distancia[tamanho], anterior[tamanho];
    int visitado[tamanho], contagem, distanciaMinima, proximoNoh, i, j;
    int inicio = 0;

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            if (matriz[i][j] != 0)
            custo[i][j] = matriz[i][j];
        else
            custo[i][j] = 9999;
            
        }

    }


    for (i = 0; i < tamanho; i++) {
        distancia[i] = custo[inicio][i];
        anterior[i] = inicio;
        visitado[i] = 0;
    }

    distancia[inicio] = 0;
    visitado[inicio] = 1;
    contagem = 1;

    while (contagem < tamanho - 1) {
        distanciaMinima = 9999;

        for (i = 0; i < tamanho; i++)
            if (distancia[i] < distanciaMinima && !visitado[i]) {
                distanciaMinima = distancia[i];
                proximoNoh = i;
            }
            
            visitado[proximoNoh] = 1;
            for (i = 0; i < tamanho; i++)
                if (!visitado[i])
                    if (distanciaMinima + custo[proximoNoh][i] < distancia[i]) {
                        distancia[i] = distanciaMinima + custo[proximoNoh][i];
                        anterior[i] = proximoNoh;
                    }
                    
        contagem++;
    }
    /*for (i = 0; i < tamanho; i++){
        printf("custo do noh %d = %d \t ", i, distancia[i]);
    } 
    */
        
}



int main(){
	
    FILE *entrada;
	int item, cabecalho;
    
	entrada = fopen("Entrada75.txt", "r");
	if(entrada == NULL){
		perror("nao ta abrindo o arquivo");
		return(-1);
	}
    if(fscanf(entrada, "%d", &cabecalho) != 0){}
    //printf("cabecalho %d \n", cabecalho);
    
    int **matriz;
    matriz = alocaMmemoria(cabecalho, cabecalho);
    for(int i = 0; i<cabecalho; i++){
        for(int j = 0; j<cabecalho; j++){
            fscanf(entrada, "%d", &matriz[i][j]);
        }
        //fscanf(entrada, "\n");
    }
    
    
    int **matrizb;
    matrizb = alocaMmemoria(cabecalho, cabecalho);
    for(int i = 0; i<cabecalho; i++){
        for(int j = 0; j<cabecalho; j++){
            matrizb[i][j] = matriz[j][i];
        }
    }
    
    
    
    float registroTempo[1000];

    for(int t=0; t<1100; t++){
        
        clock_t inic = clock();

        Dijkstra(matriz, cabecalho);

        clock_t final = clock() - inic;
        double tGasto = (((double)final) / CLOCKS_PER_SEC) * 1000000;
        if(t>99){
            registroTempo[t-100] = tGasto;
        }
        
    }
    float mediaTempo = 0, somaTempo = 0;

    for(int s = 0; s<1000; s++){
        somaTempo = somaTempo + registroTempo[s];
    }
    mediaTempo = somaTempo / 1000;
    
    float variacoes = 0;
    for (int i = 0; i < 1000; i++) {
        float v = registroTempo[i] - mediaTempo;
        variacoes += v * v;
    }

    float sigma = sqrt(variacoes / 1000);
    
    /*
    printf("tempos = [ ");
    for(int x =0; x<1000; x++){
        printf(" %f,", registroTempo[x]);
        
    }
    */
    printf(" ] \n");
    printf(" media de tempo = %f \n", mediaTempo);
    printf("desvio padrao d = %.2f\n", sigma);
    
    
    
    
    
    
    
    
    
    Dijkstra(matriz, cabecalho);

    
	return 0;
}