#include <stdio.h>
#include <stdlib.h>

//Constante que define o tamanho máximo da estrutura de dados
#define tamanho 3

//Declaração do tipo_fila: estrutura de dados
typedef struct tipo_fila{
	int dados[tamanho];
	int ini;
	int fim;
};

//Criando uma variável tipo_fila
tipo_fila fila;

//Função que enfileira um novo elemento ao fim da fila
void enfileira(int elemento){
	//Verificando se existe alguma posição disponível para uma inserção
	if(fila.fim == tamanho){
		//Se a fila estiver cheia, não é possível enfileirar
		printf("Fila cheia.\n");
		system("pause");
	}
	else
	{
		//Se a fila não estiver cheia:
		//	Adicione o novo elemento no fim
		//	Incremente o fim
		fila.dados[fila.fim] = elemento;
		fila.fim++;
	}
}

//Função que desenfileira e retorna o elemento do início da fila
int desenfileira(){
	//Variável que guarda um "backup" do elemento desenfileirado
	int elemento;
	
	//Verificando se existe algum elemento disponível para uma remoção
	if(fila.fim == fila.ini){
		//Se a fila estiver vazia, não será possível desenfileirar
		printf("Fila vazia.\n");
		system("pause");
	}
	else
	{
		//Se a fila não estiver vazia:
		//Guarda um backcup do elemento a ser removido;
		elemento = fila.dados[fila.ini];
		//"Arrasta os elementos do "fim" em direção ao "início"
		//Nesse passo, o elemento que estava no "início" da fila será sobrescrito
		for(int i=0; i<tamanho; i++)
			fila.dados[i] = fila.dados[i+1];
		//Apaga-se o elemento que estava no "fim" (convenção: atribui-se zero ao apagar)
		fila.dados[fila.fim] = 0;
		//Decrementa-se o "fim".
		fila.fim--;
		//Retorne o elemento que estava no "início"
		return elemento;
	}
}

int main(){
	fila.fim = 0;
	fila.ini = 0;
	
	printf("Testando fila de tamanho 3...\n\n");
	printf("Enfileirando o 10.\n");
	enfileira(10);
	printf("Enfileirando o 20.\n");
	enfileira(20);
	printf("Enfileirando o 30.\n");
	enfileira(30);
	printf("Enfileirando o 40.\n");
	enfileira(40);
	
	printf("Tentando desenfileirar 3x seguidas.\n");
	printf("Desenfileirando: %d.\n", desenfileira());
	printf("Desenfileirando: %d.\n", desenfileira());
	printf("Desenfileirando: %d.\n", desenfileira());
}

