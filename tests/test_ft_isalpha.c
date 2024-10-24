#include "tests.h"

int	ft_isalpha(int c);


// Function to run all tests
void test_islpha() {
	int	out;
	int	exp;

	printf("\n");
	for (int i = -128; i < 255; i++) {
		if (isalpha(i) > 0) 
		{
			if (ft_isalpha(i) <= 0)
			{
				TEST_FAIL("In this charachter");
				printf("%d\n", i);
				printf("  -> Exp: %d\n", isalpha(i));
				printf("  -> Got: %d\n", ft_isalpha(i));
				exit(1);
			}
		} 
		if (isalpha(i) == 0) 
		{
			if (ft_isalpha(i) > 0)
			{
				TEST_FAIL("In this charachter");
				printf("%d\n", i);
				printf("  -> Exp: %d\n", isalpha(i));
				printf("  -> Got: %d\n", ft_isalpha(i));
				exit(1);
			}
		} 
	}
	TEST_PASS("All good :)\n");
}

int main() {
	test_islpha(); // Run the tests with ft_atoi function
	return 0;
}

