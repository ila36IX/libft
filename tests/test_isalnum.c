#include "tests.h"


// Function to run all tests
int	test_isalnum(int debug)
{
	printf("\n");
	for (int i = -128; i < 255; i++) {
		if (isalnum(i) != 0) 
		{
			if (ft_isalnum(i) == 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isalnum(i));
					printf("  -> Got: %d\n", ft_isalnum(i));
				}
				return FALSE;
			}
		} 
		if (isalnum(i) == 0) 
		{
			if (ft_isalnum(i) != 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("%d\n", i);
					printf("  -> Exp: %d\n", isalnum(i));
					printf("  -> Got: %d\n", ft_isalnum(i));
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
	if (test_isalnum(debug))
		TEST_PASS("isalnum\n");
	else
		TEST_FAIL("isalnum\n");
	return 0;
}

