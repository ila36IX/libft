/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:12:26 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 05:37:49 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h" 

typedef struct {
	int	index;
	char	*desc;
	int	n;
	char	*exp;
} TestCase;

TestCase itoa_tests[] = {
    {1, "Simple positive single digit", 6, "6"},
    {2, "Simple positive double digit", 61, "61"},
    {3, "Simple positive triple digit", 1337, "1337"},
    {4, "Zero value", 0, "0"},
    {5, "Simple negative single digit", -6, "-6"},
    {6, "Simple negative double digit", -42, "-42"},
    {7, "Simple negative triple digit", -123, "-123"},
    {8, "INT_MAX", 2147483647, "2147483647"},
    {9, "INT_MIN", -2147483648, "-2147483648"},
    {10, "All same digits positive", 111111, "111111"},
    {11, "All same digits negative", -999999, "-999999"},
    {12, "Power of 10 - 10", 10, "10"},
    {13, "Power of 10 - 100", 100, "100"},
    {14, "Power of 10 - 1000", 1000, "1000"},
    {15, "Trailing zero - positive", 1230, "1230"},
    {16, "Trailing zeros - positive", 123000, "123000"},
    {17, "Trailing zero - negative", -1230, "-1230"},
    {18, "Palindrome - positive", 12321, "12321"},
    {19, "Palindrome - negative", -12321, "-12321"},
    {20, "Sequential digits ascending", 123456, "123456"},
    {21, "Sequential digits descending", 987654, "987654"},
    {22, "Close to INT_MAX", 2147483646, "2147483646"},
    {23, "Close to INT_MIN", -2147483647, "-2147483647"},
    {24, "Positive one", 1, "1"},
    {25, "Negative one", -1, "-1"}
};

int run_itoa_tests(int debug)
{
	int num_tests = sizeof(itoa_tests) / sizeof(itoa_tests[0]);
	int OK = TRUE;
	char *result;

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = itoa_tests[i];

		result = ft_itoa(test_case.n);

		if (strcmp(test_case.exp, result) == 0)
		{
			if (debug)
				TEST_PASS(test_case.desc);
		}
		else
		{
			if (debug)
			{
				TEST_FAIL(test_case.desc);
				printf("Expected: \"%s\"\n", test_case.exp);
				printf("Got: \"%s\"\n", result);
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

	if (run_itoa_tests(debug))
		TEST_PASS("itoa");
	else
		TEST_FAIL("itoa");
	return 0;
}
