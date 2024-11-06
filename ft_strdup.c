/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:18:28 by aljbari           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/05 06:57:54 by aljbari          ###   ########.fr       */
=======
/*   Updated: 2024/11/05 18:25:59 by aljbari          ###   ########.fr       */
>>>>>>> 0fb651dc8fa310af5fa03b8ca98b8b09019a5b03
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	if (!src)
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	i = 0;
	while (src[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*src)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}
