#include "push_swap.h"

t_stack		*find_min(t_stack *stack)
{
	t_stack		*min_node;
	t_stack		*current;
	long			min_val;

	if (!stack)
		return (NULL);
	min_val = stack->value;
	min_node = stack;
	current = stack->next;
	while (current != stack)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
