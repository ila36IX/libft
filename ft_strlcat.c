/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:22:27 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:11:25 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (dest[j])
		j++;
	if (size == 0 || j > size)
		return (size + i);
	while (*dest)
		dest++;
	size -= j;
	while (src && *src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	*dest = '\0';
	return (i + j);
}
