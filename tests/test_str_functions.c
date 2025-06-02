/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprehensive_tests.h"

void test_ft_strlen_comprehensive(void)
{
    print_test_header("ft_strlen");
    
    print_test_result("Empty string", ft_strlen("") == strlen(""));
    print_test_result("Simple string", ft_strlen("Hello") == strlen("Hello"));
    print_test_result("String with spaces", ft_strlen("Hello World") == strlen("Hello World"));
    print_test_result("Long string", ft_strlen("This is a very long string for testing purposes") == strlen("This is a very long string for testing purposes"));
    print_test_result("String with special chars", ft_strlen("Hello\tWorld\n") == strlen("Hello\tWorld\n"));
}

void test_ft_strchr_comprehensive(void)
{
    print_test_header("ft_strchr");
    
    char *str = "Hello World";
    
    print_test_result("Find first char", ft_strchr(str, 'H') == strchr(str, 'H'));
    print_test_result("Find middle char", ft_strchr(str, 'o') == strchr(str, 'o'));
    print_test_result("Find last char", ft_strchr(str, 'd') == strchr(str, 'd'));
    print_test_result("Find null terminator", ft_strchr(str, '\0') == strchr(str, '\0'));
    print_test_result("Find non-existent char", ft_strchr(str, 'x') == strchr(str, 'x'));
    print_test_result("Find space", ft_strchr(str, ' ') == strchr(str, ' '));
    
    // Edge cases
    print_test_result("Empty string search", ft_strchr("", 'a') == strchr("", 'a'));
    print_test_result("Empty string null", ft_strchr("", '\0') == strchr("", '\0'));
}

void test_ft_strrchr_comprehensive(void)
{
    print_test_header("ft_strrchr");
    
    char *str = "Hello World Hello";
    
    print_test_result("Find last occurrence", ft_strrchr(str, 'H') == strrchr(str, 'H'));
    print_test_result("Find last 'o'", ft_strrchr(str, 'o') == strrchr(str, 'o'));
    print_test_result("Find last 'l'", ft_strrchr(str, 'l') == strrchr(str, 'l'));
    print_test_result("Find null terminator", ft_strrchr(str, '\0') == strrchr(str, '\0'));
    print_test_result("Find non-existent char", ft_strrchr(str, 'x') == strrchr(str, 'x'));
    
    // Edge cases
    print_test_result("Empty string search", ft_strrchr("", 'a') == strrchr("", 'a'));
    print_test_result("Single char string", ft_strrchr("a", 'a') == strrchr("a", 'a'));
}

void test_ft_strncmp_comprehensive(void)
{
    print_test_header("ft_strncmp");
    
    print_test_result("Equal strings", ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5));
    print_test_result("Different strings", (ft_strncmp("Hello", "World", 5) > 0) == (strncmp("Hello", "World", 5) > 0));
    print_test_result("Partial comparison", ft_strncmp("Hello", "Help", 3) == strncmp("Hello", "Help", 3));
    print_test_result("Zero length", ft_strncmp("Hello", "World", 0) == strncmp("Hello", "World", 0));
    print_test_result("Empty strings", ft_strncmp("", "", 1) == strncmp("", "", 1));
    print_test_result("One empty string", (ft_strncmp("Hello", "", 5) > 0) == (strncmp("Hello", "", 5) > 0));
    
    // Edge cases with null bytes
    char str1[] = "test\0hidden";
    char str2[] = "test\0different";
    print_test_result("Strings with null bytes", ft_strncmp(str1, str2, 10) == strncmp(str1, str2, 10));
}

void test_ft_strnstr_comprehensive(void)
{
    print_test_header("ft_strnstr");
    
    char *haystack = "Hello World, Hello Universe";
    
    // Manual verification since strnstr is not standard on Linux
    print_test_result("Find at beginning", ft_strnstr(haystack, "Hello", 10) == haystack);
    print_test_result("Find in middle", ft_strnstr(haystack, "World", 15) == haystack + 6);
    print_test_result("Find empty needle", ft_strnstr(haystack, "", 10) == haystack);
    print_test_result("Not found in range", ft_strnstr(haystack, "Universe", 10) == NULL);
    print_test_result("Found in range", ft_strnstr(haystack, "Universe", 30) == haystack + 19);
    print_test_result("Needle longer than haystack", ft_strnstr("Hi", "Hello", 10) == NULL);
    
    // Edge cases
    print_test_result("Zero length", ft_strnstr(haystack, "Hello", 0) == NULL);
    print_test_result("Empty haystack", ft_strnstr("", "test", 5) == NULL);
    print_test_result("Both empty", ft_strnstr("", "", 5) != NULL);
}

