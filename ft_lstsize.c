#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list *walk;
	int		size;

	size = 0;
	walk = lst;
	while (walk)
	{
		size++;
		walk = walk->next;
	}
	return (size);
}
