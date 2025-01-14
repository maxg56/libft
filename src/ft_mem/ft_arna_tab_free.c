/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna_tab_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:14 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/14 15:15:03 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fonction pour libérer toute la mémoire allouée
void	free_memory_pool(void)
{
	t_list	**pool;
	t_list	*next;
	t_list	*current;
	int		i;

	pool = *get_memory_pool();
	if (!pool)
		return ;
	i = 0;
	while (i < MEMORY_POOL_MAX)
	{
		current = pool[i];
		while (current)
		{
			next = current->next;
			free(current->content);
			free(current);
			current = next;
		}
		i++;
	}
	free(pool);
}

void	*free_memory_pool_line(int index)
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

