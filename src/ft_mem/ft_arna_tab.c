/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/13 14:09:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_malloc(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	***ft_arnalloc_tab__orig(void)
{
	int				i;
	static t_list	**arna = NULL;

	i = 0;
	if (arna == NULL)
	{
		arna = (t_list **)malloc(sizeof(t_list *) * ARNA_TAB_MAX);
		if (arna == NULL)
			return (NULL);
		while (i < ARNA_TAB_MAX)
			arna[i++] = NULL;
	}
	return (&arna);
}

t_list	**ft_arnalloc_tab_line(int i)
{
	t_list	**arna;

	arna = *ft_arnalloc_tab__orig();
	if (arna[i] == NULL)
	{
		arna[i] = ft_lstnew_malloc(malloc(ARNA_SIZE));
		if (arna[i] == NULL )
			return (NULL);
	}
	return (&arna[i]);
}

int	get_arna_tad(int i_tad)
{
	static int	i = 0;

	if (i_tad < -1)
		return (0);
	else if (i_tad != -1)
		return (i);
	else if (i_tad != i)
		i = i_tad;
	return (i);
}

void	*ft_tab_arnalloc( size_t saze)
{
	t_list			**arna;
	void			*allocated;
	static size_t	saze_aloc = ARNA_SIZE;
	static size_t	i = 0;

	arna = ft_arnalloc_tab_line(get_arna_tad(-1));
	if (saze + i > saze_aloc)
	{
		if (saze_aloc > ARNA_SIZE)
			saze_aloc = ARNA_SIZE;
		while (saze > saze_aloc)
			saze_aloc *= 2;
		ft_lstadd_front(arna, ft_lstnew(malloc(saze_aloc)));
		i = 0;
	}
	allocated = (void *)((uintptr_t)((*arna)->content) + i);
	i += saze;
	return (allocated);
}
