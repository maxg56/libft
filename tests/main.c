/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:03:47 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 15:14:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_atoi();
	test_ft_bzero();
	test_ft_calloc();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_memmove();
	test_ft_memset();
	test_ft_strchr();
	test_ft_strdup();
	test_ft_strlcat();
	test_ft_memcpy();
	test_ft_strnstr();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strrchr();
	test_ft_strlcpy();
	test_ft_strtrim();
	test_ft_itoa();
	test_ft_strmapi();
	ft_putendl_fd("maxxxxxx", 1);
	ft_putnbr_fd(5, 1);
	return (0);
}