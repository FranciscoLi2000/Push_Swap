#include "push_swap.h"

t_stack		*ft_stack_new(long value)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = false;
	new->cheapest = false;
	new->target_node = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
