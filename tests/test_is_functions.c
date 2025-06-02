/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comprehensive_tests.h"
#include <ctype.h>

void test_ft_isalpha_comprehensive(void)
{
    print_test_header("ft_isalpha");
    
    // Test alphabetic characters
    print_test_result("'A' should be alpha", !!ft_isalpha('A') == !!isalpha('A'));
    print_test_result("'z' should be alpha", !!ft_isalpha('z') == !!isalpha('z'));
    print_test_result("'M' should be alpha", !!ft_isalpha('M') == !!isalpha('M'));
    
    // Test non-alphabetic characters
    print_test_result("'1' should not be alpha", !!ft_isalpha('1') == !!isalpha('1'));
    print_test_result("' ' should not be alpha", !!ft_isalpha(' ') == !!isalpha(' '));
    print_test_result("'@' should not be alpha", !!ft_isalpha('@') == !!isalpha('@'));
    print_test_result("'0' should not be alpha", !!ft_isalpha('0') == !!isalpha('0'));
    
    // Edge cases
    print_test_result("EOF should not be alpha", !!ft_isalpha(-1) == !!isalpha(-1));
    print_test_result("Extended ASCII", !!ft_isalpha(200) == !!isalpha(200));
}

void test_ft_isdigit_comprehensive(void)
{
    print_test_header("ft_isdigit");
    
    // Test digit characters
    print_test_result("'0' should be digit", !!ft_isdigit('0') == !!isdigit('0'));
    print_test_result("'9' should be digit", !!ft_isdigit('9') == !!isdigit('9'));
    print_test_result("'5' should be digit", !!ft_isdigit('5') == !!isdigit('5'));
    
    // Test non-digit characters
    print_test_result("'a' should not be digit", !!ft_isdigit('a') == !!isdigit('a'));
    print_test_result("'A' should not be digit", !!ft_isdigit('A') == !!isdigit('A'));
    print_test_result("' ' should not be digit", !!ft_isdigit(' ') == !!isdigit(' '));
    print_test_result("'/' should not be digit", !!ft_isdigit('/') == !!isdigit('/'));
    print_test_result("':' should not be digit", !!ft_isdigit(':') == !!isdigit(':'));
    
    // Edge cases
    print_test_result("EOF should not be digit", !!ft_isdigit(-1) == !!isdigit(-1));
}

void test_ft_isalnum_comprehensive(void)
{
    print_test_header("ft_isalnum");
    
    // Test alphanumeric characters
    print_test_result("'A' should be alnum", !!ft_isalnum('A') == !!isalnum('A'));
    print_test_result("'z' should be alnum", !!ft_isalnum('z') == !!isalnum('z'));
    print_test_result("'0' should be alnum", !!ft_isalnum('0') == !!isalnum('0'));
    print_test_result("'9' should be alnum", !!ft_isalnum('9') == !!isalnum('9'));
    
    // Test non-alphanumeric characters
    print_test_result("' ' should not be alnum", !!ft_isalnum(' ') == !!isalnum(' '));
    print_test_result("'@' should not be alnum", !!ft_isalnum('@') == !!isalnum('@'));
    print_test_result("'!' should not be alnum", !!ft_isalnum('!') == !!isalnum('!'));
    
    // Edge cases
    print_test_result("EOF should not be alnum", !!ft_isalnum(-1) == !!isalnum(-1));
}

void test_ft_isascii_comprehensive(void)
{
    print_test_header("ft_isascii");
    
    // Test ASCII characters
    print_test_result("0 should be ASCII", !!ft_isascii(0) == !!isascii(0));
    print_test_result("127 should be ASCII", !!ft_isascii(127) == !!isascii(127));
    print_test_result("'A' should be ASCII", !!ft_isascii('A') == !!isascii('A'));
    print_test_result("32 should be ASCII", !!ft_isascii(32) == !!isascii(32));
    
    // Test non-ASCII characters
    print_test_result("128 should not be ASCII", !!ft_isascii(128) == !!isascii(128));
    print_test_result("255 should not be ASCII", !!ft_isascii(255) == !!isascii(255));
    print_test_result("-1 should not be ASCII", !!ft_isascii(-1) == !!isascii(-1));
    print_test_result("1000 should not be ASCII", !!ft_isascii(1000) == !!isascii(1000));
}

void test_ft_isprint_comprehensive(void)
{
    print_test_header("ft_isprint");
    
    // Test printable characters
    print_test_result("' ' should be printable", !!ft_isprint(' ') == !!isprint(' '));
    print_test_result("'A' should be printable", !!ft_isprint('A') == !!isprint('A'));
    print_test_result("'~' should be printable", !!ft_isprint('~') == !!isprint('~'));
    print_test_result("'0' should be printable", !!ft_isprint('0') == !!isprint('0'));
    
    // Test non-printable characters
    print_test_result("0 should not be printable", !!ft_isprint(0) == !!isprint(0));
    print_test_result("\\t should not be printable", !!ft_isprint('\t') == !!isprint('\t'));
    print_test_result("\\n should not be printable", !!ft_isprint('\n') == !!isprint('\n'));
    print_test_result("127 should not be printable", !!ft_isprint(127) == !!isprint(127));
    
    // Edge cases
    print_test_result("31 should not be printable", !!ft_isprint(31) == !!isprint(31));
    print_test_result("126 should be printable", !!ft_isprint(126) == !!isprint(126));
}

void run_is_tests(void)
{
    printf("\n" TEST_INFO " Running Character Classification Tests\n");
    printf("==========================================\n");
    
    test_ft_isalpha_comprehensive();
    test_ft_isdigit_comprehensive();
    test_ft_isalnum_comprehensive();
    test_ft_isascii_comprehensive();
    test_ft_isprint_comprehensive();
    
    printf("\n" TEST_INFO " Character Classification Tests Complete\n\n");
}
