/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 04:27:46 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:11:21 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

size_t _strlcat(char *  dst, const char * src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}
typedef struct {
    int     index;
    char    *desc;
    char    dest[100];
    char    src[100];
    size_t  size;
} TestCase;

TestCase strlcat_tests[] = {
    {0, "simple string concatenation", "Hello", " World", 12},
    {1, "partial string concatenation", "Hello", " World", 8},
    {2, "full string concatenation", "Hello", " World", 15},
    {3, "empty source string", "Hello", "", 8},
    {4, "empty destination string", "", "Hello", 8},
    {5, "zero bytes", "Hello", " World", 0},
    {6, "large source string", "Hello", " World is a great place", 100},
    {7, "source longer than destination", "Hello", " World is super awesome", 100},
    {8, "source with spaces", "Hello", "    World", 9},
    {9, "source with special characters", "Hello", "@#$%^&*()", 15},
    {11, "source with mixed cases", "Hello", " wORLD", 10},
    {12, "source with leading spaces", "Hello", "    World", 12},
    {13, "source with trailing spaces", "Hello", "World    ", 12},
    {14, "source with tabs", "Hello", "\tWorld", 10},
    {15, "source with newline", "Hello", "World\n", 10},
    {16, "source with carriage return", "Hello", "World\r", 10},
    {17, "source with mixed invalid chars", "Hello", "@#$123", 12},
    {18, "source with only spaces", "Hello", "    ", 12},
    {19, "empty src with none zero n", "Hello", "", 20},
    {20, "empty dest with none zero n", "", "Hello", 20},
     {21, "destination exactly filled", "Hello", " World", 11},
    {22, "destination one less than needed", "Hello", " World", 10},
    {23, "destination oversized", "Hello", " World", 50},
    {24, "source much larger than needed", "Hello", " A very very long string that exceeds destination", 30},
    {25, "destination one byte less than source length", "Hello", "World", 9}, {26, "both strings empty", "", "", 5},
    {27, "destination partially empty", "Hi\0\0\0\0\0\0\0", " World", 12},
    {28, "source partially empty", "Hello", "Wo\0\0\0\0\0\0\0", 12},
    {29, "destination with initial NULL", "\0Hello", " World", 12},
    {30, "source with initial NULL", "Hello", "\0World", 12},
    {31, "destination filled to size limit", "1234567890", " World", 10},
    {32, "destination full but not null-terminated", "1234567890", " World", 20},
    {33, "source starts with null character", "Hello", "\0 World", 12},
};

int run_strlcat_tests(int debug)
{
    int num_tests = sizeof(strlcat_tests) / sizeof(strlcat_tests[0]);
    int OK = TRUE;
    char s[100];

    for (int i = 0; i < num_tests; i++) {
        TestCase test_case = strlcat_tests[i];
        strcpy(s, test_case.dest);
        unsigned int e = _strlcat((char *) s, test_case.src, test_case.size);
        unsigned int r = ft_strlcat(test_case.dest, test_case.src, test_case.size);
        if (strcmp((char *) s, test_case.dest) == 0 && r == e)
        {
            if (debug)
                TEST_PASS(test_case.desc);
        }
        else
        {
            if (debug)
            {
                TEST_FAIL(test_case.desc);
                printf("Expected:\n");
                    printf("(%u)[\"%s\"]\n", e, s);
                printf("Got:\n");
                    printf("(%u)[\"%s\"]\n", r, test_case.dest);
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

    if (run_strlcat_tests(debug))
        TEST_PASS("strlcat");
    else
        TEST_FAIL("strlcat");
    return 0;
}

