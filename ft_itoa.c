/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:00:06 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 18:25:07 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	rev(char *s)
{
	char	*end;
	char	temp;

	if (*s == '-')
		s++;
	end = s;
	while (*end)
		end++;
	end--;
	while (s < end)
	{
		temp = *s;
		*s++ = *end;
		*end-- = temp;
	}
}

char	*ft_itoa(int n)
{
	char			*buff;
	int				i;
	unsigned int	nb;

	buff = malloc(sizeof(char) * num_size(n));
	if (!buff)
		return (NULL);
	i = 0;
	nb = n;
	if (n == 0)
		buff[i++] = '0';
	if (n < 0)
	{
		nb = n * -1;
		buff[i++] = '-';
	}
	while (nb)
	{
		buff[i++] = nb % 10 + '0';
		nb /= 10;
	}
	buff[i] = 0;
	rev(buff);
	return (buff);
}
