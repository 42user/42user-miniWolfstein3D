#include "cub3d.h"

static void	check_for_remainder(t_list *head)
{
	while (head)
	{
		if (*((char *)(head->content)) != '\0')
		{
			g_error = 4;
			return ;
		}
		head = head->next;
	}
}

static int	looks_like_map(void *content)
{
	char			c;

	c = *((char *)content);
	if ((c == '1') || (c == ' '))
		return (1);
	return (0);
}

int	valid_list(t_parsed *parsed, t_list *lst)
{
	t_list			*head;

	head = lst;
	valid_params(&head, parsed);
	if (!g_error)
	{
		while (head && (*((char *)(head->content)) == '\0'))
			head = head->next;
		if (head == NULL)
			g_error = 7;
		if ((!g_error) && (looks_like_map(head->content)))
			valid_map(&head, parsed);
		else if (!g_error)
			g_error = 5;
		if (!g_error)
			check_for_remainder(head);
	}
	if (g_error || errno)
	{
		free_parsed(parsed);
		return (-1);
	}
	return (0);
}
