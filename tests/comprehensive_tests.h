/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprehensive_tests.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPREHENSIVE_TESTS_H
# define COMPREHENSIVE_TESTS_H

# include "../include/libft.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <unistd.h>
# include <fcntl.h>

// Test result macros
# define TEST_PASS "\033[0;32m[PASS]\033[0m"
# define TEST_FAIL "\033[0;31m[FAIL]\033[0m"
# define TEST_INFO "\033[0;34m[INFO]\033[0m"
# define TEST_WARN "\033[0;33m[WARN]\033[0m"

// Test categories
void run_is_tests(void);
void run_mem_tests(void);
void run_str_tests(void);
void run_to_tests(void);
void run_put_tests(void);
void run_lst_tests(void);
void run_gnl_tests(void);
void run_printf_tests(void);
void run_arena_tests(void);

// Individual test functions
// is functions
void test_ft_isalpha_comprehensive(void);
void test_ft_isdigit_comprehensive(void);
void test_ft_isalnum_comprehensive(void);
void test_ft_isascii_comprehensive(void);
void test_ft_isprint_comprehensive(void);

// mem functions
void test_ft_memset_comprehensive(void);
void test_ft_bzero_comprehensive(void);
void test_ft_memcpy_comprehensive(void);
void test_ft_memmove_comprehensive(void);
void test_ft_memchr_comprehensive(void);
void test_ft_memcmp_comprehensive(void);
void test_ft_calloc_comprehensive(void);

// str functions
void test_ft_strlen_comprehensive(void);
void test_ft_strlcpy_comprehensive(void);
void test_ft_strlcat_comprehensive(void);
void test_ft_strchr_comprehensive(void);
void test_ft_strrchr_comprehensive(void);
void test_ft_strncmp_comprehensive(void);
void test_ft_strnstr_comprehensive(void);
void test_ft_strdup_comprehensive(void);
void test_ft_substr_comprehensive(void);
void test_ft_strjoin_comprehensive(void);
void test_ft_strtrim_comprehensive(void);
void test_ft_split_comprehensive(void);
void test_ft_strmapi_comprehensive(void);
void test_ft_striteri_comprehensive(void);

// to functions
void test_ft_atoi_comprehensive(void);
void test_ft_atol_comprehensive(void);
void test_ft_itoa_comprehensive(void);
void test_ft_toupper_comprehensive(void);
void test_ft_tolower_comprehensive(void);

// put functions
void test_ft_putchar_fd_comprehensive(void);
void test_ft_putstr_fd_comprehensive(void);
void test_ft_putendl_fd_comprehensive(void);
void test_ft_putnbr_fd_comprehensive(void);

// lst functions
void test_ft_lstnew_comprehensive(void);
void test_ft_lstadd_front_comprehensive(void);
void test_ft_lstadd_back_comprehensive(void);
void test_ft_lstsize_comprehensive(void);
void test_ft_lstlast_comprehensive(void);
void test_ft_lstdelone_comprehensive(void);
void test_ft_lstclear_comprehensive(void);
void test_ft_lstiter_comprehensive(void);
void test_ft_lstmap_comprehensive(void);

// gnl functions
void test_get_next_line_comprehensive(void);
void test_arn_get_next_line_comprehensive(void);

// printf functions
void test_ft_printf_comprehensive(void);
void test_ft_dprintf_comprehensive(void);

// arena functions
void test_ft_arnalloc_comprehensive(void);
void test_ft_arn_strdup_comprehensive(void);
void test_ft_arn_strjoin_comprehensive(void);
void test_ft_arn_substr_comprehensive(void);
void test_ft_arn_split_comprehensive(void);

// Utility functions
void print_test_header(const char *test_name);
void print_test_result(const char *test_case, int passed);
int compare_results(const char *expected, const char *actual);
void cleanup_test_files(void);

#endif
