#include "tests.h"



// Function to run all tests
int test_isdigit(int debug) {
	for (int i = -128; i < 255; i++) {
		if (isdigit(i) == 0) 
		{
			if (ft_isdigit(i) != 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("==> %c(%d)\n", i, i);
					printf("  -> Exp: %d\n", isdigit(i));
					printf("  -> Got: %d\n", ft_isdigit(i));
				}
				return FALSE;
			}
		} 
		if (isdigit(i) != 0) 
		{
			if (ft_isdigit(i) == 0)
			{
				if (debug)
				{
					TEST_FAIL("In this charachter");
					printf("==> %c(%d)\n", i, i);
					printf("  -> Exp: %d\n", isdigit(i));
					printf("  -> Got: %d\n", ft_isdigit(i));
				}
				return FALSE;
			}
		} 
	}
	return TRUE;
}

int main(int ac, char **av) {
	int debug = FALSE;

	(void) av;
	if (ac > 1)
		debug = TRUE;

	if (test_isdigit(debug))
		TEST_PASS("isdigit");
	else
		TEST_PASS("isdigit");
	return 0;
	return 0;
}

