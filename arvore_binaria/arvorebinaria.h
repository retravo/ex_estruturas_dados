
typedef struct s_node* ArvoreBinaria;

struct s_node** create_tree();
int free_tree(struct s_node **root);
int tree_depth(struct s_node **root);
int nodes_quantity(struct s_node **root);
void print_pre_order(struct s_node **root);
void print_in_order(struct s_node **root);
void print_pos_order(struct s_node **root);
int insert_node(int value, struct s_node **root);
int remove_node(struct s_node **root, int value);
