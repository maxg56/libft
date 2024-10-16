/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:20:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/16 11:28:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(unsigned char car)
{
	if (car >= '0' && car <= '9')
		return (1);
	if (car < 'A' || car > 'z')
		return (0);
	if (car > 'Z' && car < 'a')
		return (0);
	return (1);
}
