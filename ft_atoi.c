/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:18:51 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/06 05:30:47 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	char	*spaces;
	int		found;

	found = 0;
	spaces = " \f\n\r\t\v";
	while (*spaces)
	{
		if (*spaces++ == c)
			found = 1;
	}
	return (found);
}

int	ft_atoi(const char *str)
{
	char			c;
	int				sign;
	unsigned int	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		c = *str++;
		nbr *= 10;
		nbr += (c - '0');
	}
	return (nbr * sign);
}
