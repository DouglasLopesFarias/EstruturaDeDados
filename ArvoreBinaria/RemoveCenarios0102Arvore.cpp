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
	if(n==NULL)
		return;
	imprimir(n->esq);
	printf("\n%d",n->valor);
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

void rem(Nodo *n, int valor)
{
	Nodo *filho = n;
	Nodo *pai;
	do{
		pai = filho;
		if(valor < filho->valor)
			filho = filho->esq;
		else if(valor > filho->valor)
			filho = filho->dir;	
	}while(filho!=NULL && filho->valor != valor);

	if(filho != NULL){ // nodo com o valor correspondente encontrado
		if(filho->esq == NULL && filho->dir == NULL){ // nodo folha
			printf("%d Ã© nodo folha\n",valor);
			if(pai->esq == filho) pai->esq = NULL;
			if(pai->dir == filho) pai->dir = NULL;
		}
		if(filho->esq != NULL && filho->dir == NULL){ // nodo com 1 filho a esquerda
			printf("%d tem um filho a esquerda\n",valor);
			if(pai->esq == filho) pai->esq = filho->esq;
			if(pai->dir == filho) pai->dir = filho->esq;
		}
		if(filho->esq == NULL && filho->dir != NULL){ // nodo com 1 filho a direita
			printf("%d tem um filho a direita\n",valor);
			if(pai->esq == filho) pai->esq = filho->dir;
			if(pai->dir == filho) pai->dir = filho->dir;
		}
		
		/*if(filho->esq != NULL && filho->dir != NULL) // nodo com 2 filhos
		{
			printf("%d tem dois filhos\n",valor);
			if(filho->esq->dir==NULL){
				filho->valor = filho->esq->valor;
				filho->esq = NULL;
			}else{
				Nodo *p = filho->esq;
				Nodo *aux = p;
				while(p->dir != NULL){
					aux = p;
					p = p->dir;
				}
				aux->dir = NULL;
				filho->valor = p->valor;
			}
		}*/
		
		
		if(filho->esq != NULL && filho->dir != NULL){ // Nodo com 2 filhos
		    printf("%d tem dois filhos, usando sucessor\n", valor);
		    
		    Nodo *paiSucessor = filho;
		    Nodo *sucessor = filho->dir; // Começa indo para a direita
		    
		    // Busca o menor valor da subárvore direita (o mais à esquerda possível)
		    while(sucessor->esq != NULL) {
		    	paiSucessor = sucessor;
		    	sucessor = sucessor->esq;
		    }
		    
		    // 1. Substitui o valor do nó que queremos "apagar" pelo valor do sucessor
		    filho->valor = sucessor->valor;
		    
			// 2. Ajusta os ponteiros para remover o nó sucessor original
			// Se o sucessor for o filho direto da direita:
			if (paiSucessor == filho) {
				filho->dir = sucessor->dir;
			} 
			// Se o sucessor estiver lá no fundo à esquerda:
			else {
				paiSucessor->esq = sucessor->dir; 
		    }
		    // 3. Libera a memória do nó que foi movido
		    free(sucessor);
	    }

		
	}
}

int main(void) {

	Nodo *root = create(5);

	add(root,2);
	add(root,0);
	add(root,1);
	add(root,8);
	add(root,4);

	rem(root,2);
	rem(root,1);
	rem(root,0);
	rem(root,5);

	imprimir(root);

  	return 0;
}
