#include <stdio.h>
#include <stdlib.h>

int max = 0;
int min = 0;

int maxmin( int vetor[], int n){

int i, j, aux;
      for (i = 1; i < n; i++) {
            j = i;
            while (j > 0 && vetor[j - 1] < vetor[j]) {
                  aux = vetor[j];
                  vetor[j] = vetor[j - 1];
                  vetor[j - 1] = aux;
                  j--;
            }
      }


max = vetor[0];
min = vetor[n - 1];

}



int main(){
int n, i = 0;

int *vetor;
scanf("%d",&n);
  vetor = (int*) malloc(n* sizeof(int));
 
 
 for (i = 0; i < n; i++)
  {
    scanf("%d",&vetor[i]);
  }
    maxmin(vetor, n);
    printf(" %d, %d", min, max);



}