/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:27:12 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/11 08:55:21 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	if (!s)
		return (-1);
	size = 0;
	while (s[size])
		size++;
	if (size <= start)
		return (-1);
	if (size - start > len)
		return (len);
	else
		return (size - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;
	int		alloc_s;

	alloc_s = alloc_size(s, start, len);
	if (alloc_s <= 0)
		return (ft_strdup(""));
	buff = malloc(sizeof(char) * (alloc_s + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		buff[i++] = s[start++];
	buff[i] = '\0';
	return (buff);
}
