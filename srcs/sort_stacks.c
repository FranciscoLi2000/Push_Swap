#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len;

	len = stack_len(*a);
	if (len <= 3)
	{
		sort_three(a);
		return ;
	}
	while (len > 3 && !stack_sorted(*a))
	{
		if (len > 3 && (*a)->index <= len - 3)
			pb(b, a, true);
		else
			ra(a, true);
		len = stack_len(*a);
	}
	if (!stack_sorted(*a))
		sort_three(a);
	while (*b)
	{
		current_index(*a);
		current_index(*b);
		set_target_a(*a, *b);
		cost_analysis_a(*a, *b);
		set_cheapest(*b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
