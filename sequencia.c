entrada: a arvore a ser impressa em ordem simetrica. do menor para o maior


função
 imprimir( recebe a arvore como parametro){

    se arvore != de nula;{

        imprimir(arvore->esquerda); eu passo o nó da esquerda que eu sei que será o menor a ser impresso
        como o if entrou e viu essa função ele vai rodar ela antes de descermos para a segunda linha.
        printf(p->chave); imprimindo os da esquerda que são menores que o nó chave eu posso finalmente imprimir ele.
        imprimir(arvore->direita); agora entrando na direita do nó chave ele ira imprimir os maiores que o nó chave.







    }

     lembrando que pela recursividade da função, todos os nós meio que são tratados como chave, fazendo com que a verificação bi lateral 
     seja feita em todos, garantindo que saia de forma que seja sequencial.








 }