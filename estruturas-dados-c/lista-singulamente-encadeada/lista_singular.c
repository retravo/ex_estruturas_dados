#include <stdio.h>
#include <stdlib.h>
#include "lista_singular.h"



struct s_elemento {
    int chave;
    struct s_elemento *proximo;
};

// typedef struct s_ele

struct s_elemento** criar_lista()
{
    //aloca memoria para a raiz da lista.
    struct s_elemento **lista = (struct s_elemento**) malloc(sizeof(struct s_elemento*));

    if(lista != NULL)
    {
        *lista = NULL; //raiz vazia.
    }

    return lista;
}

int destruir_lista(struct s_elemento **lista)
{
    //verifica se o ponteiro é valido.
    if(lista == NULL)
    {
        printf("Ola");

        return 0;
    }
    struct s_elemento *posicao_atual = *lista; //posição atual
    struct s_elemento *sentinela;

    //pecorre a lista liberando a memoria do elemento anterior a posição atual.
    while(posicao_atual != NULL)
    {
        //salva a posição antes de avança para o proximo elemento da lista.
        sentinela = posicao_atual;
        posicao_atual = posicao_atual->proximo;
        free(sentinela); //libera elemento anterior.
    }

    //verifica se pos_atual atingiu o final da lista
    if(posicao_atual == NULL)
    {
        free(lista); //libera a lista
        *lista = NULL;

        return 0;
    }

    return 1;
}

int adicionar_elemento(int chave, struct s_elemento **lista)
{
    if(lista == NULL) return 2; //lista invalida.

    //aloca memoria para um novo elemento e verifa o retorna de malloc
    struct s_elemento *novo_elemento = (struct s_elemento*) malloc(sizeof(struct s_elemento));
    if(novo_elemento != NULL)
    {
        //preenchemos o novo elemento.
        novo_elemento->chave = chave;
        novo_elemento->proximo = NULL; //novo elemento ensiriddo no final da lista.

        //se lista esta vazia entao novo elemento passar a ser o primeiro.
        if(*lista == NULL)
        {
            *lista = novo_elemento;
            return 0;
        }


        //pecorremos ate o ultimo elementa lista.
        struct s_elemento *posicao_atual = *lista;
        struct s_elemento *sentinela = NULL;

        while(posicao_atual->proximo != NULL)
        {
            // sentinela = posicao_atual;
            posicao_atual = posicao_atual->proximo;
        }

        //adiciona no final da lista.
        posicao_atual->proximo = novo_elemento;
        return 0;
    }

    return 1;
}

int remover_elemento(int chave, struct s_elemento **lista)
{
    if(*lista == NULL || lista == NULL)
    {
        printf("lista invalida ou lista esta vazia.\n");
        return 1;
    }

    struct s_elemento *posicao_atual = *lista;
    struct s_elemento *sentinela = NULL;

    while(posicao_atual != NULL && chave != posicao_atual->chave)
    {
        sentinela = posicao_atual;
        posicao_atual = posicao_atual->proximo;
    }

    if(posicao_atual == NULL)
    {
        printf("Elemento não encontrado.");
        return 0;
    }

    //refaz a conexao da lista sem o elemento da posicao_atual.
    sentinela->proximo = posicao_atual->proximo;
    free(posicao_atual);
    return 0;
}

int view(Lista lista)
{
    if(*lista == NULL || lista == NULL)
    {
        printf(".lista invalida ou lista esta vazia.\n");
        return 1;
    }

    struct s_elemento *posicao_atual = *lista;
    struct s_elemento *sentinela;
    while(posicao_atual != NULL)
    {
        sentinela = posicao_atual;
        printf("%d ", sentinela->chave);
        posicao_atual = posicao_atual->proximo;
    }

    printf("\n");
    return 0;
}

