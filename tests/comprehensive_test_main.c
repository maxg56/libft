/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprehensive_test_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprehensive_tests.h"
#include <ctype.h>

// Forward declarations for functions in test_utils.c
void print_final_results(void);
void cleanup_test_files(void);

// Quick tests for remaining functions
void quick_test_remaining_functions(void)
{
    printf("\n" TEST_INFO " Running Quick Tests for Remaining Functions\n");
    printf("==========================================\n");
    
    // Test ft_atoi
    print_test_header("ft_atoi");
    print_test_result("Simple positive", ft_atoi("42") == 42);
    print_test_result("Simple negative", ft_atoi("-42") == -42);
    print_test_result("With whitespace", ft_atoi("   42") == 42);
    print_test_result("With trailing chars", ft_atoi("42abc") == 42);
    
    // Test ft_atol
    print_test_header("ft_atol");
    print_test_result("Long positive", ft_atol("1234567890") == 1234567890L);
    print_test_result("Long negative", ft_atol("-1234567890") == -1234567890L);
    
    // Test ft_itoa
    print_test_header("ft_itoa");
    char *itoa_result = ft_itoa(42);
    print_test_result("Positive number", strcmp(itoa_result, "42") == 0);
    free(itoa_result);
    
    itoa_result = ft_itoa(-42);
    print_test_result("Negative number", strcmp(itoa_result, "-42") == 0);
    free(itoa_result);
    
    // Test ft_toupper/ft_tolower
    print_test_header("ft_toupper/ft_tolower");
    print_test_result("Toupper", ft_toupper('a') == toupper('a'));
    print_test_result("Tolower", ft_tolower('A') == tolower('A'));
    
    // Test put functions (basic)
    print_test_header("ft_put functions");
    printf("    " TEST_INFO " Testing put functions (check output manually):\n");
    printf("    Testing ft_putchar_fd: ");
    ft_putchar_fd('X', 1);
    printf(" <- Should show 'X'\n");
    
    printf("    Testing ft_putstr_fd: ");
    ft_putstr_fd("Hello", 1);
    printf(" <- Should show 'Hello'\n");
    
    printf("    Testing ft_putendl_fd: ");
    ft_putendl_fd("World", 1);
    printf("    ^ Should show 'World' with newline\n");
    
    printf("    Testing ft_putnbr_fd: ");
    ft_putnbr_fd(42, 1);
    printf(" <- Should show '42'\n");
    
    print_test_result("Put functions executed", 1);
    
    // Test basic list functions
    print_test_header("ft_lst functions (basic)");
    t_list *node = ft_lstnew("test");
    print_test_result("ft_lstnew", node != NULL && strcmp((char*)node->content, "test") == 0);
    
    print_test_result("ft_lstsize single", ft_lstsize(node) == 1);
    
    t_list *node2 = ft_lstnew("test2");
    ft_lstadd_back(&node, node2);
    print_test_result("ft_lstadd_back", ft_lstsize(node) == 2);
    
    t_list *last = ft_lstlast(node);
    print_test_result("ft_lstlast", last == node2);
    
    ft_lstclear(&node, NULL);  // Don't free content as it's static
    print_test_result("ft_lstclear", node == NULL);
    
    // Test printf functions
    print_test_header("ft_printf (basic)");
    printf("    " TEST_INFO " Testing printf functions:\n");
    printf("    ft_printf result: ");
    int ret1 = ft_printf("Hello %s, number: %d\n", "World", 42);
    printf("    Return value: %d\n", ret1);
    print_test_result("ft_printf executed", ret1 > 0);
    
    // Test get_next_line
    print_test_header("get_next_line");
    
    // Create test file
    int fd = open("test_gnl_quick.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd >= 0) {
        write(fd, "Line 1\nLine 2\n", 14);
        close(fd);
        
        fd = open("test_gnl_quick.txt", O_RDONLY);
        if (fd >= 0) {
            char *line = get_next_line(fd);
            print_test_result("get_next_line first line", line != NULL && strncmp(line, "Line 1", 6) == 0);
            free(line);
            
            line = get_next_line(fd);
            print_test_result("get_next_line second line", line != NULL && strncmp(line, "Line 2", 6) == 0);
            free(line);
            
            close(fd);
        }
        unlink("test_gnl_quick.txt");
    }
    
    printf("\n" TEST_INFO " Quick Tests Complete\n\n");
}

int main(int argc, char **argv)
{
    printf("🧪 LIBFT COMPREHENSIVE TEST SUITE\n");
    printf("==================================\n");
    printf("Testing all functions in your libft library...\n");
    
    // Check if specific test category is requested
    if (argc > 1) {
        if (strcmp(argv[1], "is") == 0) {
            run_is_tests();
        } else if (strcmp(argv[1], "mem") == 0) {
            run_mem_tests();
        } else if (strcmp(argv[1], "str") == 0) {
            run_str_tests();
        } else if (strcmp(argv[1], "arena") == 0) {
            run_arena_tests();
        } else if (strcmp(argv[1], "quick") == 0) {
            quick_test_remaining_functions();
        } else {
            printf("Available test categories: is, mem, str, arena, quick\n");
            printf("Run without arguments for all tests\n");
            return 1;
        }
    } else {
        // Run all tests
        run_is_tests();
        run_mem_tests();
        run_str_tests();
        run_arena_tests();
        quick_test_remaining_functions();
    }
    
    cleanup_test_files();
    print_final_results();
    
    return 0;
}
