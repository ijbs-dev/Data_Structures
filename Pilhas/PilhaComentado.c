#include <stdio.h>
#include <stdlib.h>

//Constante que define o tamanho m�ximo da estrutura de dados
#define tamanho 3

//Declara��o do tipo_pilha: estrutura de dados
typedef struct tipo_pilha{
	int dados[tamanho];
	int ini;
	int topo;
}tipo_pilha;

//Criando uma vari�vel tipo_pilha
tipo_pilha pilha;

//Fun��o que empilha um novo elemento no topo
void empilha(int elemento){
	//Verificando se existe alguma posi��o dispon�vel para uma inser��o
	if(pilha.topo == tamanho){
		//Se a pilha estiver cheia, n�o � poss�vel empilhar
		printf("Pilha cheia.\n");
		system("pause");
	}
	else
	{
		//Se a pilha n�o estiver cheia:
		//	Adicione o novo elemento no topo
		//	Incremente o topo
		pilha.dados[pilha.topo] = elemento;
		pilha.topo++;
	}
}

//Fun��o que desempilha e retorna o elemento do topo
int desempilha(){
	//Vari�vel que guarda um "backup" do elemento desempilhado
	int elemento;
	
	//Verificando se existe algum elemento dispon�vel para uma remo��o
	if(pilha.topo == pilha.ini){
		//Se a pilha estiver vazia, n�o ser� poss�vel desempilhar
		printf("Pilha vazia.\n");
		system("pause");
	}
	else
	{
		//Se a pilha n�o estiver vazia
		//	Decremente o topo
		//	Retorne o elemento que est� no topo
		pilha.topo--;
		elemento = pilha.dados[pilha.topo];
		return elemento;
	}
}

int main(){
	pilha.topo = 0;
	pilha.ini = 0;
	int aux;
	
	/*printf("Testando pilha de tamanho 3...\n\n");
	for(int i=1; i<=4; i++){
		aux = i * 10;
		printf("Empilhando o %d.\n", aux);
		empilha(aux);
	}
	
	printf("Tentando desempilhar 3x seguidas.\n");
	for(int i=1; i<=3; i++){
		aux = desempilha();
		printf("Desempilhou: %d.\n", aux);
	}*/
	
	printf("Empilhando o 10.\n");
	empilha(10);
	printf("Empilhando o 20.\n");
	empilha(20);
	printf("Empilhando o 30.\n");
	empilha(30);
	printf("Empilhando o 40.\n");
	empilha(40);
	
	printf("Desempilhou: %d.\n", desempilha());
	printf("Desempilhou: %d.\n", desempilha());
	printf("Desempilhou: %d.\n", desempilha());
	printf("Desempilhou: %d.\n", desempilha());
}
