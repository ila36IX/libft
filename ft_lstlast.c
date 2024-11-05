#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *walk;

	walk = lst;
	if (!walk)
		return (NULL);
	while (walk->next)
		walk = walk->next;
	return (walk);
}
