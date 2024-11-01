/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:03:58 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 22:10:43 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	unsigned char a;
	unsigned char b;

	i = 0;
	while(i < n)
	{
		a = ((unsigned char *) s1)[i];
		b = ((unsigned char *) s2)[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
