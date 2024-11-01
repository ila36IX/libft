/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:22:27 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/01 21:25:35 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int 	i;
	unsigned int 	j;

	i = 0;
	j = 0;
	while(src[i])
		i++;
	while(dest[j])
		j++;
	if (size == 0 || j > size)
		return (size + i);
	while (*dest)
		dest++;
	size -= j;
	while (*src && size > 1)
	{
		*dest++ = *src++;	
		size--;
	}
	*dest = '\0';
	return (i + j);
}
