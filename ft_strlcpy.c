/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:57:41 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/03 20:24:38 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	*dest = '\0';
	return (i);
}
