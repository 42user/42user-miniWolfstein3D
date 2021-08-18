#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*head;
	t_list		*tmp;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
