#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack		*current;
	t_stack		*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		if (current == *stack)
			break ;
	}
	*stack = NULL;
}
