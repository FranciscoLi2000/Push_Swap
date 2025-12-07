#include "push_swap.h"

void	current_index(t_stack *stack)
{
	t_stack		*current;
	int			len;
	int			median;
	int			i;

	if (!stack)
		return ;
	len = stack_len(stack);
	median = len / 2;
	i = 0;
	current = stack;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		i++;
		current = current->next;
		if (current == stack)
			break ;
	}
}
