/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:14:21 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 07:15:58 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void make_uppercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

static void make_lowercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'A' && *c <= 'Z')
        *c += 32;
}

static void all_n(unsigned int i, char *c)
{
    (void)i;
    *c = 'n';
}

static void alternate_case(unsigned int i, char *c)
{
    if (i % 2 == 0)
    {
        if (*c >= 'a' && *c <= 'z')
            *c -= 32;
    }
    else
    {
        if (*c >= 'A' && *c <= 'Z')
            *c += 32;
    }
}

static void identity(unsigned int i, char *c)
{
    (void)i;
    (void)c;
}

typedef struct {
    int     index;
    char    *desc;
    char    *s;
    void    (*f)(unsigned int, char*);
    char    *exp;
} TestCase;

TestCase striteri_tests[] = {
    {1, "Convert to uppercase", "omnitrix", make_uppercase, "OMNITRIX"},
    {2, "Convert to lowercase", "VILGAX", make_lowercase, "vilgax"},
    {3, "Alternate case", "ben tennyson", alternate_case, "BeN tEnNySoN"},
    {4, "Empty string", "", identity, ""},
    {5, "Single char - uppercase", "x", make_uppercase, "X"},
    {6, "Single char - lowercase", "Z", make_lowercase, "z"},
    {7, "String with spaces", "Way Big", identity, "Way Big"},
    {8, "Special chars", "XLR8!", identity, "XLR8!"},
    {9, "Mixed alphanumeric", "Alien10!", make_uppercase, "ALIEN10!"},
    {10, "Long string", "It started when an alien device did what it did", make_uppercase, 
        "IT STARTED WHEN AN ALIEN DEVICE DID WHAT IT DID"},
    {11, "Alphanumeric mix", "Ben10XLR8", alternate_case, "BeN10xLr8"},
    {12, "All n chars", "Gwen", all_n, "nnnn"},
    {13, "All n longer string", "Kevin", all_n, "nnnnn"},
    {14, "All same char lowercase", "aaaaa", make_uppercase, "AAAAA"},
    {15, "All same char uppercase", "ZZZZZ", make_lowercase, "zzzzz"},
    {16, "Mixed case", "HeAt BlAsT", make_uppercase, "HEAT BLAST"},
    {17, "Mixed case reverse", "DiAmOnDhEaD", make_lowercase, "diamondhead"},
    {18, "String with newlines", "Four\nArms", identity, "Four\nArms"},
    {19, "String with tabs", "Grey\tMatter", identity, "Grey\tMatter"},
    {20, "NULL input string", NULL, identity, ""},
    {21, "NULL function pointer with valid string", "Upgrade", NULL, "Upgrade"},
    {0, "null", NULL, NULL, ""}
};

int run_striteri_tests(int debug)
{
    int     num_tests;
    int     OK;
    TestCase    t;
    OK = TRUE;
    num_tests = sizeof(striteri_tests) / sizeof(striteri_tests[0]);
    
    for (int i = 0; i < num_tests; i++) {
        t = striteri_tests[i];
        char *input = t.s ? strdup(t.s) : NULL;  // Create a copy of input string
        
        ft_striteri(input, t.f);
        
        if ((!input && !t.exp) || (input && strcmp(input, t.exp) == 0))
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
                printf("  -> Got: \"%s\"\n", input ? input : "NULL");
                printf("\n");
            }
            OK = FALSE;
        }
        free(input);  // Free the duplicated string
    }
    return (OK);
}

int main(int ac, char **av)
{
    int debug = FALSE;
    (void) av;
    if (ac > 1)
        debug = TRUE;
    
    if (run_striteri_tests(debug))
        TEST_PASS("striteri");
    else
        TEST_FAIL("striteri");
    
    return 0;
}
