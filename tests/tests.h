#ifndef TESTS_H
# define TESTS_H

#include "../include/libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_atoi(void);
void test_ft_bzero();
void test_ft_calloc();
void test_ft_memchr();
void test_ft_memcmp();
void test_ft_memmove();
void test_ft_memset();
void test_ft_strchr();
void test_ft_strdup();
void test_ft_strlcat();
void test_ft_memcpy();
void test_ft_strnstr();
void test_ft_strnstr();
void test_ft_tolower(void);
void test_ft_strrchr(void);
void test_ft_strlcpy(void);
void    test_ft_strtrim(void);
void	test_ft_itoa(void);
static char	change_case(unsigned int i, char c);
void	test_ft_strmapi(void);
#endif 