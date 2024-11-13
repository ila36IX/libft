/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:33:02 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/11 08:53:50 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buff;
	size_t	n;

	n = num * size;
	if (size && num > SIZE_MAX / size)
		return (NULL);
	buff = malloc(n);
	if (!buff)
		return (NULL);
	ft_bzero(buff, num * size);
	return (buff);
}
