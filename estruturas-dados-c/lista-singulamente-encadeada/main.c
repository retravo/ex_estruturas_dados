#include <stdio.h>
#include <stdlib.h>
#include "lista_singular.h"

int main(int argc, const char *args[]){
    Lista inteiros = criar_lista();

    adicionar_elemento(332, inteiros);
    adicionar_elemento(123, inteiros);
    adicionar_elemento(545, inteiros);
    adicionar_elemento(948, inteiros);

    adicionar_elemento(432, inteiros);
    adicionar_elemento(432, inteiros);

    remover_elemento(545, inteiros);


    printf("%d\n", view(inteiros));
    destruir_lista(inteiros);
    printf("%d\n", view(inteiros));

}
