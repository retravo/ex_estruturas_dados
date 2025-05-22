

typedef struct s_elemento **Lista;

Lista criar_lista();
int destruir_lista(Lista lista);
int adicionar_elemento(int elemento, Lista lista);
int remover_elemento(int elemento, Lista lista);
int buscar_elemento(int elemento, Lista lista);
int elemento_exite(int elemento, Lista lista);
int view(Lista lista);
