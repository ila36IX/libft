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

static int	ft_overflow(unsigned long nbr, char next_digit, int sign)
{
	unsigned long	cutoff;
	int				cutlim;
	int				return_value;

	return_value = 0;
	if (sign == 1)
	{
		cutoff = LONG_MAX;
		return_value = -1;
	}
	else
	{
		cutoff = (unsigned long)LONG_MAX + 1;
		return_value = 0;
	}
	cutlim = cutoff % 10;
	cutoff = cutoff / 10;
	if (nbr > cutoff || (nbr == cutoff && (next_digit - '0') > cutlim))
		return (return_value);
	return (1);
}

int	ft_atoi(const char *str)
{
	char			c;
	int				sign;
	unsigned long	nbr;

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
		if (ft_overflow(nbr, *(str + 1), sign) != 1)
			return (ft_overflow(nbr, *(str + 1), sign));
		c = *str++;
		nbr *= 10;
		nbr += (c - '0');
	}
	return (nbr * sign);
}
