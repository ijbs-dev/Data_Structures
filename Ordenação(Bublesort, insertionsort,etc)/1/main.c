#include <stdio.h>

void bubblesort(int a[], int n){
  int aux;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n-1; j++){
      if (a[j] > a[j+1]){
        aux = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;        
      }
    }
  }
}

void selectionsort(int a[], int n){
  int maior, indice;
  for (int i = n-1; i > 0; i--){
    maior = a[0];
    indice = 0;
    for (int j = 1; j <= i; j++){
      if (a[j] > maior){
        maior = a[j];
        indice = j;
      }
    }
    a[indice] = a[i];
    a[i] = maior;
  }
}

int main(void) {
  int dados[] = {5, 1, 8, 3, 9, 2};
  int tam = sizeof(dados)/sizeof(int);
  for (int i = 0; i < tam; i++){
    printf("%d ", dados[i]);
  }
  printf("\n");
  
  //bubblesort(dados,tam);

  selectionsort(dados, tam);

  for (int i = 0; i < tam; i++){
    printf("%d ", dados[i]);
  }
  printf("\n");
  return 0;
}