/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:57:09 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 06:19:27 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    int     index;
    char    desc[50];
    char    input[200];
    char    set[50];
    char    expected[200];
} TestCase;

TestCase tests[] = {
    {0x01, "Simple trim", "  Ben10 is cool  ", " ", "Ben10 is cool"},
    {0x02, "Trim special characters", "**Hello, World!**", "*", "Hello, World!"},
    {0x03, "Trim multiple characters", "-=-Hello-=-", "-=", "Hello"},
    {0x04, "No characters to trim", "Hello", " ", "Hello"},
    {0x05, "Trim only beginning", "123Hello", "123", "Hello"},
    {0x06, "Trim only end", "Hello123", "123", "Hello"},
    {0x07, "Trim beginning and end", "123Hello123", "123", "Hello"},
    {0x08, "Empty set", "Hello", "", "Hello"},
    {0x09, "Empty input string", "", "123", ""},
    {0x0A, "All characters to trim", "****", "*", ""},
    {0x0B, "Trim newline characters", "\n\nHello\n\n", "\n", "Hello"},
    {0x0C, "Trim tabs", "\t\tHello\t\t", "\t", "Hello"},
    {0x0D, "Trim mixed whitespace", " \t\n Hello \n\t ", " \t\n", "Hello"},
    {0x0E, "Trim special symbols", "$$Cannonbolt$$", "$", "Cannonbolt"},
    {0x0F, "Trim from middle (should not)", "Hel*lo", "*", "Hel*lo"},
    {0x10, "Trim all matching characters", "====", "=", ""},
    {0x11, "No characters in set", "Hello World!", "XYZ", "Hello World!"},
    {0x12, "Single character input", "A", "A", ""},
    {0x13, "Single character set", "Hello", "H", "ello"},
    {0x14, "Set larger than input", "Hi", "Hia", ""},
    {0x15, "Long set with spaces", "  Hello World!  ", " !", "Hello World"},
    {0x16, "Trimming numerals", "123ali456", "123456", "ali"},
};

int run_ft_strtrim_tests(int debug) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        char *result = ft_strtrim(test_case.input, test_case.set);
        int passed = TRUE;
        
        if (result == NULL || strcmp(result, test_case.expected) != 0)
        {
            passed = FALSE;
            OK = FALSE;
        }

        if (debug) {
            if (passed)
                TEST_PASS(test_case.desc);
            else {
                TEST_FAIL(test_case.desc);
                printf("Expected: \"%s\"\n", test_case.expected);
                printf("Got: \"%s\"\n", result ? result : "NULL");
            }
        }

        free(result);
    }
    return (OK);
}

int main(int ac, char **av)
{
    int debug = FALSE;

    (void) av;
    if (ac > 1)
        debug = TRUE;
    if (run_ft_strtrim_tests(debug))
        TEST_PASS("strtrim");
    else
        TEST_FAIL("strtrim");
    return 0;
}

