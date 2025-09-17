/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:19:21 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/17 18:22:43 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;

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
