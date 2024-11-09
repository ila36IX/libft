/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:06:42 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 19:29:47 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	while (*s == c && *s)
		s++;
	count = 0;
	while (*s)
	{
		count++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
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

static char	*fill_buff(char **tokens, char const *s, char c, int i)
{
	char	*buff;
	int		j;

	buff = malloc(sizeof(char) * len_helper(s, c));
	if (!buff)
		return (NULL);
	j = 0;
	while (*s != c && *s)
		buff[j++] = *s++;
	buff[j] = '\0';
	tokens[i] = buff;
	while (*s == c && *s)
		s++;
	return ((char *)s);
}

static void	free_arr(char **tokens, int filled_size)
{
	int	i;

	i = 0;
	while (i < filled_size)
	{
		if (tokens[i])
			free(tokens[i++]);
	}
	free(tokens);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	int		i;

	if (!s)
		return (NULL);
	tokens = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		s = fill_buff(tokens, s, c, i);
		if (!s)
		{
			free_arr(tokens, i);
			return (NULL);
		}
		i++;
	}
	return ((tokens[i] = NULL), tokens);
}
