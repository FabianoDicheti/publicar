#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;


int** alocaMmemoria(int linhas, int colunas){
    int **matriz;
    matriz = (int **) malloc(linhas * sizeof(int *));
    
    for(int i = 0; i<linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }
    return matriz;

}

typedef struct nohs{
    int proximo;
    int peso; ///custo
}noh;

class classeGrafo{
    int dimensao;
    list<noh> *listaAdjacencia;
    private:
        void LLista(int src, list<noh> lt) { //Listar a Lista
        list<noh> :: iterator i;
        noh tempnoh;
    }
    public:
    classeGrafo() {
        dimensao = 0;
    }

    classeGrafo(int nohCount) {
        dimensao = nohCount;
        listaAdjacencia = new list<noh>[dimensao];
    }

    void adicionaVertice(int anterior, int proximo, int peso) {
        noh novoNoh;
        novoNoh.proximo = proximo;
        novoNoh.peso = peso;
        listaAdjacencia[anterior].push_back(novoNoh);
    }

    void listaVertices() {
        for(int i = 0; i<dimensao; i++) {
            list<noh> listaTempor = listaAdjacencia[i];
            LLista(i, listaTempor);
        }
    }

        friend void dijkstra(classeGrafo grafo, int *custo, int *nohAnterior, int nohInicial);
};

void dijkstra(classeGrafo grafo, int *custo, int *nohAnterior, int nohInicial) {
    int dimensao = grafo.dimensao;

    for(int item = 0; item<dimensao; item++) {
        custo[item] = 9999;
        nohAnterior[item] = -1;
    }

    custo[nohInicial] = 0;
    set<int> agrupamento;
    list<int> fila;

    for(int item = 0; item<dimensao; item++) {  ///por o noh na fila
        fila.push_back(item);
    }

    while(!fila.empty()) {
        list<int> :: iterator i;
        i = min_element(fila.begin(), fila.end());
        int item = *i; 
        fila.remove(item);
        agrupamento.insert(item);
        list<noh> :: iterator itera;

        for(itera = grafo.listaAdjacencia[item].begin(); itera != grafo.listaAdjacencia[item].end();itera++) {
            if((custo[item]+(itera->peso)) < custo[itera->proximo]) { 
                custo[itera->proximo] = (custo[item]+(itera->peso));
                nohAnterior[itera->proximo] = item;
            }
        }
    }
}

int main() {
    
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
        fscanf(entrada, "\n");
    }
	
	for(int s = 0; s<cabecalho; s++){
        for(int t = 0; t<cabecalho; t++){
            if(matriz[s][t] == 0){
				matriz[s][t] = 9999;
				
			}
        }
        fscanf(entrada, "\n");
    }
    



    int **vertices;
    vertices = alocaMmemoria((cabecalho*cabecalho), 3);
    
    classeGrafo grafo(cabecalho);
    int custo[cabecalho], nohAnterior[cabecalho];
    int nohInicial = 0;

    for(int j = 0; j<(cabecalho); j++){
        for(int k =0; k<(cabecalho); k++){
            grafo.adicionaVertice(j, k, matriz[j][k]); 
            
        }
        
    }


    dijkstra(grafo, custo, nohAnterior, nohInicial);

/*
    for(int i = 0; i<cabecalho; i++)
        if(i != nohInicial)
        printf(" custo do noh %d = %d  \t", i, custo[i]);
        
        
*/ 
    return 0;
}

