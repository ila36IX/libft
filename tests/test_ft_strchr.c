#include "tests.h"

typedef struct {
    int     index;
    char    *desc;
    char    *s;
    char    c;
} TestCase;

TestCase strchr_tests[] = {
	{0, "Find 'X' in simple string", "AlienX", 'X'},
	{1, "Find 'o' in middle", "Ben Tennyson", 'o'},
	{2, "Find space character", "Ben 10", ' '},
	{3, "Find non-existent character", "Omnitrix", 'z'},
	{4, "Find null character", "Gwen", '\0'},
	{5, "Find first character", "Heatblast", 'H'},
	{6, "Find last character", "Diamondhead", 'd'},
	{7, "Find special character", "Kevin Levin!", '!'},
	{8, "Empty string input", "", 'a'},
	{9, "find none existing lower case", "Rath", 'A'},
	{10, "Whitespace at start", "  Spaces", ' '},
	{11, "Whitespace in middle", "Space and more space", ' '},
	{12, "Multiple occurrences", "Bailiff", 'f'},
	{13, "First occurrence of repeated character", "1337", '3'}
};

int run_strchr_tests(int debug)
{
	int num_tests = sizeof(strchr_tests) / sizeof(strchr_tests[0]);
	int OK = TRUE;

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = strchr_tests[i];
		char *p = strchr(test_case.s, test_case.c);
		char *_p = ft_strchr(test_case.s, test_case.c);
		if (p == _p)
		{
			if (debug)
				TEST_PASS(test_case.desc);
		}
		else
		{
			if (debug)
			{
				TEST_FAIL(test_case.desc);
				printf("Expected: [%p]> %s\n", p, p);
				printf("Got: [%p]> %s\n", _p, _p);
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

	if (run_strchr_tests(debug))
		TEST_PASS("strchr");
	else
		TEST_FAIL("strchr");
	return 0;
}
