#include "push_swap.h"

int			stack_len(t_stack *stack)
{
	t_stack		*current;
	int			count;

	if (!stack)
		return (0);
	count = 0;
	current = stack;
	while (1)
	{
		count++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (count);
}