void test_ft_strdup_comprehensive(void)
{
    print_test_header("ft_strdup");
    
    char *original = "Hello World";
    char *ft_copy = ft_strdup(original);
    char *std_copy = strdup(original);
    
    print_test_result("Copy content matches", strcmp(ft_copy, std_copy) == 0);
    print_test_result("Copy is different pointer", ft_copy != original);
    print_test_result("Length matches", strlen(ft_copy) == strlen(std_copy));
    
    free(ft_copy);
    free(std_copy);
    
    // Test empty string
    char *ft_empty = ft_strdup("");
    char *std_empty = strdup("");
    print_test_result("Empty string copy", strcmp(ft_empty, std_empty) == 0);
    
    free(ft_empty);
    free(std_empty);
}

void test_ft_substr_comprehensive(void)
{
    print_test_header("ft_substr");
    
    char *str = "Hello World";
    char *sub;
    
    // Normal cases
    sub = ft_substr(str, 0, 5);
    print_test_result("Substring from start", strcmp(sub, "Hello") == 0);
    free(sub);
    
    sub = ft_substr(str, 6, 5);
    print_test_result("Substring from middle", strcmp(sub, "World") == 0);
    free(sub);
    
    sub = ft_substr(str, 0, 20);
    print_test_result("Length longer than string", strcmp(sub, str) == 0);
    free(sub);
    
    // Edge cases
    sub = ft_substr(str, 15, 5);
    print_test_result("Start beyond string", strcmp(sub, "") == 0);
    free(sub);
    
    sub = ft_substr(str, 5, 0);
    print_test_result("Zero length", strcmp(sub, "") == 0);
    free(sub);
}

void test_ft_strjoin_comprehensive(void)
{
    print_test_header("ft_strjoin");
    
    char *s1 = "Hello ";
    char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);
    
    print_test_result("Join two strings", strcmp(joined, "Hello World") == 0);
    print_test_result("Correct length", strlen(joined) == strlen(s1) + strlen(s2));
    free(joined);
    
    // Edge cases
    joined = ft_strjoin("", "World");
    print_test_result("Join with empty first", strcmp(joined, "World") == 0);
    free(joined);
    
    joined = ft_strjoin("Hello", "");
    print_test_result("Join with empty second", strcmp(joined, "Hello") == 0);
    free(joined);
    
    joined = ft_strjoin("", "");
    print_test_result("Join two empty strings", strcmp(joined, "") == 0);
    free(joined);
}

