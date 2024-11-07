#include "tests.h"

typedef struct {
    int     index;
    char    *desc;
    char    c;
} TestCase;

TestCase toupper_tests[] = {
	{0, "a", 'a'},
	{1, "z", 'z'},
	{2, "A", 'A'},
	{3, "Z", 'Z'},
	{3, "N", 'N'},
	{3, "o", 'o'},
	{4, "Non-letter character 1", '1'},
	{5, "Non-letter character $", '$'},
	{6, "Whitespace", ' '},
	{7, "Newline character", '\n'},
	{8, "Tab character", '\t'},
	{9, "Punctuation character", '.'},
	{10, "d", 'd'},
	{11, "n", 'n'},
	{12, "Digit zero", '0'},
	{13, "Special character !", '!'}
};

int run_toupper_tests(int debug)
{
	int num_tests = sizeof(toupper_tests) / sizeof(toupper_tests[0]);
	int OK = TRUE;

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = toupper_tests[i];
		int c = toupper(test_case.c);
		int _c = ft_toupper(test_case.c);
		if (c == _c)
		{
			if (debug)
				TEST_PASS(test_case.desc);
		}
		else
		{
			if (debug)
			{
				TEST_FAIL(test_case.desc);
				printf("Expected: (%c[%d])\n", _c, _c);
				printf("Got: (%c[%d])\n", c, c);
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

	if (run_toupper_tests(debug))
		TEST_PASS("toupper");
	else
		TEST_FAIL("toupper");
	return 0;
}
