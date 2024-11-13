/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:04:48 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 18:26:12 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_sz(char const *s1, char const *s2)
{
	size_t	size;

	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	return (size + 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	buff = malloc(sizeof(char) * (ft_calc_sz(s1, s2)));
	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			buff[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			buff[i++] = s2[j++];
	buff[i] = '\0';
	return (buff);
}
