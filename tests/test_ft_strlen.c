/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:45:00 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/08 01:45:00 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"
#include <string.h>

typedef struct {
    int     index;
    char    *desc;
    char    *str;
} StrlenTestCase;

StrlenTestCase strlen_tests[] = {
    {0, "Empty string", ""},
    {1, "Single character", "a"},
    {2, "Short string", "Hello"},
    {3, "String with spaces", "Hello, world!"},
    {4, "String with newline", "Hello\nworld"},
    {5, "String with tabs", "Hello\tworld"},
    {6, "String with special characters", "Hello, world!@#"},
    {7, "String with numbers", "1234567890"},
    {8, "Long string", "This is a much longer string to test the function."},
    {9, "String with multiple spaces", "   "},
    {10, "Mixed characters", "Hello123!@#"}
};

int run_strlen_tests(size_t (*func_to_test)(const char*), int debug)
{
    int num_tests = sizeof(strlen_tests) / sizeof(strlen_tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        StrlenTestCase test_case = strlen_tests[i];

        size_t expected = strlen(test_case.str);
        size_t result = func_to_test(test_case.str);

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
                printf("  -> Expected: %zu\n", expected);
                printf("  -> Got: %zu\n", result);
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
    if (run_strlen_tests(ft_strlen, debug))
        TEST_PASS("strlen");
    else
        TEST_FAIL("strlen");
    return 0;
}

