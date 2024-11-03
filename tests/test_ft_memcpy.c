#include "tests.h" 

typedef struct {
	int	index;
	char	*desc;
	char	src[100];
	char	dest[100];
	size_t	size;
} TestCase;

TestCase memcpy_tests[] = {
	{0, "simple string copy", "Hello, World!", "Goodbye!", 7},
	{1, "partial array copy", "123456789", "abcdefg", 5},
	{2, "full array copy", "", "Lorem ipsum dolor sit amet", 26},
	{3, "empty source string", "Hello", "", 5},
	{4, "copy to same buffer", "samebuffer", "samebuffer", 11},
	{5, "non-ASCII characters", "initial", "日本語", 3},
	{6, "special characters", "specialchars", "!@#$%^&*", 8},
	{7, "zero bytes", "nochange", "shouldnotchange", 0},
	{8, "large copy", "short", "averyverylongstringthatexceeds", 35},
	{9, "whitespace", "white    space", "    ", 4},
	{10, "overlapping regions", "0123456789", "3456789", 7},
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

int run_memcpy_tests(int debug)
{
	int num_tests = sizeof(memcpy_tests) / sizeof(memcpy_tests[0]);
	int OK = TRUE;
	char *s[100];

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = memcpy_tests[i];

		test_case.dest[test_case.size] = 'i';
		memcpy(test_case.dest, test_case.src, test_case.size);
		memcpy(s, test_case.dest, test_case.size + 1);
		memset(test_case.dest, 'x', test_case.size);
		ft_memcpy(test_case.dest, test_case.src, test_case.size);

		if (memcmp((const char *) s, test_case.dest, test_case.size) == 0 && test_case.dest[test_case.size] == 'i')
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
				prinmem(test_case.dest, test_case.size + 1);
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

	if (run_memcpy_tests(debug))
		TEST_PASS("memcpy");
	else
		TEST_FAIL("memcpy");
	return 0;
}
