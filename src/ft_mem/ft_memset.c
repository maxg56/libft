/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:49:46 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/17 17:53:35 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count )
{
	char	*str;

	str = pointer;
	while (count--)
		*str++ = (unsigned char)value;
	return (pointer);
}
