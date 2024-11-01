/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:43:15 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 21:53:30 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strrchr(const char *s, int c)
{
	char	*last_acc;

	last_acc = NULL;
	if (!s)
		return (NULL);
	while(*s)
	{
		if (*s == c)
			last_acc = (char *) s;
		s++;
	}
	if (c == 0)
		return ((char *) s);

	return (last_acc);

}
