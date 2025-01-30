/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:08 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/30 18:52:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arn_calloc(size_t count, size_t size )
{
	void	*ptr;

	if (size == 0 || count == 0)
		return (ft_arnalloc(0));
	if ((size_t)count * (size_t)size > SIZE_MAX)
		return (NULL);
	ptr = (void *)ft_arnalloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size )
{
	void	*ptr;

	if (size == 0 || count == 0)
		return (malloc(0));
	if ((size_t)count * (size_t)size > SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
