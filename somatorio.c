#include <stdio.h>
int somatorio(int n){


    int soma;

    if (n == 0)
        return 0;
    else
        soma = n + somatorio(n - 1);

    return soma;
}






int main(){
int n = 0;

scanf("%d",&n);

int soma = somatorio(n);
printf("%d\n", soma);

}