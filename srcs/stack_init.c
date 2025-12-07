#include "push_swap.h"

void	stack_init(t_stack **a, char **nums)
{
	long	n;
	int		i;

	check_input(nums);
	i = 0;
	while (nums[i])
	{
		n = ft_atol(nums[i]);
		check_overflow(n, a);
		append_node(a, (int)n);
		i++;
	}
	check_duplicates(*a);
}
