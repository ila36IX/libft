#include "libft.h"

void ft_lstclear(t_list	**lst, void (*del)(void*))
{
	t_list	*walk;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	walk = *lst;
	while(walk)
	{
		tmp = walk->next;
		del(walk->content);
		free(walk);
		walk = tmp;
	}
	*lst = NULL;
}
