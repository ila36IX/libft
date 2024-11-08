#include "tests.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
    int     index;
    char    desc[50];
    char    s1[100];
    char    s2[100];
    char    expected[200];
} TestCase;

TestCase tests[] = {
    {0x01, "Simple join", "Hello, ", "World!", "Hello, World!"},
    {0x02, "Join with empty suffix", "Hello", "", "Hello"},
    {0x03, "Join with empty prefix", "", "World", "World"},
    {0x04, "Join empty strings", "", "", ""},
    {0x05, "Join with special characters", "Hello,", " \nWorld!", "Hello, \nWorld!"},
    {0x06, "Join with spaces", "Hello", " World", "Hello World"},
    {0x07, "Join with numbers", "123", "456", "123456"},
    {0x08, "Join long strings", "A very long string that exceeds usual length", " and continues even further", "A very long string that exceeds usual length and continues even further"},
};

int run_ft_strjoin_tests(int debug) {
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = tests[i];
        char *result = ft_strjoin(test_case.s1, test_case.s2);
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
    if (run_ft_strjoin_tests(debug))
        TEST_PASS("strjoin");
    else
        TEST_FAIL("strjoin");
    return 0;
}

