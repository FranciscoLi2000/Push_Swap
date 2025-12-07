#include "push_swap.h"

static t_stack	*find_target_node(t_stack *a, long b_value)
{
	t_stack		*target_node;
	t_stack		*current_a;
	long			best_match_val;

	best_match_val = 2147483648L;
	target_node = NULL;
	current_a = a;
	while (current_a)
	{
		if (current_a->value > b_value && current_a->value < best_match_val)
		{
			best_match_val = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
		if (current_a == a)
			break ;
	}
	if (target_node == NULL)
		target_node = find_min(a);
	return (target_node);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*current_b;

	if (!a || !b)
		return ;
	current_b = b;
	while (current_b)
	{
		current_b->target_node = find_target_node(a, current_b->value);
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}
