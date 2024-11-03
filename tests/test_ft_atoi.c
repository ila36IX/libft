
#include "tests.h" 
#include <stdio.h>


typedef struct {
	int	index;
	char	*desc;
	char	*nbr;
} TestCase;

TestCase atoi_tests[] = {
    {0, "Zero", "0"},
    {1, "Positive single digit", "5"},
    {2, "Positive multiple digits", "12345"},
    {3, "Negative single digit", "-8"},
    {4, "Negative multiple digits", "-9876"},
    {5, "Leading zeros", "00042"},
    {6, "Maximum INT", "2147483647"},
    {7, "Minimum INT", "-2147483648"},
    {8, "Leading spaces", "   123"},
    {9, "Leading tabs", "\t\t-456"},
    {10, "Plus sign", "+789"},
    {11, "Plus sign with spaces", "   +12"},
    {12, "Mixed spaces and signs", "  -  123"},
    {13, "Multiple signs", "+-42"},
    {14, "Letters after number", "123abc"},
    {15, "Letters before number", "abc123"},
    {16, "Empty string", ""},
    {17, "Just spaces", "   "},
    {18, "Single space", " "},
    {19, "Overflow positive", "2147483648"},
    {20, "Overflow negative", "-2147483649"},
    {21, "Large overflow", "999999999999"},
    {22, "Mixed invalid chars", "@#$123"},
    {23, "Only plus sign", "+"},
    {24, "Only minus sign", "-"},
    {25, "Double decimal point", "12.34.56"},
    {26, "Mixed spaces around number", "  12  "},
    {27, "Mixed spaces and tabs around number", "\t  34 \t"},
    {28, "Signs with letters", "+a123"},
    {29, "Non-ASCII characters", "123€"},
    {30, "Whitespace only", "\t\n"},
    {31, "Whitespace before sign", "  +12"},
    {32, "Whitespace before number with sign", "  -12 34"},
    {33, "Large negative overflow", "-999999999999"},
    {34, "Sign before zero", "+0"},
    {35, "Signs with no digits", "+-"},
    {36, "Digits and special characters mixed", "12!@#"},
};

int run_atoi_tests(int (*func_to_test)(char*), int debug)
{
	int num_tests = sizeof(atoi_tests) / sizeof(atoi_tests[0]);
	int OK;

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = atoi_tests[i];

		const int expected = atoi(test_case.nbr);
		const int result = func_to_test(test_case.nbr);

		if (result == expected)
		{
			if (debug)
				TEST_PASS(test_case.desc);
		}
		else
		{
			if (debug)
			{
				TEST_PASS(test_case.desc);
				_TEST_FAIL(test_case.desc);
				printf("  -> Expected: %d\n", expected);
				printf("  -> Got: %d\n", result);
				printf("\n");
			}
			OK = FALSE;
		}
	}
	return (OK);
}

int main()
{
	if (run_atoi_tests(ft_atoi, TRUE))
		TEST_PASS("atoi");
	else
		TEST_FAIL("atoi");
	return 0;
}
