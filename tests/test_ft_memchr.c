/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:25:00 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/08 01:25:00 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"
#include <string.h>

typedef struct {
    int     index;
    char    *desc;
    void    *src;
    int     c;
    size_t  n;
} MemchrTestCase;

MemchrTestCase memchr_tests[] = {
    {0, "Find 'a' in string", "Hello, world!", 'a', 13},
    {1, "Find 'w' in string", "Hello, world!", 'w', 13},
    {2, "Find '\\0' in string", "Hello, world!", '\0', 13},
    {3, "Find first 'o' in string", "Hello, world!", 'o', 13},
    {4, "Find non-existing char", "Hello, world!", 'x', 13},
    {5, "Search within 0 bytes", "Hello, world!", 'H', 0},
    {6, "Search in empty string", "", 'H', 1},
    {7, "Find in middle of string", "Hello, world!", 'r', 10},
    {8, "Find last character", "Hello, world!", '!', 13},
    {9, "Find space character", "Hello, world!", ' ', 13},
    {10, "Find at very beginning", "Hello, world!", 'H', 13}
};

int run_memchr_tests(void *(*func_to_test)(const void*, int, size_t), int debug)
{
    int num_tests = sizeof(memchr_tests) / sizeof(memchr_tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        MemchrTestCase test_case = memchr_tests[i];

        void *expected = memchr(test_case.src, test_case.c, test_case.n);
        void *result = func_to_test(test_case.src, test_case.c, test_case.n);

        if (result == expected)
        {
            if (debug)
                TEST_PASS(test_case.desc);
        }
        else
        {
            if (debug)
            {
                TEST_FAIL(test_case.desc);
                printf("  -> Expected: %p\n", expected);
                printf("  -> Got: %p\n", result);
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
    if (run_memchr_tests(ft_memchr, debug))
        TEST_PASS("memchr");
    else
        TEST_FAIL("memchr");
    return 0;
}

