# include "libft.h"



int main(void) {
	// Exemple d'utilisation
	char *allocated_memory = allocate_from_pool(64000);
	get_current_pool_index(2);
	allocated_memory = allocate_from_pool(64000);
	if (!allocated_memory)
		return 1;
	ft_arn_tab_substr("Hello World", 0, 5);
	// Utilisation de la mémoire allouée
	free_memory_pool_line(2);
	ft_arn_tab_calloc(10, 10);
	allocated_memory = allocate_from_pool(64000);
	get_current_pool_index(1);
	allocated_memory = allocate_from_pool(700000000);
	free_memory_pool();
		return 0;
}