/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:11:06 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:29:30 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	j;

	if (!s || !to_find)
		return (NULL);
	if ((!*s && !*to_find) || (!*to_find && !n))
		return ((char *)s);
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
