#include <stdio.h>
#include <stdlib.h>

typedef struct nodos{

	int valor;
	struct nodos *esquerda;
	struct nodos *direita;

} nodos;

nodos* AddNodos(nodos *, int);
void showPre(nodos *);
void showIn(nodos *);
void showPost(nodos *);
void erase(nodos *);

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
		showPre(arvore);
		printf("\n");
		printf("In..:");
		showIn(arvore);
		printf("\n");
		printf("Post:");
		showPost(arvore);
		printf("\n\n");
		erase(arvore);

	}

    return 0;
}


///  F U N C O E S  ///

nodos* AddNodos(nodos *arvore, int valor)
{

	if (!arvore)
	{

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

void showPost(nodos *arvore)
{

	if (arvore)
	{

		showPost(arvore->esquerda);
		showPost(arvore->direita);
		printf(" %d", arvore->valor);

	}

}

void showPre(nodos *arvore)
{

	if (arvore)
	{

		printf(" %d", arvore->valor);
		showPre(arvore->esquerda);
		showPre(arvore->direita);

	}

}
void showIn(nodos *arvore)
{

	if (arvore)
	{

		showIn(arvore->esquerda);
		printf(" %d", arvore->valor);
		showIn(arvore->direita);

	}

}

void erase(nodos *arvore)
{

	if (arvore)
	{

		erase(arvore->esquerda);
		erase(arvore->direita);
		free(arvore);
		arvore = NULL;

	}

}