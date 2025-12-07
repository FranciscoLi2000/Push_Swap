#include "push_swap.h"

t_stack		*find_min(t_stack *stack)
{
	t_stack		*min_node;
	t_stack		*current;
	long			min_val;

	if (!stack)
		return (NULL);
	min_val = 2147483648;
	min_node = NULL;
	current = stack;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_node = current;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
	return (min_node);
}
