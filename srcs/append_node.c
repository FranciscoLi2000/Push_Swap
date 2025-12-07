#include "push_swap.h"

void		append_node(t_stack **stack, int n)
{
	t_stack		*new_node;
	t_stack		*last;

	new_node = ft_stack_new((long)n);
	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = *stack;
		new_node->prev = *stack;
	}
	else
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}
