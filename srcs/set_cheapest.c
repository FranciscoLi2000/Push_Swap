#include "push_swap.h"

void	set_cheapest(t_stack *stack)
{
	t_stack		*cheapest_node;
	t_stack		*current;
	int				min_cost;

	if (!stack)
		return ;
	min_cost = 2147483647;
	cheapest_node = NULL;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}
