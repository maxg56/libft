/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:07:20 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/16 19:00:57 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (n == 0 || !dst || !src)
		return (NULL);
	while (n-- > 0)
		*(char *)dst++ = *(char *)src++;
	return (dst);
}
