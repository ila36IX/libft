/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:43:15 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 18:26:56 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_acc;

	last_acc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_acc = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (last_acc);
}
