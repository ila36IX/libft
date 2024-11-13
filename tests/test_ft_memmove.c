#include "tests.h"


int run_memmove_tests(int debug) {
	char *s1 = NULL;
	char *s2 = NULL;
	char *o1 = NULL;
	char *o2 = NULL;
	char *test_case = NULL;
	int OK = TRUE;
	
	test_case = "WHEN: src is less then dest";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(&s1[14], &s1[9], 9);
	o2 = ft_memmove(&s2[14], &s2[9], 9);
	if (strcmp(o1, o2) != 0)
	{
		if (debug)
		{
			TEST_FAIL(test_case);
			printf("\tEXP: %s\n", o1);
			printf("\tYOU: %s\n", o2);
			OK = FALSE;
		}
	}
	else
	{
		if (debug)
			TEST_PASS(test_case);
	}
	free(s1);
	free(s2);

	test_case = "WHEN: dest is less then src";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(&s1[9], &s1[14], 9);
	o2 = ft_memmove(&s2[9], &s2[14], 9);
	if (strcmp(o1, o2) != 0)
	{
		if (debug)
		{

			TEST_FAIL(test_case);
			printf("\tEXP: %s\n", o1);
			printf("\tYOU: %s\n", o2);
			OK = FALSE;
		}
	}
	else
	{
		if (debug)
			TEST_PASS(test_case);
	}
	free(s1);
	free(s2);

	test_case = "WHEN: dest is src";
	s1 = "seg fault";
	o1 = memmove(s1, s1, 9);
	o2 = ft_memmove(s1, s1, 9);
	if (strcmp(o1, o2) != 0)
	{
		if (debug)
		{
			TEST_FAIL(test_case);
			printf("\tEXP: %s\n", o1);
			printf("\tYOU: %s\n", o2);
			OK = FALSE;
		}
	}
	else
	{
		if (debug)
			TEST_PASS(test_case);
	}


	test_case = "WHEN: n is 0";
	s1 = strdup("alien is not from earth");
	s2 = strdup("alien is not from earth");
	o1 = memmove(s1, s1, 0);
	o2 = ft_memmove(s2, s2, 0);
	if (o2 == NULL)
	{
		if (debug)
		{
			TEST_FAIL(test_case);
			printf("\tEXP: %s\n", o1);
			printf("\tYOU: %s\n", o2);
		}
	}
	else if (strcmp(o1, o2) != 0)
	{
		if (debug)
		{
			TEST_FAIL(test_case);
			printf("\tEXP: %s\n", o1);
			printf("\tYOU: %s\n", o2);
		}
	}
	else
	{
		if (debug)
			TEST_PASS(test_case);
	}
	free(s1);
	free(s2);
	return (OK);
}

int main(int ac,char **av)
{
	int debug = FALSE;

	(void) av;
	if (ac > 1)
		debug = TRUE;

	if (run_memmove_tests(debug))
		TEST_PASS("memmove");
	else
		TEST_FAIL("memmove");
	return (0);
}
