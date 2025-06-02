/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arena_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprehensive_tests.h"

void test_ft_arnalloc_comprehensive(void)
{
    print_test_header("ft_arnalloc");
    
    // Test basic allocation
    void *ptr1 = ft_arnalloc(100);
    print_test_result("Basic allocation", ptr1 != NULL);
    
    void *ptr2 = ft_arnalloc(200);
    print_test_result("Second allocation", ptr2 != NULL);
    print_test_result("Different pointers", ptr1 != ptr2);
    
    // Test zero allocation
    void *ptr3 = ft_arnalloc(0);
    print_test_result("Zero size allocation", ptr3 != NULL);
    
    // Test large allocation
    void *ptr4 = ft_arnalloc(70000); // Larger than ARNA_SIZE
    print_test_result("Large allocation", ptr4 != NULL);
    
    // Use the memory to ensure it's valid
    if (ptr1) {
        memset(ptr1, 'A', 100);
        print_test_result("Memory is writable", ((char*)ptr1)[0] == 'A');
    }
    
    ft_arna_free();
    printf("    " TEST_INFO " Arena freed successfully\n");
}

void test_ft_arn_strdup_comprehensive(void)
{
    print_test_header("ft_arn_strdup");
    
    char *original = "Hello World";
    char *copy = ft_arn_strdup(original);
    
    print_test_result("Copy created", copy != NULL);
    print_test_result("Content matches", strcmp(copy, original) == 0);
    print_test_result("Different pointers", copy != original);
    print_test_result("Correct length", strlen(copy) == strlen(original));
    
    // Test empty string
    char *empty_copy = ft_arn_strdup("");
    print_test_result("Empty string copy", empty_copy != NULL && strcmp(empty_copy, "") == 0);
    
    // Test multiple allocations
    char *copy2 = ft_arn_strdup("Test 2");
    char *copy3 = ft_arn_strdup("Test 3");
    
    print_test_result("Multiple allocations work", 
        copy2 != NULL && copy3 != NULL && 
        strcmp(copy2, "Test 2") == 0 && 
        strcmp(copy3, "Test 3") == 0);
    
    ft_arna_free();
}

void test_ft_arn_strjoin_comprehensive(void)
{
    print_test_header("ft_arn_strjoin");
    
    char *s1 = "Hello ";
    char *s2 = "World";
    char *joined = ft_arn_strjoin(s1, s2);
    
    print_test_result("Join two strings", joined != NULL && strcmp(joined, "Hello World") == 0);
    print_test_result("Correct length", strlen(joined) == strlen(s1) + strlen(s2));
    
    // Test with empty strings
    char *joined_empty1 = ft_arn_strjoin("", "World");
    print_test_result("Join with empty first", joined_empty1 != NULL && strcmp(joined_empty1, "World") == 0);
    
    char *joined_empty2 = ft_arn_strjoin("Hello", "");
    print_test_result("Join with empty second", joined_empty2 != NULL && strcmp(joined_empty2, "Hello") == 0);
    
    char *joined_both_empty = ft_arn_strjoin("", "");
    print_test_result("Join two empty strings", joined_both_empty != NULL && strcmp(joined_both_empty, "") == 0);
    
    ft_arna_free();
}

void test_ft_arn_substr_comprehensive(void)
{
    print_test_header("ft_arn_substr");
    
    char *str = "Hello World";
    char *sub;
    
    // Normal cases
    sub = ft_arn_substr(str, 0, 5);
    print_test_result("Substring from start", sub != NULL && strcmp(sub, "Hello") == 0);
    
    sub = ft_arn_substr(str, 6, 5);
    print_test_result("Substring from middle", sub != NULL && strcmp(sub, "World") == 0);
    
    sub = ft_arn_substr(str, 0, 20);
    print_test_result("Length longer than string", sub != NULL && strcmp(sub, str) == 0);
    
    // Edge cases
    sub = ft_arn_substr(str, 15, 5);
    print_test_result("Start beyond string", sub != NULL && strcmp(sub, "") == 0);
    
    sub = ft_arn_substr(str, 5, 0);
    print_test_result("Zero length", sub != NULL && strcmp(sub, "") == 0);
    
    ft_arna_free();
}

