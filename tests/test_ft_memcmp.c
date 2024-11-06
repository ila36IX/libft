#include "tests.h"
#include <string.h>

typedef struct {
    int     index;
    char    *desc;
    char    dest[100];
    char    src[100];
    size_t  size;
} TestCase;

/* Define the test cases for memcmp */
TestCase memcmp_tests[] = {
    {0, "equal memory areas", "Hello", "Hello", 5},
    {1, "different memory areas", "Hello", "World", 5},
    {2, "prefix match", "HelloWorld", "HelloThere", 5},
    {3, "partial match", "Hello", "Helium", 4},
    {4, "empty source area", "Hello", "", 5},
    {5, "empty destination area", "", "Hello", 5},
    {6, "zero bytes", "Hello", "World", 0},
    {7, "non-ASCII characters", "日本語", "日本", 6},
    {8, "special characters", "@#$%^", "@#$%", 5},
    {9, "case sensitivity", "Hello", "hello", 5},
    {10, "source shorter than dest", "Hi", "Hello", 2},
    {11, "dest shorter than source", "Hello", "Hi", 2},
    {12, "memory areas with spaces", "Hello World", "Hello ", 11},
    {13, "dest with leading spaces", "Hello", " Hello", 6},
    {14, "source with trailing spaces", "Hello ", "Hello", 6},
    {15, "dest with tabs", "Hello\t", "Hello", 6},
    {16, "source with newline", "Hello\n", "Hello", 6},
    {17, "dest with carriage return", "Hello\r", "Hello", 6},
    {18, "source with mixed chars", "Hello123", "Hello124", 8},
    {19, "both empty areas", "", "", 5},
    {20, "one empty area, larger n", "Hello", "", 10},
    {21, "both areas with spaces", "Hello World", "Hello World", 11},
    {22, "long source area", "A very long string that exceeds usual length", "A very long string that exceeds usual length", 50},
    {23, "long dest area", "Hello", "A very long string that exceeds usual length", 5},
    {24, "memory areas with non-printable characters", "Hello\x01\x02", "Hello", 7},
    {25, "dest with non-printable characters", "Hello", "Hello\x01\x02", 7},
    {26, "both areas with non-printable characters", "Hello\x01\x02", "Hello\x01\x02", 7},
    {27, "null characters in between", "Hel\0lo", "Hel\0lo", 6},
    {28, "null character in source only", "Hel\0lo", "Hello", 6},
    {29, "null character in destination only", "Hello", "Hel\0lo", 6},
    {30, "source longer than limit", "HelloWorld", "Hello", 10},
    {31, "destination longer than limit", "Hello", "HelloWorld", 10},
    {32, "different length areas, limit exceeds length", "Hello", "Hell", 10},
    {33, "same length areas, different characters", "Hello", "World", 10},
    {34, "memory areas with repeating patterns", "abababab", "abababab", 8},
    {35, "areas with mixed alphanumeric", "abc123", "abc123", 6},
};

int run_memcmp_tests(int debug)
{
    int num_tests = sizeof(memcmp_tests) / sizeof(memcmp_tests[0]);
    int OK = TRUE;

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = memcmp_tests[i];

        int e = memcmp(test_case.dest, test_case.src, test_case.size);
        int r = ft_memcmp(test_case.dest, test_case.src, test_case.size);

        if ((e > 0 && r > 0))
        {
            if (debug)
                TEST_PASS(test_case.desc);
        }
        else if ((e < 0 && r < 0))
        {
            if (debug)
                TEST_PASS(test_case.desc);
        }
        else if (e == 0 && r == 0)
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
                printf("(%d)[\"%.*s\"] and [\"%.*s\"]\n", e, (int)test_case.size, test_case.dest, (int)test_case.size, test_case.src);
                printf("Got:\n");
                printf("(%d)[\"%.*s\"] and [\"%.*s\"]\n", r, (int)test_case.size, test_case.dest, (int)test_case.size, test_case.src);
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

    if (run_memcmp_tests(debug))
        TEST_PASS("memcmp");
    else
        TEST_FAIL("memcmp");
    return 0;
}

