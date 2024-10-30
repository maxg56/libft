/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tests.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:24:04 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 15:15:06 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"


void	test_ft_isalpha(void)
{
	printf("__________________Testing ft_isalpha__________________\n");
	printf("'A': %d\n", ft_isalpha('A'));
	printf("'z': %d\n", ft_isalpha('z'));
	printf("'1': %d\n", ft_isalpha('1'));
	printf("' ': %d\n", ft_isalpha(' '));
	//printf("' ': %d\n", ft_isalpha(NULL));
}

void	test_ft_isdigit(void)
{
	printf("__________________Testing ft_isdigit__________________\n");
	printf("'0': %d\n", ft_isdigit('0'));
	printf("'9': %d\n", ft_isdigit('9'));
	printf("'a': %d\n", ft_isdigit('a'));
}

void	test_ft_isascii(void)
{
	printf("__________________Testing ft_isascii__________________\n");
	printf("'A': %d\n", ft_isascii('A'));
	printf("255: %d\n", ft_isascii(255));
}

void	test_ft_isprint(void)
{
	printf("__________________Testing ft_isprint__________________\n");
	printf("'A': %d\n", ft_isprint('A'));
	printf("9: %d\n", ft_isprint(9));
	printf("127: %d\n", ft_isprint(127));
}

