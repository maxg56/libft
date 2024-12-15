/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:08 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 01:26:33 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size )
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
