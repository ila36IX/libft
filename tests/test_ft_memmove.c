#include "tests.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void run_tests() {
	char *s1 = NULL;
	char *s2 = NULL;
	char *o1 = NULL;
	char *o2 = NULL;
	char *test_case = NULL;
	
	test_case = "WHEN: src is less then dest";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(&s1[14], &s1[9], 9);
	o2 = ft_memmove(&s2[14], &s2[9], 9);
	if (strcmp(o1, o2) != 0)
	{
		TEST_FAIL(test_case);
		printf("\tEXP: %s\n", o1);
		printf("\tYOU: %s\n", o2);
	}
	else
		TEST_PASS(test_case);
	free(s1);
	free(s2);

	test_case = "WHEN: dest is less then src";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(&s1[9], &s1[14], 9);
	o2 = ft_memmove(&s2[9], &s2[14], 9);
	if (strcmp(o1, o2) != 0)
	{
		TEST_FAIL(test_case);
		printf("\tEXP: %s\n", o1);
		printf("\tYOU: %s\n", o2);
	}
	else
		TEST_PASS(test_case);
	free(s1);
	free(s2);

	test_case = "WHEN: dest is src";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(s1, s1, 9);
	o2 = ft_memmove(s2, s2, 9);
	if (strcmp(o1, o2) != 0)
	{
		TEST_FAIL(test_case);
		printf("\tEXP: %s\n", o1);
		printf("\tYOU: %s\n", o2);
	}
	else
		TEST_PASS(test_case);
	free(s1);
	free(s2);


	test_case = "WHEN: n is 0";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(s1, s1, 0);
	o2 = ft_memmove(s2, s2, 0);
	if (o2 == NULL)
	{
		TEST_FAIL(test_case);
		printf("\tEXP: %s\n", o1);
		printf("\tYOU: %s\n", o2);
	}
	else if (strcmp(o1, o2) != 0)
	{
		TEST_FAIL(test_case);
		printf("\tEXP: %s\n", o1);
		printf("\tYOU: %s\n", o2);
	}
	else
		TEST_PASS(test_case);
	free(s1);
	free(s2);
}

int main()
{
	run_tests();	
}
