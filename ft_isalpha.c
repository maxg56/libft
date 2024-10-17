/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:20:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/17 12:30:11 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(unsigned char car)
{
	if (car < 'A' || car > 'z')
		return (0);
	if (car > 'Z' && car < 'a')
		return (0);
	return (1);
}
