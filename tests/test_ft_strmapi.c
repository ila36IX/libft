#include "tests.h"
#include <stdio.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:07:46 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 06:07:46 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char	to_lower(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static char	all_n(unsigned int i, char c)
{
	(void)c;
	(void)i;
	return ('n');
}

static char	alternate_case(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	else
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}

static char	identity(unsigned int i, char c)
{
	(void)i;
	return (c);
}

typedef struct
{
	int		index;
	char	*desc;
	char	*s;
	char	(*f)(unsigned int, char);
	char	*exp;
}			TestCase;

TestCase	strmapi_tests[] = {{1, "Convert to uppercase", "omnitrix", to_upper,
		"OMNITRIX"},
							{2, "Convert to lowercase", "VILGAX", to_lower,
								"vilgax"},
							{3, "Alternate case", "ben tennyson",
								alternate_case, "BeN TeNnYsOn"},
							{4, "Empty string", "", identity, ""},
							{5, "Single char - uppercase", "x", to_upper, "X"},
							{6, "Single char - lowercase", "Z", to_lower, "z"},
							{7, "String with spaces", "Way Big", identity,
								"Way Big"},
							{8, "Special chars", "XLR8!", identity, "XLR8!"},
							{9, "Mixed alphanumeric", "Alien10!", to_upper,
								"ALIEN10!"},
							{10, "Long string",
								"It started when an alien device did what it did",
								to_upper,
								"IT STARTED WHEN AN ALIEN DEVICE DID WHAT IT DID"},
							{11, "Alphanumeric mix", "Ben10XLR8",
								alternate_case, "BeN10xLr8"},
							{12, "Add index to chars", "Gwen", all_n, "nnnn"},
							{13, "Add index to longer string", "Kevin", all_n,
								"nnnnn"},
							{14, "All same char lowercase", "aaaaa", to_upper,
								"AAAAA"},
							{15, "All same char uppercase", "ZZZZZ", to_lower,
								"zzzzz"},
							{16, "Mixed case", "HeAt BlAsT", to_upper,
								"HEAT BLAST"},
							{17, "Mixed case reverse", "DiAmOnDhEaD", to_lower,
								"diamondhead"},
							{18, "String with newlines", "Four\nArms", identity,
								"Four\nArms"},
							{19, "String with tabs", "Grey\tMatter", identity,
								"Grey\tMatter"},
							{21, "NULL input string", NULL, identity, ""},
							{22, "NULL function pointer with valid string",
								"Upgrade", NULL, "Upgrade"},
							{0, "null", NULL, NULL, ""}};

int	run_strmapi_tests(int debug)
{
	int		num_tests;
	char	*result;
	int		OK;

	TestCase t; /* test */
	OK = TRUE;
	num_tests = sizeof(strmapi_tests) / sizeof(strmapi_tests[0]);
	for (int i = 0; i < num_tests; i++)
	{
		t = strmapi_tests[i];
		result = ft_strmapi(t.s, t.f);
		if (strcmp(result, t.exp) == 0)
		{
			if (debug)
				TEST_PASS(t.desc);
		}
		else
		{
			if (debug)
			{
				TEST_FAIL(t.desc);
				printf("  -> Expected: \"%s\"\n", t.exp);
				printf("  -> Got: \"%s\"\n", result);
				printf("\n");
			}
			OK = FALSE;
		}
	}
	return (OK);
}

int	main(int ac, char **av)
{
	int	debug;

	debug = FALSE;
	(void)av;
	if (ac > 1)
		debug = TRUE;
	if (run_strmapi_tests(debug))
		TEST_PASS("strmapi");
	else
		TEST_FAIL("strmapi");
	/*char *s = strdup("ben tennyson");*/
	/*int i = 0;*/
	/*while(*s)*/
	/*	printf("%c", alternate_case(i++, *s++));*/
	return (0);
}
