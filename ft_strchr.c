/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:38:19 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 21:53:30 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while(*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *) s);

	return (NULL);
}
