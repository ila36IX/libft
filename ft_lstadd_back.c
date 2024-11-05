#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *walk;

	if (!lst)
		return ; 
	new->next = NULL;
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
