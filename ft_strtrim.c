/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:00 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 06:19:27 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_exist(const char *s, char c)
{
	while (*s)
		if (*(s++) == c)
			return (1);
	return (0);
}

static size_t	alloc_size(const char *s, const char *set)
{
	const char	*start;
	const char	*end;

	end = NULL;
	while (c_exist(set, *s))
		s++;
	if (!*s)
		return (0);
	start = s;
	while (*s)
		s++;
	s--;
	while (c_exist(set, *s))
		s--;
	end = s;
	return (end - start + 1);
}

static void	fill_size(const char *s, char *buff, const char *set)
{
	const char	*start;
	const char	*end;

	while (c_exist(set, *s))
		s++;
	start = s;
	while (*s)
		s++;
	s--;
	while (c_exist(set, *s))
		s--;
	end = s;
	while (start <= end)
		*buff++ = *start++;
	*buff = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*buff;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	size = alloc_size(s1, set);
	if (!size)
		return (ft_strdup(""));
	buff = malloc(sizeof(char) * size + 1);
	if (!buff)
		return (NULL);
	fill_size(s1, buff, set);
	return (buff);
}
