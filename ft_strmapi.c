/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:41:11 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 06:04:41 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*buff;
	unsigned int	i;

	buff = ft_strdup(s);
	if (!buff)
		return (NULL);
	i = 0;
	while(buff[i])
	{
		buff[i] = f(i, buff[i]);
		i++;
	}
	return (buff);
}