void test_ft_strtrim_comprehensive(void)
{
    print_test_header("ft_strtrim");
    
    char *str = "   Hello World   ";
    char *trimmed = ft_strtrim(str, " ");
    
    print_test_result("Trim spaces", strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    
    str = "***Hello World***";
    trimmed = ft_strtrim(str, "*");
    print_test_result("Trim asterisks", strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    
    str = "abcHello Worldcba";
    trimmed = ft_strtrim(str, "abc");
    print_test_result("Trim multiple chars", strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    
    // Edge cases
    trimmed = ft_strtrim("", " ");
    print_test_result("Trim empty string", strcmp(trimmed, "") == 0);
    free(trimmed);
    
    trimmed = ft_strtrim("   ", " ");
    print_test_result("Trim all spaces", strcmp(trimmed, "") == 0);
    free(trimmed);
}

void test_ft_split_comprehensive(void)
{
    print_test_header("ft_split");
    
    char **result = ft_split("Hello,World,Test", ',');
    
    print_test_result("Split count", result[0] && result[1] && result[2] && !result[3]);
    print_test_result("First element", strcmp(result[0], "Hello") == 0);
    print_test_result("Second element", strcmp(result[1], "World") == 0);
    print_test_result("Third element", strcmp(result[2], "Test") == 0);
    
    ft_free_tab(result);
    
    // Edge cases
    result = ft_split("", ',');
    print_test_result("Split empty string", result[0] == NULL);
    ft_free_tab(result);
    
    result = ft_split("Hello", ',');
    print_test_result("No delimiter", strcmp(result[0], "Hello") == 0 && result[1] == NULL);
    ft_free_tab(result);
    
    result = ft_split(",,,", ',');
    print_test_result("Only delimiters", result[0] == NULL);
    ft_free_tab(result);
}

static char test_toupper_char(unsigned int i, char c)
{
    (void)i;
    return ft_toupper(c);
}

void test_ft_strmapi_comprehensive(void)
{
    print_test_header("ft_strmapi");
    
    char *str = "hello";
    char *result = ft_strmapi(str, test_toupper_char);
    
    print_test_result("Map to uppercase", strcmp(result, "HELLO") == 0);
    free(result);
    
    // Edge cases
    result = ft_strmapi("", test_toupper_char);
    print_test_result("Map empty string", strcmp(result, "") == 0);
    free(result);
}

static void test_striteri_helper(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);
}

void test_ft_striteri_comprehensive(void)
{
    print_test_header("ft_striteri");
    
    char str[] = "hello";
    ft_striteri(str, test_striteri_helper);
    
    print_test_result("Iterate and modify", strcmp(str, "HELLO") == 0);
    
    // Edge case
    char empty[] = "";
    ft_striteri(empty, test_striteri_helper);
    print_test_result("Iterate empty string", strcmp(empty, "") == 0);
}

void test_ft_strlcpy_comprehensive(void)
{
    print_test_header("ft_strlcpy");
    
    char dest[20];
    char std_dest[20];
    
    size_t ft_ret = ft_strlcpy(dest, "Hello World", 6);
    size_t std_ret = strlcpy(std_dest, "Hello World", 6);
    
    print_test_result("Copy with truncation", strcmp(dest, std_dest) == 0);
    print_test_result("Return value matches", ft_ret == std_ret);
    
    // Edge cases
    ft_ret = ft_strlcpy(dest, "Hi", 20);
    std_ret = strlcpy(std_dest, "Hi", 20);
    
    print_test_result("Copy without truncation", strcmp(dest, std_dest) == 0);
    print_test_result("Return value no truncation", ft_ret == std_ret);
}

void test_ft_strlcat_comprehensive(void)
{
    print_test_header("ft_strlcat");
    
    char dest[20] = "Hello ";
    char std_dest[20] = "Hello ";
    
    size_t ft_ret = ft_strlcat(dest, "World", 20);
    size_t std_ret = strlcat(std_dest, "World", 20);
    
    print_test_result("Concatenate strings", strcmp(dest, std_dest) == 0);
    print_test_result("Return value matches", ft_ret == std_ret);
    
    // Test with truncation
    strcpy(dest, "Hello ");
    strcpy(std_dest, "Hello ");
    
    ft_ret = ft_strlcat(dest, "World", 10);
    std_ret = strlcat(std_dest, "World", 10);
    
    print_test_result("Concatenate with truncation", strcmp(dest, std_dest) == 0);
    print_test_result("Return value with truncation", ft_ret == std_ret);
}

void run_str_tests(void)
{
    printf("\n" TEST_INFO " Running String Manipulation Tests\n");
    printf("==========================================\n");
    
    test_ft_strlen_comprehensive();
    test_ft_strchr_comprehensive();
    test_ft_strrchr_comprehensive();
    test_ft_strncmp_comprehensive();
    test_ft_strnstr_comprehensive();
    test_ft_strdup_comprehensive();
    test_ft_substr_comprehensive();
    test_ft_strjoin_comprehensive();
    test_ft_strtrim_comprehensive();
    test_ft_split_comprehensive();
    test_ft_strmapi_comprehensive();
    test_ft_striteri_comprehensive();
    test_ft_strlcpy_comprehensive();
    test_ft_strlcat_comprehensive();
    
    printf("\n" TEST_INFO " String Manipulation Tests Complete\n\n");
}
