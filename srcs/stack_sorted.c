#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	t_stack		*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
