#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int** alocaMmemoria(int linhas, int colunas);

struct NohListaAdj;
struct ListaAdjacencia;
struct grafo;
struct NohListaAdj;
struct grafo* creategrafo(int V);

void novoVertice(struct grafo* graph, int anterior, int proximo, int distancia);

struct MinHeapNoh;
struct MinHeap;
struct MinHeapNoh* newMinHeapNoh(int v, int dist);
struct MinHeap* createMinHeap(int maximo);
void swapMinHeapNoh(struct MinHeapNoh** a, struct MinHeapNoh** b);
void atualizaHeap(struct MinHeap* minHeap, int indice);
int vazio(struct MinHeap* minHeap);
struct MinHeapNoh* extractMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap, int v, int dist);
bool isInMinHeap(struct MinHeap *minHeap, int v);

void printArr(int dist[], int n);
void dijkstra(struct grafo* graph, int anterior);



int main(){
	
	
	
	
	
    FILE *entrada;
	int item, cabecalho;
    
	entrada = fopen("teste.txt", "r");
	if(entrada == NULL){
		perror("nao ta abrindo o arquivo");
		return(-1);
	}
    if(fscanf(entrada, "%d", &cabecalho) != 0){}
    printf("cabecalho %d \n", cabecalho);
    
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
    
/*
    struct grafo *graph = creategrafo(cabecalho);
    for(int f=0; f<cabecalho; f++){
        for(int g = 0; g< cabecalho; g++){
			if(matriz[f][g] ==0)
				novoVertice(graph,f,g, 99999);
			else
				novoVertice(graph,f,g, matriz[f][g]);
			
			printf(" %d ", matriz[f][g]);
        }
        printf("\n");
    }
    */


    int **vertices;
    vertices = alocaMmemoria((cabecalho*cabecalho), 3);
    
    int c = 0;
    for(int j = 0; j<(cabecalho); j++){
        for(int k =0; k<(cabecalho); k++){
            vertices[c][0] = j;
            vertices[c][1] = k;
            vertices[c][2] = matriz[j][k];
			if(vertices[c][2] == 0){
				vertices[c][2] = 9999;
			}
            c++;
            
        }
        
    }
    
	for(int a = 0; a<cabecalho; a++){
		for(int b = 0; b<cabecalho; b++){
		printf("g.addEdge(%d, %d, %d);  \n",a, b, matriz[a][b] );
		}
	}
	
    struct grafo *graph = creategrafo(cabecalho);
    for(int f=0; f<(cabecalho*cabecalho); f++){
		if(vertices[f][2] == 0){
			novoVertice(graph,vertices[f][0],vertices[f][1], 9999);
		}
		else
			novoVertice(graph,vertices[f][0],vertices[f][1], vertices[f][2]);
		
    }

	dijkstra(graph, 0);

	return 0;
}


//////////// FFFFFFFFFFFFFFFFFFF

int** alocaMmemoria(int linhas, int colunas){
    int **matriz;

    matriz = (int **) malloc(linhas * sizeof(int *));
    int i;
    for(i = 0; i<linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));

    }
    return matriz;

}



// A structure to represent a Noh in adjacency list
struct NohListaAdj{
	int proximo;
	int distancia;
	struct NohListaAdj* next;
};

// A structure to represent an adjacency list
struct ListaAdjacencia{
	
// Pointer to head Noh of list
struct NohListaAdj *head;
};

// A structure to represent a graph.// A graph is an array of adjacency lists.// tamanho of array will be V (number of// vertices in graph)
struct grafo{
	int V;
	struct ListaAdjacencia* array;
};

// A utility function to create// a new adjacency list Noh
struct NohListaAdj* newNohListaAdj(int proximo, int distancia){
	struct NohListaAdj* novoNoh = (struct NohListaAdj*)
	malloc(sizeof(struct NohListaAdj));
	novoNoh->proximo = proximo;
	novoNoh->distancia = distancia;
	novoNoh->next = NULL;
	return novoNoh;
}

// A utility function that creates// a grafo of V vertices
struct grafo* creategrafo(int V){
	struct grafo* graph = (struct grafo*) malloc(sizeof(struct grafo));
	graph->V = V;

	// Create an array of adjacency lists.// tamanho of array will be V
	graph->array = (struct ListaAdjacencia*)
	malloc(V * sizeof(struct ListaAdjacencia));

	// Initialize each adjacency list// as empty by making head as NULL
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void novoVertice(struct grafo* graph, int anterior, int proximo, int distancia){
	// Add an edge from anterior to proximo.// A new Noh is added to the adjacency// list of anterior. The Noh is// added at the beginning
	struct NohListaAdj* novoNoh = newNohListaAdj(proximo, distancia);
	novoNoh->next = graph->array[anterior].head;
	graph->array[anterior].head = novoNoh;

	// Since graph is undirected,// add an edge from proximo to anterior also
	novoNoh = newNohListaAdj(anterior, distancia);
	novoNoh->next = graph->array[proximo].head;
	graph->array[proximo].head = novoNoh;
}

// Structure to represent a min heap Noh
struct MinHeapNoh{
	int v;
	int dist;
};

// Structure to represent a min heap
struct MinHeap{
	
	int tamanho;	
	int maximo;

