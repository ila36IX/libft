#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *data)
{
	if (!lst || !data)
		return ;
	data->next = *lst;
	*lst = data;
}
