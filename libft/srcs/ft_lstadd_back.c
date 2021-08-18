#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	t_list	*head;

	head = *lst;
	if (head)
	{
		last = ft_lstlast(head);
		last->next = new;
	}
	else
		*lst = new;
}
