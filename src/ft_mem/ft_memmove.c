/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:17:55 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/16 19:13:28 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || !dst || !src)
		return (NULL);
	i = 0;
	while (dst > src && len-- > 0)
		((char *)dst)[len] = ((char *)src)[len];
	while (dst < src && i++ < len)
		((char *)dst)[i - 1] = ((char *)src)[i - 1];
	return (dst);
}
