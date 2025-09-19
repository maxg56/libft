/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:12:53 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/19 16:45:02 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + ft_strlen(src));

	while (*src && len_dst + 1 < dstsize)
		dst[len_dst++] = *src++;
	dst[len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}
