/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/14 15:20:14 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Fonction pour créer un nouveau nœud de liste
t_list	*create_list_node(void *content)
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
t_list	***get_memory_pool(void)
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
void	*allocate_from_pool(size_t size)
{
	static size_t	current_offset = 0;
	static size_t	current_block_size = DEFAULT_BLOCK_SIZE;
	t_list			**current_line;
	t_list			*new_block;
	void			*allocated_memory;

	current_line = get_memory_pool_line(get_current_pool_index(-1));
	if (!current_line)
		return (NULL);
	if (current_offset + size > current_block_size)
	{
		while (size > current_block_size)
			current_block_size *= 2;
		new_block = create_list_node(malloc(current_block_size));
		if (!new_block)
			return (NULL);
		new_block->next = *current_line;
		*current_line = new_block;
		current_offset = 0;
	}
	allocated_memory = (void *)((uintptr_t)((*current_line)->content) + \
	current_offset);
	current_offset += size;
	return (allocated_memory);
}
