/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:02:30 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:13:20 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

typedef struct {
    int     index;
    char    *desc;
    char    dest[100];
    char    src[100];
    size_t  size;
} TestCase;

TestCase strncmp_tests[] = {
    {0, "equal strings", "Hello", "Hello", 5},
    {1, "prefix match", "HelloWorld", "HelloThere", 5},
    {2, "partial match", "Hello", "Helium", 4},
    {3, "no match", "Apple", "Orange", 5},
    {4, "empty source string", "Hello", "", 5},
    {5, "empty destination string", "", "Hello", 5},
    {6, "zero bytes", "Hello", "World", 0},
    {7, "non-ASCII characters", "日本語", "日本", 3},
    {8, "special characters", "@#$%^", "@#$%", 4},
    {9, "case sensitivity", "Hello", "hello", 5},
    {10, "source shorter than dest", "Hi", "Hello", 2},
    {11, "dest shorter than source", "Hello", "Hi", 2},
    {12, "source with spaces", "Hello World", "Hello ", 6},
    {13, "dest with leading spaces", "Hello", " Hello", 6},
    {14, "source with trailing spaces", "Hello ", "Hello", 6},
    {15, "dest with tabs", "Hello\t", "Hello", 6},
    {16, "source with newline", "Hello\n", "Hello", 6},
    {17, "dest with carriage return", "Hello\r", "Hello", 6},
    {18, "source with mixed chars", "Hello123", "Hello124", 8},
    {19, "both empty strings", "", "", 5},
    {20, "one empty string, larger n", "Hello", "", 10},
    {21, "both strings with spaces", "Hello World", "Hello World", 11},
    {22, "long source string", "A very long string that exceeds usual length", "A very long string that exceeds usual length", 50},
    {23, "long dest string", "Hello", "A very long string that exceeds usual length", 5},
    {24, "source with non-printable characters", "Hello\x01\x02", "Hello", 7},
    {25, "destination with non-printable characters", "Hello", "Hello\x01\x02", 7},
    {26, "source and dest with non-printable characters", "Hello\x01\x02", "Hello\x01\x02", 7},
    {27, "null characters in between", "Hel\0lo", "Hel\0lo", 6},
    {28, "null character in source only", "Hel\0lo", "Hello", 6},
    {29, "null character in destination only", "Hello", "Hel\0lo", 6},
    {30, "source longer than limit", "HelloWorld", "Hello", 10},
    {31, "destination longer than limit", "Hello", "HelloWorld", 10},
    {32, "different length strings, limit exceeds length", "Hello", "Hell", 10},
    {33, "same length strings, limit exceeds length", "Hello", "World", 10},
    {34, "different strings with same prefix", "HelloThere", "HelloWorld", 5},
    {35, "strings with repeating patterns", "abababab", "abababab", 8},
    {36, "strings with mixed alphanumeric", "abc123", "abc123", 6},
    {37, "one string empty", "", "HelloWorld", 0},
    {38, "source with newlines and spaces", "Hello\n World", "Hello\n World", 12},
    {39, "destination with newlines and spaces", "Hello\n World", "HelloWorld", 12},
    {40, "source with tabs and spaces", "Hello\t World", "Hello\t World", 12},
    {41, "destination with tabs and spaces", "HelloWorld", "Hello\t World", 12},
    {44, "equal strings with n less than length", "Hello", "Hello", 3},
    {45, "different strings with n less than length", "Hello", "World", 3},
    {46, "source and destination have trailing nulls", "Hello\0\0\0", "Hello\0\0\0", 8},
};

int run_strncmp_tests(int debug)
{
    int num_tests = sizeof(strncmp_tests) / sizeof(strncmp_tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = strncmp_tests[i];
        char temp_dest[100], temp_src[100];
        strcpy(temp_dest, test_case.dest);
        strcpy(temp_src, test_case.src);

        int e = strncmp(temp_dest, temp_src, test_case.size);
        int r = ft_strncmp(test_case.dest, test_case.src, test_case.size);

        if (e == r && strcmp(temp_dest, test_case.dest) == 0 && strcmp(temp_src, test_case.src) == 0)
        {
            if (debug)
                TEST_PASS(test_case.desc);
        }
        else
        {
            if (debug)
            {
                TEST_FAIL(test_case.desc);
                printf("Expected:\n");
                printf("(%d)[\"%s\"] and [\"%s\"]\n", e, temp_dest, temp_src);
                printf("Got:\n");
                printf("(%d)[\"%s\"] and [\"%s\"]\n", r, test_case.dest, test_case.src);
                printf("\n");
            }
            OK = FALSE;
        }
    }
    return (OK);
}

int main(int ac, char **av)
{
    int debug = FALSE;

    (void) av;
    if (ac > 1)
        debug = TRUE;

    if (run_strncmp_tests(debug))
        TEST_PASS("strncmp");
    else
        TEST_FAIL("strncmp");
    return 0;
}

