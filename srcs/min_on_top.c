#include "push_swap.h"

void	min_on_top(t_stack **a)
{
	t_stack		*min_node;

	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
