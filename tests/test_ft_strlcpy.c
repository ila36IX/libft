#include "tests.h"

/*
 * _strlcpy - the original bsd implementation, do not change this function
 */
unsigned int _strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0)
		{
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0)
	{
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++);
	}

	return(s - src - 1);	/* count does not include NUL */
}

typedef struct {
    int     index;
    char    *desc;
    char    dest[100];
    char    src[100];
    size_t  size;
} TestCase;

TestCase strlcpy_tests[] = {
	{0, "simple string copy", "", "Cannonbolt", 8},
	{1, "partial string copy", "Cannon", "Cannonbolt", 6},
	{2, "full string copy", "Cannonbolt", "Cannonbolt", 9},
	{3, "empty source string", "Cannonbolt", "", 0},
	{4, "empty destination string", "", "Cannonbolt", 0},
	{5, "zero bytes", "Cannonbolt", "Cannonbolt", 0},
	{6, "large source string", "Cannonbolt", "Cannonbolt is a powerful alien", 100},
	{7, "source longer than destination", "Cannonbolt", "Cannonbolt is super strong", 100},
	{8, "source with spaces", "Cannonbolt", "Cannon bolt", 9},
	{9, "source with special characters", "Cannonbolt", "@#$%^&*()", 9},
	{10, "source with non-ASCII characters", "Cannonbolt", "日本語", 9},
	{11, "source with mixed cases", "Cannonbolt", "cANNONbolt", 9},
	{12, "source with leading spaces", "Cannonbolt", "   Cannonbolt", 9},
	{13, "source with trailing spaces", "Cannonbolt", "Cannonbolt   ", 9},
	{14, "source with tabs", "Cannonbolt", "\tCannonbolt", 9},
	{15, "source with newline", "Cannonbolt", "Cannonbolt\n", 9},
	{16, "source with carriage return", "Cannonbolt", "Cannonbolt\r", 9},
	{17, "source with mixed invalid chars", "Cannonbolt", "@#$123", 9},
	{18, "source with only spaces", "Cannonbolt", "   ", 9},
	{19, "empty src with none zero n", "Cannonbolt", "", 61},
	{19, "empty dest with none zero n", "", "Cannonbolt", 61},
};

int run_strlcpy_tests(int debug)
{
	int num_tests = sizeof(strlcpy_tests) / sizeof(strlcpy_tests[0]);
	int OK = TRUE;
	char s[100];

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = strlcpy_tests[i];
		strcpy(s, test_case.dest);
		unsigned int e = _strlcpy((char *) s, test_case.src, test_case.size);
		unsigned int r = ft_strlcpy(test_case.dest, test_case.src, test_case.size);
		if (strcmp((char *) s, test_case.dest) == 0 && r == e)
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
					printf("(%u)[\"%s\"]\n", e, s);
				printf("Got:\n");
					printf("(%u)[\"%s\"]\n", r, test_case.dest);
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

	ft_strlcpy(NULL, "no null please", 0);
	if (run_strlcpy_tests(debug))
		TEST_PASS("strlcpy");
	else
		TEST_FAIL("strlcpy");
	return 0;
}
