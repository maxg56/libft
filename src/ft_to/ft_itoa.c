/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:01:48 by mgendrot          #+#    #+#             */
/*   Updated: 2025/09/17 18:40:56 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arn_itoa(int n)
{
	char			*str;
	int				len;
	long			num;

	num = n;
	len = (n <= 0);
	while (num && ++len)
		num /= 10;
	str = (char *)ft_arn_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	num = (long)n * (n < 0) * -1 + n * (n >= 0);
	while (len-- && (n >= 0 || len))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long			num;

	num = n;
	len = (n <= 0);
	while (num && ++len)
		num /= 10;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	num = (long)n * (n < 0) * -1 + n * (n >= 0);
	while (len-- && (n >= 0 || len))
	{
		str[len] = (num % 10) + '0' ;
		num /= 10;
	}
	return (str);
}
