/**
 * @author Francisco Urbano, 5/25
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"


//Estrutura principal da implementação
struct s_node
{
	int value;
	struct s_node* left_tree;
	struct s_node* right_tree;	
};


//Cria a raiz da arvore. A raiz é um tipo de nó especial que
//aponta para o primeiro elemento da arvore.
struct s_node** create_tree()
{
	struct s_node** root = (struct s_node**) malloc(sizeof(struct s_node*));
	if(root != NULL)
	{
		*root = NULL; //Arvore fica vazia.
	}

	return root;
}


//Destruição da arvore. Percorrer todos os nós da arvore de modo
//a liberar a memoria alocada para cada um deles.
void free_nodes(struct s_node *node)
{
	if(node == NULL) return; //atigiu um nó folha

	free_nodes(node->left_tree);
	free_nodes(node->right_tree);
	free(node);
}

int free_tree(struct s_node **root)
{	
	//Verifica se a raiz é valida.
	if(root == NULL)
	{
		printf("Erro de parametro ou node vazio...\n");
		return 1;
	}

	free_nodes(*root);
	free(root); //Libera a memoria alocada pela a função create_tree().
	return 0;
}

//Obtem a profundidade/nivel da arvore, percorrendo de forma recursiva a arvore.
int tree_depth(struct s_node **root) 
{	
	//Verifica a valida do parametro root. 
	if(root == NULL || *root == NULL)
	{
		printf("Parametro invalidos\n");
		return 0;
	}

	int left_depth  = tree_depth(&(*root)->left_tree);
	int right_depth = tree_depth(&(*root)->right_tree);

	//Retorna a maior sub-arvore.
	if(left_depth > right_depth) return (left_depth + 1);
	return (right_depth + 1);
}
	
//Obtem de elementos tem na arvore
int nodes_quantity(struct s_node **root)
{
	if(root == NULL || *root == NULL) 
	{
		printf("parametro invalidos\n");
		return 0;
	}

	int left_height  = nodes_quantity(&(*root)->left_tree);
	int right_height = nodes_quantity(&(*root)->right_tree);
	return (left_height + right_height + 1);
}

void print_pre_order(struct s_node **root)
{
	if(*root == NULL || root == NULL){
		return;
	} 

	printf("%d ", (*root)->left_tree);
	print_pre_order((&(*root)->left_tree));	
	print_pre_order((&(*root)->right_tree));	
}

void print_in_order(struct s_node **root)
{
	if(*root == NULL || root == NULL){
		return;
	} 

	print_in_order(&((*root)->left_tree));	
	printf("%d ", (*root)->value);
	print_in_order(&((*root)->right_tree));	
}

void print_pos_order(struct s_node **root)
{
	if(*root == NULL || root == NULL){
		return;
	} 

	print_pos_order(&((*root)->left_tree));	
	print_pos_order(&((*root)->right_tree));	
	printf("%d ", (*root)->value);
}

int insert_node(int value, struct s_node **root)
{
	if(root == NULL) return 1;

	//Aloca memoria para o novo nó
	struct s_node *new_node = (struct s_node*) malloc(sizeof(struct s_node));
	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->left_tree = NULL;
		new_node->right_tree = NULL; 
	}

	//Trata o caso em que raiz da arvore esta vazia.
	if(*root == NULL) 
	{
		//novo né agora é a raiz da arvore.
		*root = new_node;
	} else {
		//procura onde inserir o novo nó.
		struct s_node *current_node = *root;
		struct s_node *tmp_node = NULL;
		do {
			tmp_node = current_node;
			//trata se o valor ja estiver na arvore.
			if(value == current_node->value)
			{
				free(new_node); //libera o nó redundante.
				printf("Valor já perternce a arvore.\n");
				return 0; //Encerrar o loop que procura em qual nó inserir.
			} 
			
			//Avança para o filho da direita.
			if(value > current_node->value) current_node = current_node->right_tree;
			//Avança para o filho da esquerda.
			else current_node = current_node->left_tree;
			

		} while(current_node != NULL);

		//Conectar os nó
		if(value > tmp_node->value) tmp_node->right_tree = new_node;
		else tmp_node->left_tree = new_node;

	} //end else.

	return 0;
}

struct s_node* remove_current(struct s_node *current_node)
{
	struct s_node *node1, *node2;

	if(current_node->left_tree == NULL)
	{
		node2 = current_node->right_tree;
		free(current_node);
		return node2;
	}

	node1 = current_node;
	node2 = current_node->left_tree;

	while(node2->right_tree != NULL)
	{
		node1 = node2; //Nó anterio.
		node2 = node2->right_tree; // desce na sub-arvore esquerda ate nó folha.
	}

	//Se ouver mudança execute.
	if(node1 != current_node)
	{	
		//Nó anterio ao mais a direita de atual receber o nó a esquerda
		//pq node2 não tem mais nó a direita.
		node1->right_tree = node2->left_tree;
		node2->left_tree = current_node->left_tree;
	}

	node2->right_tree = current_node->right_tree;
	free(current_node);
	return node2;
}

int remove_node(struct s_node **root, int value)
{
	if(*root == NULL || root == NULL) return 1;

	struct s_node *current_node = *root;
	struct s_node *tmp_node = NULL;

	while(current_node != NULL)
	{	
		//Acho o nó a ser removido.
		if(value == current_node->value)
		{	
			//Verifica se o nó é a raiz.
			if(current_node == (*root)) *root = remove_current(current_node);
			else
			{
				if(tmp_node->left_tree == current_node) tmp_node->left_tree = remove_current(current_node);
				else tmp_node->right_tree = remove_current(current_node);
			}

			return 0;
		}
		//Guada o valor de atual antes de caminha na arvore.
		tmp_node = current_node;

		//Percorre na arvore a procura do nó.
		if(value > current_node->value) current_node = current_node->right_tree;
		else current_node = current_node->left_tree;

	} //end while.

}
