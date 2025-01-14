/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:01:48 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/14 15:29:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len ;

	len = 0;
	if (n <= 0)
		len = 1 ;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_arn_tab_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = get_num_len(n);
	str = (char *)allocate_from_pool(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else
		num = n ;
	while (len-- && (n >= 0 || len))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_arn_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = get_num_len(n);
	str = (char *)ft_arnalloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		num = -n;	char *allocated_memory = allocate_from_pool(64000);
	get_current_pool_index(2);
	allocated_memory = allocate_from_pool(64000);
	if (!allocated_memory)
		return 1;
	ft_arn_tab_substr("Hello World", 0, 5);
	// Utilisation de la mémoire allouée
	free_memory_pool_line(2);
	ft_arn_tab_calloc(10, 10);
	allocated_memory = allocate_from_pool(64000);
	get_current_pool_index(1);
	allocated_memory = allocate_from_pool(700000000);
	free_memory_pool();
		return 0;
}
		str[0] = '-';
	}
	else
		num = n ;
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
	unsigned int	num;

	len = get_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else
		num = n ;
	while (len-- && (n >= 0 || len))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
