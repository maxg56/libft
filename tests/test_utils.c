/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprehensive_tests.h"

static int test_count = 0;
static int pass_count = 0;

void print_test_header(const char *test_name)
{
    printf("\n📋 Testing %s:\n", test_name);
    printf("--------------------------------------------------\n");
}

void print_test_result(const char *test_case, int passed)
{
    test_count++;
    if (passed) {
        pass_count++;
        printf("  %s %s\n", TEST_PASS, test_case);
    } else {
        printf("  %s %s\n", TEST_FAIL, test_case);
    }
}

int compare_results(const char *expected, const char *actual)
{
    if (expected == NULL && actual == NULL)
        return 1;
    if (expected == NULL || actual == NULL)
        return 0;
    return strcmp(expected, actual) == 0;
}

void cleanup_test_files(void)
{
    unlink("test_file.txt");
    unlink("test_gnl.txt");
    unlink("test_gnl_arena.txt");
    unlink("test_printf_output.txt");
}

void print_final_results(void)
{
    printf("\n==================================================\n");
    printf("🏁 FINAL RESULTS\n");
    printf("==================================================\n");
    
    if (pass_count == test_count) {
        printf(TEST_PASS " ALL TESTS PASSED! (%d/%d)\n", pass_count, test_count);
        printf("🎉 Congratulations! Your libft implementation is working perfectly!\n");
    } else {
        printf(TEST_WARN " Tests passed: %d/%d (%.1f%%)\n", 
               pass_count, test_count, 
               (float)pass_count / test_count * 100);
        printf("🔧 %d test(s) need attention.\n", test_count - pass_count);
    }
    
    printf("==================================================\n");
}

// Additional test functions for memory and conversion functions

void test_ft_memset_comprehensive(void)
{
    print_test_header("ft_memset");
    
    char buffer1[10];
    char buffer2[10];
    
    ft_memset(buffer1, 'A', 5);
    memset(buffer2, 'A', 5);
    
    print_test_result("Memset comparison", memcmp(buffer1, buffer2, 5) == 0);
    
    ft_memset(buffer1, 0, 10);
    memset(buffer2, 0, 10);
    
    print_test_result("Memset with zero", memcmp(buffer1, buffer2, 10) == 0);
}

void test_ft_bzero_comprehensive(void)
{
    print_test_header("ft_bzero");
    
    char buffer1[10] = "Hello";
    char buffer2[10] = "Hello";
    
    ft_bzero(buffer1, 3);
    bzero(buffer2, 3);
    
    print_test_result("Bzero comparison", memcmp(buffer1, buffer2, 10) == 0);
}

void test_ft_memcpy_comprehensive(void)
{
    print_test_header("ft_memcpy");
    
    char src[] = "Hello World";
    char dest1[20] = {0};
    char dest2[20] = {0};
    
    ft_memcpy(dest1, src, 12);  // Copy including null terminator
    memcpy(dest2, src, 12);
    
    print_test_result("Memcpy comparison", memcmp(dest1, dest2, 12) == 0);
    print_test_result("Content correct", strcmp(dest1, "Hello World") == 0);
}

void test_ft_memmove_comprehensive(void)
{
    print_test_header("ft_memmove");
    
    char buffer1[] = "Hello World";
    char buffer2[] = "Hello World";
    
    ft_memmove(buffer1 + 2, buffer1, 5);
    memmove(buffer2 + 2, buffer2, 5);
    
    print_test_result("Memmove overlap", memcmp(buffer1, buffer2, 11) == 0);
}

void test_ft_memchr_comprehensive(void)
{
    print_test_header("ft_memchr");
    
    char data[] = "Hello\0World";
    
    print_test_result("Find existing char", ft_memchr(data, 'e', 5) == memchr(data, 'e', 5));
    print_test_result("Find null byte", ft_memchr(data, '\0', 10) == memchr(data, '\0', 10));
    print_test_result("Not found", ft_memchr(data, 'x', 5) == memchr(data, 'x', 5));
}

void test_ft_memcmp_comprehensive(void)
{
    print_test_header("ft_memcmp");
    
    print_test_result("Equal memory", ft_memcmp("Hello", "Hello", 5) == memcmp("Hello", "Hello", 5));
    print_test_result("Different memory", (ft_memcmp("Hello", "World", 5) > 0) == (memcmp("Hello", "World", 5) > 0));
    print_test_result("Partial comparison", ft_memcmp("Hello", "Help", 3) == memcmp("Hello", "Help", 3));
}

void test_ft_calloc_comprehensive(void)
{
    print_test_header("ft_calloc");
    
    int *arr = (int *)ft_calloc(5, sizeof(int));
    print_test_result("Allocation successful", arr != NULL);
    
    if (arr) {
        int all_zero = 1;
        for (int i = 0; i < 5; i++) {
            if (arr[i] != 0) {
                all_zero = 0;
                break;
            }
        }
        print_test_result("Memory initialized to zero", all_zero);
        free(arr);
    }
    
    // Test edge cases
    void *ptr = ft_calloc(0, 5);
    print_test_result("Zero count allocation", ptr != NULL);
    if (ptr) free(ptr);
    
    ptr = ft_calloc(5, 0);
    print_test_result("Zero size allocation", ptr != NULL);
    if (ptr) free(ptr);
}

void run_mem_tests(void)
{
    printf("\n" TEST_INFO " Running Memory Management Tests\n");
    printf("==========================================\n");
    
    test_ft_memset_comprehensive();
    test_ft_bzero_comprehensive();
    test_ft_memcpy_comprehensive();
    test_ft_memmove_comprehensive();
    test_ft_memchr_comprehensive();
    test_ft_memcmp_comprehensive();
    test_ft_calloc_comprehensive();
    
    printf("\n" TEST_INFO " Memory Management Tests Complete\n\n");
}