	// This is needed for decreaseKey()
	int *pos;
	struct MinHeapNoh **array;
};

// A utility function to create a
// new Min Heap Noh
struct MinHeapNoh* newMinHeapNoh(int v, int dist){
	struct MinHeapNoh* minHeapNoh = (struct MinHeapNoh*)
    malloc(sizeof(struct MinHeapNoh));
	minHeapNoh->v = v;
	minHeapNoh->dist = dist;
	return minHeapNoh;
}

// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int maximo){
	struct MinHeap* minHeap = (struct MinHeap*)
    malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(maximo * sizeof(int));
	minHeap->tamanho = 0;
	minHeap->maximo = maximo;
	minHeap->array = (struct MinHeapNoh**)
    malloc(maximo * sizeof(struct MinHeapNoh*));
	return minHeap;
}

// A utility function to swap two
// Nohs of min heap.
// Needed for min heapify
void swapMinHeapNoh(struct MinHeapNoh** a, struct MinHeapNoh** b){
	struct MinHeapNoh* t = *a;
	*a = *b;
	*b = t;
}

// A standard function to
// heapify at given indice
// This function also updates
// position of Nohs when they are swapped.
// Position is needed for decreaseKey()
void atualizaHeap(struct MinHeap* minHeap, int indice){
	int menor, esquerda, direita;
	menor = indice;
	esquerda = 2 * indice + 1;
	direita = 2 * indice + 2;

	if (esquerda < minHeap->tamanho &&
		minHeap->array[esquerda]->dist <
		minHeap->array[menor]->dist )
		menor = esquerda;

	if (direita < minHeap->tamanho &&
		minHeap->array[direita]->dist <
		minHeap->array[menor]->dist )
		menor = direita;

	if (menor != indice){
		// The Nohs to be swapped in min heap
		MinHeapNoh *menorNoh = minHeap->array[menor];
		MinHeapNoh *indiceNoh = minHeap->array[indice];

		// Swap positions
		minHeap->pos[menorNoh->v] = indice;
		minHeap->pos[indiceNoh->v] = menor;

		// Swap Nohs
		swapMinHeapNoh(&minHeap->array[menor], &minHeap->array[indice]);

		atualizaHeap(minHeap, menor);
	}
}

// A utility function to check if
// the given minHeap is ampty or not
int vazio(struct MinHeap* minHeap){
	return minHeap->tamanho == 0;
}

// Standard function to extract minimum Noh from heap
struct MinHeapNoh* extractMin(struct MinHeap* minHeap){
	if (vazio(minHeap))
		return NULL;

	// Store the nohRaiz Noh
	struct MinHeapNoh* nohRaiz = minHeap->array[0];

	// Replace nohRaiz Noh with last Noh
	struct MinHeapNoh* ultimoNoh = minHeap->array[minHeap->tamanho - 1];
	minHeap->array[0] = ultimoNoh;

	// Update position of last Noh
	minHeap->pos[nohRaiz->v] = minHeap->tamanho-1;
	minHeap->pos[ultimoNoh->v] = 0;

	// Reduce heap tamanho and heapify nohRaiz
	--minHeap->tamanho;
	atualizaHeap(minHeap, 0);

	return nohRaiz;
}

// Function to decreasy dist value
// of a given vertex v. This function
// uses pos[] of min heap to get the
// current index of Noh in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int dist){
	// Get the index of v in heap array
	int i = minHeap->pos[v];

	// Get the Noh and update its dist value
	minHeap->array[i]->dist = dist;

	// Travel up while the complete
	// tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->array[i]->dist <
		minHeap->array[(i - 1) / 2]->dist){
		// Swap this Noh with its parent
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
		swapMinHeapNoh(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v){
	if (minHeap->pos[v] < minHeap->tamanho)
		return true;
	return false;
}

// A utility function used to print the solution
void printArr(int dist[], int n){
	for (int i = 0; i < n; ++i)
		printf("D do %d = %d \t", i, dist[i]);
}

// The main function that calculates
// distances of shortest paths from anterior to all
// vertices. It is a O(ELogV) function
void dijkstra(struct grafo* graph, int anterior){
	
	// Get the number of vertices in graph
	int V = graph->V;

	// dist values used to pick// minimum distancia edge in cut
	int dist[V];	

	// minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all // vertices. dist value of all vertices
	for (int v = 0; v < V; ++v){
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNoh(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of anterior vertex// as 0 so that it is extracted first
	minHeap->array[anterior] = newMinHeapNoh(anterior, dist[anterior]);
	minHeap->pos[anterior] = anterior;
	dist[anterior] = 0;
	decreaseKey(minHeap, anterior, dist[anterior]);

	// Initially tamanho of min heap is equal to V
	minHeap->tamanho = V;

	// In the followin loop,
	// min heap contains all Nohs
	// whose shortest distance
	// is not yet finalized.
	while (!vazio(minHeap)){
		// Extract the vertex with
		// minimum distance value
		struct MinHeapNoh* minHeapNoh = extractMin(minHeap);
	
		// Store the extracted vertex number
		int u = minHeapNoh->v;

		struct NohListaAdj* pCrawl = graph->array[u].head;
		while (pCrawl != NULL){
			int v = pCrawl->proximo;

			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->distancia + dist[u] < dist[v]){
				dist[v] = dist[u] + pCrawl->distancia;
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	


	printArr(dist, V);
}
