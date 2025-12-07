#include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	len = stack_len(*a);
	i = 0;
	while (len > 3)
	{
		if ((*a)->index >= len - 2)
			ra(a, true);
		else
			pb(b, a, true);
		len = stack_len(*a);
		i++;
	}
}