void test_ft_arn_split_comprehensive(void)
{
    print_test_header("ft_arn_split");
    
    char **result = ft_arn_split("Hello,World,Test", ',');
    
    print_test_result("Split creates array", result != NULL);
    print_test_result("Split count correct", result[0] && result[1] && result[2] && !result[3]);
    print_test_result("First element correct", result && strcmp(result[0], "Hello") == 0);
    print_test_result("Second element correct", result && strcmp(result[1], "World") == 0);
    print_test_result("Third element correct", result && strcmp(result[2], "Test") == 0);
    
    // Test edge cases
    char **empty_result = ft_arn_split("", ',');
    print_test_result("Split empty string", empty_result != NULL && empty_result[0] == NULL);
    
    char **no_delim = ft_arn_split("Hello", ',');
    print_test_result("No delimiter", no_delim != NULL && strcmp(no_delim[0], "Hello") == 0 && no_delim[1] == NULL);
    
    char **only_delim = ft_arn_split(",,,", ',');
    print_test_result("Only delimiters", only_delim != NULL && only_delim[0] == NULL);
    
    ft_arna_free();
}

void test_ft_arn_itoa_comprehensive(void)
{
    print_test_header("ft_arn_itoa");
    
    char *result;
    
    result = ft_arn_itoa(42);
    print_test_result("Positive number", result != NULL && strcmp(result, "42") == 0);
    
    result = ft_arn_itoa(-42);
    print_test_result("Negative number", result != NULL && strcmp(result, "-42") == 0);
    
    result = ft_arn_itoa(0);
    print_test_result("Zero", result != NULL && strcmp(result, "0") == 0);
    
    result = ft_arn_itoa(-2147483648);
    print_test_result("INT_MIN", result != NULL && strcmp(result, "-2147483648") == 0);
    
    result = ft_arn_itoa(2147483647);
    print_test_result("INT_MAX", result != NULL && strcmp(result, "2147483647") == 0);
    
    ft_arna_free();
}

void test_arn_get_next_line_comprehensive(void)
{
    print_test_header("arn_get_next_line");
    
    // Create a test file
    int fd = open("test_gnl_arena.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        print_test_result("Create test file", 0);
        return;
    }
    
    write(fd, "Line 1\nLine 2\nLine 3", 20);
    close(fd);
    
    // Test reading
    fd = open("test_gnl_arena.txt", O_RDONLY);
    print_test_result("Open test file", fd >= 0);
    
    if (fd >= 0) {
        char *line1 = arn_get_next_line(fd);
        print_test_result("Read first line", line1 != NULL && strcmp(line1, "Line 1\n") == 0);
        
        char *line2 = arn_get_next_line(fd);
        print_test_result("Read second line", line2 != NULL && strcmp(line2, "Line 2\n") == 0);
        
        char *line3 = arn_get_next_line(fd);
        print_test_result("Read third line", line3 != NULL && strcmp(line3, "Line 3") == 0);
        
        char *line4 = arn_get_next_line(fd);
        print_test_result("Read EOF", line4 == NULL);
        
        close(fd);
    }
    
    // Test invalid fd
    char *invalid_line = arn_get_next_line(-1);
    print_test_result("Invalid fd", invalid_line == NULL);
    
    ft_arna_free();
    unlink("test_gnl_arena.txt");
}

void run_arena_tests(void)
{
    printf("\n" TEST_INFO " Running Arena Allocator Tests\n");
    printf("==========================================\n");
    
    test_ft_arnalloc_comprehensive();
    test_ft_arn_strdup_comprehensive();
    test_ft_arn_strjoin_comprehensive();
    test_ft_arn_substr_comprehensive();
    test_ft_arn_split_comprehensive();
    test_ft_arn_itoa_comprehensive();
    test_arn_get_next_line_comprehensive();
    
    printf("\n" TEST_INFO " Arena Allocator Tests Complete\n\n");
}
