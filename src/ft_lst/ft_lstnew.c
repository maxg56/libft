/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:20:34 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/30 18:53:06 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arn_lstnew(void *content)
{
	t_list	*lst;

	lst = ft_arnalloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}
