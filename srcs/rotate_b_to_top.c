#include "push_swap.h"

void	rotate_b_to_top(t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node)
	{
		if (cheapest_node->above_median)
			rb(b, true);	/* Rotar hacia arriba */
		else
			rrb(b, true);	/* Rotar inversamente */
	}
}
