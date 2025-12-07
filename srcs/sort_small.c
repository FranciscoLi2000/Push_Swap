#include "push_swap.h"

void	sort_small(t_stack **a, t_stack **b)
{
	int		len;

	len = stack_len(*a);
	while (len > 3)
	{
		if ((*a)->value == find_min(*a)->value)
			pb(b, a, true);
		else
			ra(a, true);
		len--;
	}
	sort_three(a);
	pa(a, b, true);
	if (stack_len(*a) == 5)
		pa(a, b, true);
}
