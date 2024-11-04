#include "tests.h"


// Function to run all tests
int	test_isascii(int debug)
{
	for (int i = -128; i < 255; i++) {
		if (isascii(i) != 0) 
		{
			if (ft_isascii(i) == 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isascii(i));
					printf("  -> Got: %d\n", ft_isascii(i));
				}
				return FALSE;
			}
		} 
		if (isascii(i) == 0) 
		{
			if (ft_isascii(i) != 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isascii(i));
					printf("  -> Got: %d\n", ft_isascii(i));
				}
				return (FALSE);
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
	if (test_isascii(debug))
		TEST_PASS("isascii");
	else
		TEST_FAIL("isascii");
	return 0;
}

