#include "tests.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    int     index;
    char    desc[50];
    char    input[100];
    unsigned int start;
    size_t len;
    char    expected[100];
} TestCase;

TestCase tests[] = {
    {0x01, "Simple substring", "Hello, World!", 7, 5, "World"},
    {0x02, "Substring from start", "Hello, World!", 0, 5, "Hello"},
    {0x03, "Substring to end", "Hello, World!", 7, 50, "World!"},
    {0x04, "Full string", "Hello, World!", 0, 50, "Hello, World!"},
    {0x05, "Empty input string", "", 0, 5, ""},
    {0x06, "Zero length", "Hello, World!", 7, 0, ""},
    {0x07, "Start beyond string length", "Hello, World!", 50, 5, ""},
    {0x09, "Substring with special characters", "Hello, @World$!", 7, 6, "@World"},
    {0x0A, "Start at end of string", "Hello", 5, 5, ""},
    {0x0B, "Negative start index", "Hello, World!", -1, 5, ""},
    {0x0C, "Substring with spaces", "Hello, World! ", 6, 6, " World"},
    {0x0D, "Substring from middle", "Cannonbolt", 3, 4, "nonb"},
    {0x0E, "one character from end", "AlienX", 5, 1, "X"},
};

int run_ft_substr_tests(int debug) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        char *result = ft_substr(test_case.input, test_case.start, test_case.len);
        int passed = TRUE;

        if (result == NULL || strcmp(result, test_case.expected) != 0) {
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
    if (run_ft_substr_tests(debug))
        TEST_PASS("substr");
    else
        TEST_FAIL("substr");
    return 0;
}

