/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:33:02 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:44:54 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buff;

	buff = malloc(num * size);
	if (!buff)
		return NULL;
	bzero(buff, num * size);
	return (buff);
}
