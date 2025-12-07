#include "push_swap.h"

void	rotate_a_to_target(t_stack **a, t_stack *target_node)
{
	while (*a != target_node)
	{
		if (target_node->above_median)
			ra(a, true);	/* Rotar hacia arriba */
		else
			rra(a, true);	/* Rotar inversamente */
	}
}
