#include <stdio.h>

int Separa(int vetor[], int pivo, int n){

  int AUX[n];
    int aux2=0;
    int pivo = vetor[pivo];
    int i;
    for(i=0; i < n; i++){
        if(vetor[i] < pivo){
     AUX[aux2] = vetor[i];
     aux2++;
        }
    }

    AUX[aux2] = pivo;
    aux2++;


    for(i=0; i < n; i++){
        if(vetor[i] > pivo){
        AUX[aux2] = vetor[i];
        aux2++;
        }
    }
    for(i=0; i < n; i++){
        vetor[i] = AUX[i];
    }
}




int main(){

int pivo, n = 0;
scanf("%d",&n);
scanf("%d",&pivo);
int *vetor;
scanf("%d",&n);
  vetor = (int*) malloc(n* sizeof(int));
 
 pivo = pivo - 1;
 for (int i = 0; i < n; i++)
  {
    scanf("%d",&vetor[i]);
  }



    Separa(vetor, pivo, n);
    for(int t=0; t < n; t++){
        printf("%d ", vetor[t]);
    }


}