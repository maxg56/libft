/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/12 17:16:50 by mgendrot         ###   ########.fr       */
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

static t_list	**ft_arnalloc_orig(int i)
{
	static t_list	**arna = NULL;

	if (arna == NULL)
	{
		arna = (t_list **)malloc(sizeof(t_list *) * ARNA_TAB_MAX);
		if (arna == NULL)
			return (NULL);
	}
	if (arna[i] == NULL)
	{
		arna[i] = ft_lstnew_malloc(malloc(64000));
		if (arna[i] == NULL )
			return (NULL);
	}
	if (i != -1)
		return (&arna);
	return (&arna[i]);
}


int get_arna_tad(int i_tad)
{
	static int i = 0;
	if (i_tad != -1)
	{
		return(i);
	}
	if (i_tad != i)
	{
		i = i_tad;
	}
	return(i);
}

void	*ft_arnalloc( size_t saze)
{
	t_list			**arna;
	void			*allocated;
	static size_t	i = 0;
	size_t	saze_aloc = 64000;

	arna = ft_arnalloc_orig(get_arna_tad(-1));
	if (saze + i > saze_aloc)
	{
		while (saze > saze_aloc)
			saze_aloc *= 2;
		ft_lstadd_front(arna, ft_lstnew(malloc(saze_aloc)));
		i = 0;
	}
	allocated = (void *)((uintptr_t)((*arna)->content) + i);
	i += saze;
	return (allocated);
}

void	ft_arna_free(void)
{
	t_list	*arna;
	t_list	*tmp;

	arna = ft_arnalloc_orig(get_arna_tad(-1));
	if (!arna)
		return ;
	while (arna)
	{
		tmp = arna;
		arna = arna->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_arna_tab(int i)
{
	get_arna_tad(i);
	
	ft_arna_free();
}

void	ft_arna_tab_free(void)
{
	int i;
	
	i = ARNA_TAB_MAX;
	while (i--)
		ft_arna_tab(i);
	free(ft_arnalloc_orig(-1));
	
}