#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*walk;

	walk = lst;
	while (walk)
	{
		f(walk->content);
		walk = walk->next;
	}
}