// Fonction de test pour ft_s
void	test_ft_atoi(void)
{
	printf("__________________Testing ft_atoi__________________\n");
	printf("\"42\": %d , %d \n", ft_atoi("42"), atoi("42"));
	printf("\"-42\": %d , %d \n", ft_atoi("-42"), atoi("-42"));
	printf("\"   42abc\": %d  , %d\n", ft_atoi("   42abc"), atoi("  42abc"));
	printf("\\: %d , %d\n", ft_atoi("adx"), atoi("adx"));
	printf("\\: %d , %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("\\: %d , %d\n", ft_atoi("\n\v\t\r\f21"), atoi("\n\v\f\t\r21"));
	printf("\\: %d , %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
}

// Fonction de test pour ft_bzero
void test_ft_bzero() {
    char str[10] = "Hello";
    ft_bzero(str, 1);
    printf("Testing ft_bzero: %s\n", str); // Devrait imprimer des caractères nuls
}

// Fonction de test pour ft_calloc
void test_ft_calloc() {
    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("Testing ft_calloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]); // Devrait imprimer 0 0 0 0 0
    }
    printf("\n");
    free(arr);
}

// Fonction de test pour ft_memchr
void test_ft_memchr() 
{
    char str[] = "Hello";
    char *result = ft_memchr(str, 'e', 5); // Replace with your custom ft_memchr function
    if (result != NULL)
        printf("Testing ft_memchr: Found 'e' at position %ld\n", result - str);
    else
        printf("Testing ft_memchr: 'e' not found\n");
}

void test_ft_memcmp() {
    char str1[] = "Hello";
    char str2[] = "Helloo";
    printf("Testing ft_memcmp: %d\n", ft_memcmp(str1, str2, 6)); // Should print 0 if they are equal for 6 chars
}

// Fonction de test pour ft_memmove
void test_ft_memmove() {
    char dest[20] = "Hello, World!";
    ft_memmove(dest + 7, dest, 5);
    printf("Testing ft_melstmmove: %s\n", dest); // Devrait imprimer "Hello, Hello!"
}

// Fonction de test pour ft_memset
void test_ft_memset() {
    char str[20] = "Hello";
    ft_memset(str, '*', 3);
    printf("Testing ft_memset: %s\n", str); // Devrait imprimer "***lo"
}

// Fonction de test pour ft_strchr
void test_ft_strchr() {
    char str[] = "HHello";
    char *result = ft_strchr(str, 'e');
    printf("Testing ft_strchr: %s\n", result); // Devrait imprimer "ello"
}

// Fonction de test pour ft_strdup
void test_ft_strdup() {
    char *dup = ft_strdup("Hello");
    printf("Testing ft_strdup: %s\n", dup); // Devrait imprimer "Hello"
    free(dup);
}

// Fonction de test pour ft_strlcat
void test_ft_strlcat() {
    char dest[1] = "";
    char src[] = " World";
	size_t len = ft_strlcat(dest, src, 0);
	printf( "__________________ft_strlcat__________________\n");
    printf("Testing ft_memcpy: %s (length: %zu) \n", dest , len);
}

// Fonction de test pour ft_memcpy
void test_ft_memcpy() {
    char dest[20];
    char src[] = "Hello";
	char dest2[20];
	memcpy(dest2, src, 6);
    ft_memcpy(dest, src, 6);
	printf( "__________________ft_strtrim__________________\n");
    printf("Testing ft_memcpy: %s ,  %s \n", dest , dest2);
	char dest3[20];
	char src2[] = "Hello";
	char dest4[20];
	memcpy(dest3, src2, 2);
    ft_memcpy(dest4, src2, 2);
	printf("Testing ft_memcpy: %s ,  %s \n", dest4 , dest3);
	char dest5[20];
	char src3[] = "";
	char dest6[20];
	memcpy(dest5, src3, 2);
    ft_memcpy(dest6, src3, 2);
	printf("Testing ft_memcpy: |%s| ,  |%s| \n", dest6 , dest5);
}

// Fonction de test pour ft_strnstr
void test_ft_strnstr() {
    char haystack[] = "Hello, World!";
    char *result = ft_strnstr(haystack, "World", 13);
    printf("Testing ft_strnstr: %s\n", result); // Devrait imprimer "World!"
}

// Fonction de test pour ft_toupper
void test_ft_strnstr() {
    printf("Testing ft_toupper:\n");
    printf("'a' -> '%c'\n", ft_toupper('a')); // Devrait imprimer 'A'
}

// Fonction de test pour ft_tolower
void test_ft_tolower(void) {
    printf("Testing ft_tolower:\n");
    printf("'A' -> '%c'\n", ft_tolower('A')); // Devrait imprimer 'a'
}

// Fonction de test pour ft_strrchr
void test_ft_strrchr(void) {
    char str[] = "Hello";
    char *result = ft_strrchr(str, 'l');
	printf("Testing ft_strrchr: %s\n", result); // Devrait imprimer "lo"
	result = ft_strrchr(str, 'H');
	printf("Testing ft_strrchr: %s\n", result); // Devrait imprimer "lo"
	result = ft_strrchr(NULL, ' ');
	printf("Testing ft_strrchr: %s\n", result);
}

// Fonction de test pour ft_strlcpy
void test_ft_strlcpy(void) {
    char dest[20];
    char src[] = "Hello";
    size_t len = ft_strlcpy(dest, src, sizeof(dest));
    printf("Testing ft_strlcpy: %s (length: %zu)\n", dest, len); // Devrait imprimer "Hello"
}


void    test_ft_strtrim(void)
{
    char *p;

	printf( "ft_strtrim\n");
	p = ft_strtrim(" h  -     ", " -");
	printf( "%s : h\n",p);
	free(p);
	p = ft_strtrim("Hello", " ");
	printf( "%s : Hello \n",p);
	free(p);
	p = ft_strtrim("Hello", "l ");
	printf( "%s : Hello\n",p);
	free(p);
	p = ft_strtrim("", "l");
	printf( "%s : \n",p);
	free(p);
	p = ft_strtrim("Hello", "Hello");
	printf( "%s : \n",p);
	free(p);
}
void	test_ft_itoa(void)
{
	printf("Testing ft_itoa:\n");
	printf("\"42\": %s\n", ft_itoa(42));
	printf("\"-42\": %s\n", ft_itoa(-42));
	printf("\"   42abc\": %s\n", ft_itoa(INT_MIN));
}

static char	change_case(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	else
		return (ft_tolower(c));
}

void	test_ft_strmapi(void)
{
	char	*str ;
	char	*result ;


	str = "bonjour";
	result = ft_strmapi(str, change_case);

	printf("__________Testing ft_strmaoi_________\n");
	if (result)
	{
		printf("Résultat : %s\n", result);
		free(result);
	}
}

