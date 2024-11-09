/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:16:08 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 18:25:10 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*walk;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	walk = *lst;
	while (walk->next)
		walk = walk->next;
	walk->next = new;
}
