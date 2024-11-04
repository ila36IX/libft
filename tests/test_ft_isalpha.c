#include "tests.h"



// Function to run all tests
int	test_islpha(int debug)
{
	for (int i = -128; i < 255; i++) {
		if (isalpha(i) > 0) 
		{
			if (ft_isalpha(i) <= 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isalpha(i));
					printf("  -> Got: %d\n", ft_isalpha(i));
				}
					return FALSE;
			}
		} 
		if (isalpha(i) == 0) 
		{
			if (ft_isalpha(i) > 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isalpha(i));
					printf("  -> Got: %d\n", ft_isalpha(i));
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
	if (test_islpha(debug))
		TEST_PASS("isalpha");
	else
		TEST_FAIL("isalpha");

	return 0;
}

