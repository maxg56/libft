/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arna_tab_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:14 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/13 14:27:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tab_arna_free(void)
{
	t_list	*arna;
	t_list	*tmp;

	arna = *ft_arnalloc_tab_line(get_arna_tad(-1));
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

void	ft_arna_tab_free(int i)
{
	get_arna_tad(i);
	ft_tab_arna_free();
}

void	ft_arna_tab_free_free(void)
{
	int	i;

	i = ARNA_TAB_MAX;
	while (i--)
		get_arna_tad(i);
	free(ft_arnalloc_tab__orig());
}
