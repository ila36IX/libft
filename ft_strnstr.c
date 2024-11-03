/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:11:06 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/03 17:08:31 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	j;

	if (!s || !to_find)
		return (NULL);
	if (!s[0] && !to_find[0])
		return ((char *) s);
	i = 0;
	while (s[i] && i < n)
	{
		j = i;
		k = 0;
		while (s[j] == to_find[k] && s[j] && j < n)
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

/*#include <string.h>*/
/*#include <stdlib.h>*/
/*char *_strnstr(const char *s, const char *find, size_t slen)*/
/*{*/
/*	char c, sc;*/
/*	size_t len;*/
/**/
/*	if ((c = *find++) != '\0') {*/
/*		len = strlen(find);*/
/*		do {*/
/*			do {*/
/*				if (slen-- < 1 || (sc = *s++) == '\0')*/
/*					return (NULL);*/
/*			} while (sc != c);*/
/*			if (len > slen)*/
/*				return (NULL);*/
/*		} while (strncmp(s, find, len) != 0);*/
/*		s--;*/
/*	}*/
/*	return ((char *)s);*/
/*}*/
/*int main()*/
/*{*/
/*	typedef struct {*/
/*		int index;*/
/*		char *desc;*/
/*		char *haystack;*/
/*		char *needle;*/
/*		size_t len;*/
/*	} StrnstrTestCase;*/
/*	StrnstrTestCase strnstr_tests[] = {*/
/*		{0x0A, "Haystack and needle are identical", "Cannonbolt", "Cannonbolt", 50},*/
/*	};*/
/*	StrnstrTestCase test_case = strnstr_tests[0];*/
/*	const char *expected = _strnstr(test_case.haystack, test_case.needle, test_case.len);*/
/*	const char *result = ft_strnstr(test_case.haystack, test_case.needle, test_case.len);*/
/**/
/*	printf("%p\n", expected);*/
/*	printf("%p\n", result);*/
/**/
/*	expected = _strnstr("Cannonbolt", "Cannonbolt", 50);*/
/*	result = ft_strnstr("Cannonbolt", "Cannonbolt", 50);*/
/**/
/*	printf("%p\n", expected);*/
/*	printf("%p\n", result);*/
/*}*/
