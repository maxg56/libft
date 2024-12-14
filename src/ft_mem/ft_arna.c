/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:01:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 00:10:35 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_arna_malloc_orig(void)
{
	static t_list	*arna = NULL;

	if (arna == NULL)
	{
		arna = ft_lstnew(malloc(64000));
		if (arna == NULL || arna->content == NULL)
			return (NULL);
	}
	return (&arna);
}

void	*ft_arna_malloc( size_t saze)
{
	t_list			**arna;
	void			*allocated;
	static size_t	i = 0;
	static size_t	saze_aloc = 64000;

	arna = ft_arna_malloc_orig();
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


void	ft_arna_free_all(void)
{
	t_list	*arna;
	t_list	*tmp;

	arna = *ft_arna_malloc_orig();
	while (arna)
	{
		tmp = arna;
		arna = arna->next;
		free(tmp->content);
		free(tmp);
	}
}

