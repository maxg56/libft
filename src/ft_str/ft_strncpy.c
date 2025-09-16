/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:47:51 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/16 22:33:09 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ret;

	ret = dest;
	while (n-- && *src)
		*dest++ = *src++;
	while (n--)
		*dest++ = '\0';
	return (ret);
}
