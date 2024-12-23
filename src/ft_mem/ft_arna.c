/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:01:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 21:56:06 by mgendrot         ###   ########.fr       */
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

static t_list	**ft_arnalloc_orig(void)
{
	static t_list	*arna = NULL;

	if (arna == NULL)
	{
		arna = ft_lstnew_malloc(malloc(64000));
		if (arna == NULL )
			return (NULL);
	}
	return (&arna);
}

void	*ft_arnalloc( size_t saze)
{
	t_list			**arna;
	void			*allocated;
	static size_t	i = 0;
	static size_t	saze_aloc = 64000;

	arna = ft_arnalloc_orig();
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

	arna = *ft_arnalloc_orig();
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
