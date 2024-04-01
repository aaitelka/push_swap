
#include "../include/push_swap.h"

t_node	*ft_new_node(int item)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->item = item;
	node->next = NULL;
	return (node);
}

void	ft_add_front(t_node **nodes, t_node *new)
{
	if (!nodes || !new)
		return ;
	new->next = *nodes;
	*nodes = new;
}

t_node	*ft_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_add_back(t_node **nodes, t_node *new)
{
	t_node	*last;

	if (!nodes || !new)
		return ;
	last = ft_last(*nodes);
	if (last)
		last->next = new;
	else
		*nodes = new;
}

void	ft_clear(t_node **nodes, void (*del)(void*))
{
	t_node	*temp;

	if (!nodes || !del)
		return ;
	while (*nodes)
	{
		temp = (*nodes)->next;
		*nodes = temp;
	}
	nodes = NULL;
}

void	ft_iterate(t_node *node, void (*f)(int))
{
	if (!node || !f)
		return ;
	while (node)
	{
		f(node->item);
		node = node->next;
	}
}
