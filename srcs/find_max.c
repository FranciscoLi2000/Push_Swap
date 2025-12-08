#include "push_swap.h"

t_stack		*find_max(t_stack *stack)
{
	t_stack		*max_node;
	t_stack		*current;
	long			max_val;

	if (!stack)
		return (NULL);
	max_val = stack->value;
	max_node = stack;
	current = stack->next;
	while (current != stack)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}
