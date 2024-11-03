#include "tests.h" 

typedef struct {
	int	index;
	char	*desc;
	char	s[100];
	size_t	size;
} TestCase;

TestCase bzero_tests[] = {
	{0, "simple string", "Hello, World!", 5},
	{1, "full array", "123456789", 9},
	{2, "zero bytes", "abcdefg", 0},
	{3, "half array", "memset test", 6},
	{4, "special characters", "!@#$%^&*", 8},
	{5, "133 characters", "133", 3},
	{6, "no operation", "hello", 0},
	{7, "all spaces", "          ", 10},
	{8, "mixed content", "12ab34cd56", 5},
	{9, "already zeroed", "\0\0\0\0\0\0\0\0", 8}
};

void prinmem(void *m, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		if (i % 16 == 0 && i)
			printf("\n");
		printf("0x%02X ", ((char *) m)[i]);
		i++;
	}
	printf("\n");
}

int run_bzero_tests(void (*func_to_test)(void *, size_t), int debug)
{
	int num_tests = sizeof(bzero_tests) / sizeof(bzero_tests[0]);
	int OK = TRUE;
	char *s[100];

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = bzero_tests[i];

		test_case.s[test_case.size] = 'i';
		bzero(test_case.s, test_case.size);
		memcpy(s, test_case.s, test_case.size + 1);
		memset(test_case.s, 'x', test_case.size);
		func_to_test(test_case.s, test_case.size);

		if (memcmp((const char *) s, test_case.s, test_case.size) == 0 && test_case.s[test_case.size] == 'i')
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
				prinmem(s, test_case.size + 1);
				printf("Got:\n");
				prinmem(test_case.s, test_case.size + 1);
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

	if (run_bzero_tests(ft_bzero, debug))
		TEST_PASS("bzero");
	else
		TEST_FAIL("bzero");
	return 0;
}
