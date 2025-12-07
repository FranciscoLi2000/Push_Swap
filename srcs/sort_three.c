#include "push_swap.h"

void	sort_three(t_stack **a)
{
	long	x;
	long	y;
	long	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->prev->value;
	if (x < y && y > z && x < z)
		ra(a, true);
	else if (x > y && y < z && x < z)
		sa(a, true);
	else if (x < y && y > z && x > z)
		rra(a, true);
	else if (x > y && y < z && x > z)
		ra(a, true);
	else if (x > y && y > z)
	{
		sa(a, true);
		rra(a, true);
	}
}
