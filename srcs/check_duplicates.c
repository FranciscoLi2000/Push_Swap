#include "push_swap.h"

void	check_duplicates(t_stack *a)
{
	t_stack		*current;
	t_stack		*runner;

	current = a;
	while (1)
	{
		runner = current->next;
		while (runner != a)
		{
			if (current->value == runner->value)
				free_errors(&a);
			runner = runner->next;
		}
		current = current->next;
		if (current == a)
			break ;
	}
}
