#include "tests.h"



// Function to run all tests
void test_isdigit() {
	int	out;
	int	exp;

	printf("\n");
	for (int i = -128; i < 255; i++) {
		if (isdigit(i) > 0) 
		{
			if (ft_isdigit(i) <= 0)
			{
				TEST_FAIL("In this charachter");
				printf("==> %c(%d)\n", i, i);
				printf("  -> Exp: %d\n", isdigit(i));
				printf("  -> Got: %d\n", ft_isdigit(i));
				exit(1);
			}
		} 
		if (isdigit(i) == 0) 
		{
			if (ft_isdigit(i) > 0)
			{
				TEST_FAIL("In this charachter");
				printf("==> %c(%d)\n", i, i);
				printf("  -> Exp: %d\n", isdigit(i));
				printf("  -> Got: %d\n", ft_isdigit(i));
				exit(1);
			}
		} 
	}
	TEST_PASS("is_digit works fine\n");
}

int main() {
	test_isdigit(); // Run the tests with ft_atoi function
	return 0;
}

