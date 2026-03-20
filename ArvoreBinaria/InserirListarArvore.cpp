#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
};

typedef struct nodo Nodo;

Nodo* create(int valor)
{
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n)
{
	if(n==NULL){		
		return;		
	}		
	imprimir(n->esq);
	printf("\n Valor: %d\n",n->valor);
	imprimir(n->dir);
}

void add(Nodo *n, int valor)
{
	if(valor < n->valor)
	{
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
	}
	else
	{
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

int main(void) {  	
	Nodo *raiz = create(5);
	add(raiz,2);
	add(raiz,1);
	add(raiz,8);
	add(raiz,4);	
	imprimir(raiz);
  	return 0;
}
