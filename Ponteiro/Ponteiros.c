#include <stdio.h>
#include <stdlib.h>
int *p;
int x[10], i;

int main(){
	
	//1 - Inicializando 'i' com 10:
	i = 10; 
	//2 - Inicializando 'p' com o end. de 'i':
	p = &i; 
	//3 - Alterando o valor de 'i' para 20 
	//(e de *p, consequentemente, para 20):
	i = 20; 
	//4 - Alterando o valor de '*p' para 30
	//(e de 'i', consequentemente, para 30):
	*p = 30; 
	
	//Imprimindo os valores para comparar:
	printf("Valor de i: %d\n", i);
	printf("Valor de &i: %d\n", &i);
	printf("Valor de p: %d\n", p);
	printf("Valor de *p: %d\n", *p);
	
}

