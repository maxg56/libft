/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:35:01 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/17 18:20:25 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	neg;
	long	num;

	neg = 1;
	num = 0;
	while (((*str <= '\r' && *str >= '\t' ) || *str == ' ' ) && *str++)
		;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg *= -1;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - 48);
	return (num * neg);
}

