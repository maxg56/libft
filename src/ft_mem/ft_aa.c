#include <stdlib.h>
#include <stdint.h>


#define MEMORY_POOL_MAX 1024 // Ancien ARNA_TAB_MAX
#define DEFAULT_BLOCK_SIZE 64000 // Ancien ARNA_SIZE
typedef struct s_list {
    void            *content;
    struct s_list   *next;
} t_list;

// Fonction pour créer un nouveau nœud de liste
static t_list	*create_list_node(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// Récupère le tableau de mémoire statique
static t_list	***get_memory_pool(void)
{
	static t_list	**pool = NULL;
	int				i;

	if (!pool)
	{

		i = 0;
		pool = malloc(sizeof(t_list *) * MEMORY_POOL_MAX);
		if (!pool)
			return (NULL);
		while (i < MEMORY_POOL_MAX)
		{
			pool[i] = NULL;
			i++;
		}
	}
	return (&pool);
}

// Récupère une ligne du tableau de mémoire
static t_list	**get_memory_pool_line(int index)
{
	t_list	**pool;
	void	*new_block;

	pool = *get_memory_pool();
	if (!pool)
		return (NULL);
	if (!pool[index])
	{
		new_block = malloc(1);
		if (!new_block)
			return (NULL);
		pool[index] = create_list_node(new_block);
		if (!pool[index])
			return (NULL);
	}
	return (&pool[index]);
}

// Gestion de l'indice courant du pool
int	get_current_pool_index(int new_index)
{
	static int	current_index ;

	current_index = 0;
	if (new_index < -1)
		return (0);
	else if (new_index == -1)
		return (current_index);
	current_index = new_index;
	return (current_index);
}

// Allocation de mémoire depuis le pool


// Fonction pour libérer toute la mémoire allouée
void free_memory_pool(void)
{
	t_list	**pool;
	int		i;

	pool = *get_memory_pool();
	if (!pool)
		return;
	i = 0;
	while (i < MEMORY_POOL_MAX)
	{
        t_list *current = pool[i];
        while (current)
		{
            t_list *next = current->next;
            free(current->content);
            free(current);
            current = next;
        }
		i++;
    }
    free(pool);
}

void *free_memory_pool_line(int index)
{
	t_list	**pool;
	t_list	*current;
	t_list	*next;

	pool = *get_memory_pool();
	if (!pool)
		return (NULL);
	if (!pool[index])
		return (NULL);
	current = pool[index];
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	pool[index] = create_list_node(malloc(1));
	return (NULL);
}

