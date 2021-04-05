#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int chave;
    struct no* prox;
}no;

typedef struct Pilha{
    no *topo;
    int tamanho;
}pilha;

void iniciaPilha(pilha *p){
   p->topo = NULL;
   p->tamanho = 0;
}

void push(int n, pilha *p){
 no *ptr = malloc(sizeof(no));
 
 ptr->chave = n;
 ptr->prox = p->topo;
 p->topo = ptr;
 p->tamanho = p-> tamanho + 1;
 
 

}

pilha* remove_duplicados(pilha* b){
    no* a;
    no* p;
    no* q;

    for(p = b->topo ; p != NULL; p = p -> prox ){
        a = NULL; 

        for(q = p -> prox; q != NULL; ){ 
            if(p -> chave == q -> chave){ 
                if(a == NULL){ 
                    p -> prox = q -> prox;
                }
                else{ 
                    a -> prox = q -> prox;
                }

                no* remover = q;
                q = q -> prox;
                free(remover);
            }
            else { 
                a = q;
                q = q->prox;
            }
        }
    }

    return b;
}


int pop(pilha *p){
 no* ptr = p->topo;
 int dado;

p->topo = ptr->prox;
ptr->prox = NULL;
dado = ptr->chave;
free(ptr);

return dado;



 }

void imprimir(pilha *p){
    no* ptr = p->topo;

    if (ptr == NULL)
    {
        printf("erro, a pilha está vazia");
    } else{

         while (ptr != NULL)
         {
             printf("%d ", ptr->chave);
             ptr = ptr->prox;
        }
         printf("\n");

    }
    




}


int main() {

pilha *p1 = (pilha*) malloc(sizeof(pilha));
iniciaPilha(p1);

 int n;
    scanf("%d", &n);
    while (n != -1)
    {
        push(n, p1);
        scanf("%d", &n);
    }

pilha *aux = (pilha*) malloc(sizeof(pilha));
iniciaPilha(aux);
int dado;
 n = 0;
while(n < p1->tamanho)
 {
     dado = pop(p1);
     push(dado, aux);

 }

free(p1);

 remove_duplicados(aux);
 imprimir(aux);










  




}