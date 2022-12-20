#include <stdio.h>
#include <stdlib.h>

typedef struct No {
int dado;
struct No *esq, *dir; /* *pai */
} No;

No *criar_no(int x) {
No *r = malloc(sizeof(No));
r->dado = x;
r->esq = NULL;
r->dir = NULL;
return r;
}


int main(void) {
  No *tree = criar_no(10);
  return 0;
}