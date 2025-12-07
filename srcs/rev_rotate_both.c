#include "push_swap.h"

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b, true);
	current_index(*a);	/* Re-indexar después de rrr */
	current_index(*b);	/* Re-indexar después de rrr */
}

