/**
 * @author Francisco Urbano 5/25
 */


#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"

int main(int argc, const char *args[]){

	ArvoreBinaria* ab = create_tree();
	insert_node(50, ab);
	insert_node(70, ab);
	insert_node(25, ab);
	insert_node(20, ab);
	insert_node(30, ab);
	insert_node(35, ab);
	insert_node(27, ab);

	print_in_order(ab);

	remove_node(ab, 50);
	printf("\n");
	print_in_order(ab);
	free_tree(ab);
	
	return 0;
}
