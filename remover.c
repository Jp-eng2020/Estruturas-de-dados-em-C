
#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* pai;
  struct NODE* esquerda;
  struct NODE* direita;
};
typedef struct NODE NO;

NO* criar() {
   return NULL;
}


void incluir(NO **p, int n)
{
	if (*p == NULL)
	{
	      *p=(NO *)malloc(sizeof (NO));
	      (*p)->esquerda=NULL;
	      (*p)->direita=NULL;
	      (*p)->chave=n;
	}
	else 
        {
		if (n < ((*p)->chave))
		{
			incluir(&((*p)->esquerda), n);
		}
		else
		{
			incluir(&((*p)->direita), n);
		}
	}
}

NO* minimo(NO* p) {
	if(p == NULL) return NULL;
	if(p->esquerda == NULL) return p;
	else minimo(p->esquerda); 
}

NO *remover_no(NO* p, int n)
{
    
    if(p == NULL)
        return NULL;
 
    if(p->chave < n)
        p->direita = remover_no(p->direita,n);
 
    else if(p->chave > n)
        p->esquerda = remover_no(p->esquerda,n);
   
    else
    {
      
        if(p->esquerda == NULL && p->direita == NULL)
        {
            free(p);
            return NULL;
        }
        
        else if(p->esquerda == NULL)
        {
            struct node *temp = p->direita;
            free(p);
            return temp;
        }
        
        else if(p->direita == NULL)
        {
            struct node *temp = p->esquerda;
            free(p);
            return temp;
        }
        
        else
        {
            int direitaMin = minimo(p->direita);
            p->chave = direitaMin;
            p->direita = remover_no(p->direita,direitaMin);
        }

    }


    return p;
}

void imprimir(NO *p){
    if(p != NULL){
        imprimir(p->esquerda);
        printf("\n%i", p->chave);
        imprimir(p->direita);
    }
}



int main() {
   NO* arvore;
   arvore = criar();
   
   int n;
    scanf("%d", &n);
    while (n != -1)
    {
        incluir(&arvore, n);
        scanf("%d", &n);
    }
    scanf("%d", &n);
    remover_no(&arvore, n);

 imprimir(arvore);

   
}
