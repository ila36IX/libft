#include "tests.h"


// Function to run all tests
int	test_isprint(int debug)
{
	printf("\n");
	for (int i = -128; i < 255; i++) {
		if (isprint(i) != 0) 
		{
			if (ft_isprint(i) == 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isprint(i));
					printf("  -> Got: %d\n", ft_isprint(i));
				}
				return FALSE;
			}
		} 
		if (isprint(i) == 0) 
		{
			if (ft_isprint(i) != 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isprint(i));
					printf("  -> Got: %d\n", ft_isprint(i));
				}
				return FALSE;
			}
		} 
	}
	return TRUE;
}

int main(int ac, char **av)
{
	int debug = FALSE;

	(void) av;
	if (ac > 1)
		debug = TRUE;
	if (test_isprint(debug))
		TEST_PASS("isprint\n");
	else
		TEST_FAIL("isprint\n");

	return 0;
}
