#include <stdio.h>
#include <stdlib.h>

//== 2 * 15 = 30 -> primo mais proximo 31
#define TAM 31

bool sair = false;
int op;

void inicializarTabela(int t[]){
	int i;
	for(i = 0; i < TAM; i++){
		t[i] = 0;
	}
}

int funcaoHash(int chave){
	return chave % TAM;
}

void inserir(int t[], int valor){
	int id = funcaoHash(valor);
	while( t[id] != 0){
		id = funcaoHash(id + 1);
	}
	t[id] = valor;
}

/*
  passa a chave e a tablea para fazer a busca
  pega o indice da chave
  faz o while enquanto o valor no t[id] for != 0 pois procura so os elementos preenchidos
  se achou retorna o elemento t[id] == chave
  se não pega o id da posição seguinte id = funcaoHash(id + 1;)
*/
int buscar(int t[], int chave){
	int id = funcaoHash(chave);
	while(t[id] != 0){
		if(t[id] == chave){
			return t[id];
		}else{
			id = funcaoHash(id + 1);
		}
	}	
}

void imprimir(int t[]){
	int i;
	for(i =0 ; i < TAM; i++ ){
		printf("%d = %d\n", i, t[i]);		
	}
	system("pause");
}

void menu(){    
	printf("01 - Insere\n");	
	printf("02 - Buscar \n");
	printf("03 - Imprimir\n");
	printf("04 - Sair do sistema\n");	
	printf("Digite uma opção:\n");	
}

void sairDoSistema(){
	printf("Saindo do sistema...\n");
	sair = true;
}

int main(){
	int tabela[TAM];
	int valor, retorno;
	inicializarTabela(tabela);
	
	while(!sair){
		system("CLS");
		menu();
		scanf("%d", &op);
		switch(op){			
			case 1: 
			    printf("Digite o valor a ser inserido: \n");
	            scanf("%d", &valor);
				inserir(tabela, valor); 
				break;
			case 2: 
			    printf("Digite o valor a ser localizado: \n");
	            scanf("%d", &valor);
	            retorno = buscar(tabela, valor);
	            if(retorno != 0){
	            	printf("Valor encontrado \n");	            	
				}else{
					printf("Valor nao encontrado \n");	      
				}
			    buscar(tabela, valor); 
				system("pause");
				break;
			case 3: 
			    imprimir(tabela);	
				break;
			case 4: 
			    sairDoSistema(); 
				break;			
			default: 
			    printf("Opção inválida!\n"); 
				system("pause");
		}
	}
	
	return 0;
}
