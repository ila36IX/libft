/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:11:06 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 22:46:50 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	int	i;
	int	j;
	int	k;

	if (!s || !to_find)
		return (NULL);
	i = 0;
	while (s[i])
	{
		j = i;
		k = 0;
		while (s[j] == to_find[k] && k < n)
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0' && k == n)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
