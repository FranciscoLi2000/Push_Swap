#include "push_swap.h"

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack		*cheapest_node;

	cheapest_node = *b;
	while (!cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median && !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	rotate_b_to_top(b, cheapest_node);
	rotate_a_to_target(a, cheapest_node->target_node);
	pa(a, b, true);
}
