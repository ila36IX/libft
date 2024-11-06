/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:24:08 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/05 18:24:10 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*walk;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	walk = *lst;
	while (walk)
	{
		tmp = walk->next;
		del(walk->content);
		free(walk);
		walk = tmp;
	}
	*lst = NULL;
}
