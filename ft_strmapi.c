/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:41:11 by aljbari           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/05 07:14:50 by aljbari          ###   ########.fr       */
=======
/*   Updated: 2024/11/05 18:26:37 by aljbari          ###   ########.fr       */
>>>>>>> 0fb651dc8fa310af5fa03b8ca98b8b09019a5b03
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buff;
	unsigned int	i;

	buff = ft_strdup(s);
	if (!s || !f)
		return (buff);
	if (!buff)
		return (NULL);
	i = 0;
<<<<<<< HEAD
	while(s[i])
=======
	while (buff[i])
>>>>>>> 0fb651dc8fa310af5fa03b8ca98b8b09019a5b03
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	return (buff);
}
