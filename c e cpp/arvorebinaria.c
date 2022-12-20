#include <stdio.h>
#include <stdlib.h>

typedef struct nodos{

	int valor;
	struct nodos *esquerda;
	struct nodos *direita;

} nodos;

nodos* AddNodos(nodos *, int);
void printPre(nodos *);
void printIn(nodos *);
void printPost(nodos *);
void liberaMem(nodos *);

int main(){

	unsigned short i;
	int valor;

	unsigned short QuantNodos;
	unsigned short QuantCasos, caso = 0;
    //printf("quantos casos?");
	scanf("%hu", &QuantCasos);

	while (QuantCasos>0){

		nodos *arvore = NULL;
        //printf("quantos nos?");
		scanf("%hu", &QuantNodos);

		for (i = 0; i < QuantNodos; i++)
		{
			scanf("%d", &valor);
			arvore = AddNodos(arvore, valor);

		}

		printf("Case %hu:\n", ++caso);
		printf("Pre.:");
		printPre(arvore);
		printf("\n");
		printf("In..:");
		printIn(arvore);
		printf("\n");
		printf("Post:");
		printPost(arvore);
		printf("\n\n");
		liberaMem(arvore);

	}

    return 0;
}


///  F U N C O E S  ///

nodos* AddNodos(nodos *arvore, int valor){

	if (!arvore){

		arvore = (nodos *) malloc(sizeof(nodos));
		arvore->valor = valor;
		arvore->esquerda = arvore->direita = NULL;

	}
	else if (arvore->valor > valor)
		arvore->esquerda = AddNodos(arvore->esquerda, valor);

	else
		arvore->direita = AddNodos(arvore->direita, valor);

	return arvore;

}

void printPost(nodos *arvore){

	if (arvore){

		printPost(arvore->esquerda);
		printPost(arvore->direita);
		printf(" %d", arvore->valor);

	}

}

void printPre(nodos *arvore){

	if (arvore){

		printf(" %d", arvore->valor);
		printPre(arvore->esquerda);
		printPre(arvore->direita);

	}

}
void printIn(nodos *arvore){

	if (arvore){

		printIn(arvore->esquerda);
		printf(" %d", arvore->valor);
		printIn(arvore->direita);

	}

}

void liberaMem(nodos *arvore){

	if (arvore){

		liberaMem(arvore->esquerda);
		liberaMem(arvore->direita);
		free(arvore);
		arvore = NULL;

	}

}