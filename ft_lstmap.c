#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
		t_list *head;
		t_list *node;

		if (!lst || !f || !del)
			return (NULL);
		head = NULL;
		while (lst)
		{
			node = ft_lstnew(f(lst->content));
			if (!node)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, node);
			lst = lst->next;
		}
		return (head);
}
