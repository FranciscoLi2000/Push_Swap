#include "push_swap.h"

void	normalize_stack(t_stack *a)
{
	t_stack		*current;
	t_stack		*min_node;
	int				len;
	int				index_rank;
	long			min_val;

	len = stack_len(a);
	index_rank = 1;
	while (index_rank <= len)
	{
		min_val = 2147483648L;
		min_node = NULL;
		current = a;
		while (current)
		{
			if (current->value < min_val && current->index == 0)
			{
				min_val = current->value;
				min_node = current;
			}
			current = current->next;
			if (current == a)
				break ;
		}
		if (min_node)
			min_node->index = index_rank;
		index_rank++;
	}
}
