/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:42:36 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/16 22:30:13 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// size_t	ft_strlen(const char *str)
// {
// 	if (!str || *str == '\0')
// 		return (0);
// 	return (1 + ft_strlen(str + 1));
// }

