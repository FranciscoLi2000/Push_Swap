#include "push_swap.h"

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	t_stack		*current_b;
	int				len_a;
	int				len_b;
	int				cost_a;
	int				cost_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current_b = b;
	while (current_b)
	{
		if (current_b->above_median)
			cost_b = current_b->index;				/* Usar rb */
		else
			cost_b = len_b - current_b->index;			/* Usar rrb */
		if (current_b->target_node->above_median)
			cost_a = current_b->target_node->index;			/* Usar ra */
		else
			cost_a = len_a - current_b->target_node->index;		/* Usar rra */
		current_b->push_cost = cost_a + cost_b;
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}
