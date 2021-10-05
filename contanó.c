
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

NO* buscar(NO* arv, int x) {
    if(arv == NULL) return NULL;
    if(arv->chave == x) return arv;
    if(x <= arv->chave) return buscar(arv->esquerda,x);
    else return buscar(arv->direita,x); 
}

void insercao(NO **p, int n)
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
			insercao(&((*p)->esquerda), n);
		}
		else
		{
			insercao(&((*p)->direita), n);
		}
	}
}

int conta_no(NO *p){
   if(p == NULL)
        return 0;
   else
        return 1 + conta_no(p->esquerda) + conta_no(p->direita);
}





int main() {
   NO* arvore;

   arvore = criar();
   int n;
    scanf("%d", &n);
    while (n != -1)
    {
        incluir(arvore, n);
        scanf("%d", &n);
    }


  int nos = 0;
  nos = conta_no(arvore);

  printf("%d", nos);

   
}
