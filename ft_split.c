/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:06:42 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/04 23:38:06 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	while (*s == c)
		s++;
	count = 0;
	while (*s)
	{
		count++;
		while(*s != c && *s)
			s++;
		while(*s == c && *s)
			s++;
	}
	return (count);
}

static int	len_helper(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		s++;
		size++;
	}
	return (size + 1);
}


char **ft_split(char const *s, char c)
{
	char	**tokens;
	char	*buff;
	int	i;
	int	j;

	tokens = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!tokens)
		return (NULL);
	i = 0;
	while(*s == c && *s)
		s++;
	while (*s)
	{
		buff = malloc(sizeof(char) * len_helper(s, c));
		j = 0;
		if (!buff)
			return (NULL);
		while(*s != c && *s)
			buff[j++] = *s++;
		buff[j] = '\0';
		tokens[i++] = buff;
		while(*s == c && *s)
			s++;
	}
	tokens[i] = NULL;
	return (tokens);
}
