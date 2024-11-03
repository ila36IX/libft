#include "tests.h" 

typedef struct {
	int	index;
	char	*desc;
	char	s[100];
	char	c;
	size_t	size;
} TestCase;

TestCase memset_tests[] = {
	{0, "simple string", "", 'a', 50},
	{1, "full array with x", "", 'x', 99},
	{2, "partial array", "Hello, World!", 'y', 5},
	{3, "fill with zero", "123456789", 0, 9},
	{4, "fill half", "ABCDEFGHIJ", 'z', 5},
	{5, "empty string", "", 'b', 0},
	{6, "1 characters", "123456789", '1', 9},
	{7, "special characters", "!@#$%^&*", '*', 8},
	{8, "max size", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 'q', 26},
	{9, "no fill", "teststring", 'c', 0},
	{10, "fill with space", "stringtest", ' ', 5}
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

int run_memset_tests(void	*(*func_to_test)(void *, int, size_t), int debug)
{
	int num_tests = sizeof(memset_tests) / sizeof(memset_tests[0]);
	int OK = TRUE;
	char *s[100];

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = memset_tests[i];

		void	*expected = memset(test_case.s, test_case.c, test_case.size);
		memcpy(s, expected, test_case.size);
		memset(test_case.s, '\0', test_case.size + 1);
		test_case.s[test_case.size] = '@';
		void	*result = func_to_test(test_case.s, test_case.c, test_case.size);

		if (result == expected && strncmp((const char *)s, result, test_case.size) == 0 && test_case.s[test_case.size] == '@')
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
				prinmem(s, test_case.size);
				printf("Got:\n");
				prinmem(result, test_case.size);
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

	if (run_memset_tests(ft_memset, debug))
		TEST_PASS("memset");
	else
		TEST_FAIL("memset");
	return 0;
}
