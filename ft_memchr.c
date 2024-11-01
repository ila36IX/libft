/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:57:16 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 22:04:27 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;
	char	*tempP;

	i = 0;
	tempP = (char *) s;
	while (i < n)
	{
		if (tempP[i] == (char) c)
			return (tempP);
		i++;
	}
	return (NULL);
}
