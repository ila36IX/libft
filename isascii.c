/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:54:03 by aljbari           #+#    #+#             */
/*   Updated: 2024/10/22 23:57:19 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
