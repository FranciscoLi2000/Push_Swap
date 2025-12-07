#include "push_swap.h"

static void	push_to_empty(t_stack **dst, t_stack *node)
{
	*dst = node;
	(*dst)->next = *dst;
	(*dst)->prev = *dst;
}

static void	push_to_non_empty(t_stack **dst, t_stack *node)
{
	t_stack		*old_head;
	t_stack		*last;

	old_head = *dst;
	last = (*dst)->prev;
	node->prev = last;
	node->next = old_head;
	last->next = node;
	old_head->prev = node;
	*dst = node;
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack		*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (stack_len(*src) > 0)
	{
		(*src)->prev = node_to_push->prev;
		node_to_push->prev->next = *src;
	}
	else
		*src = NULL;
	if (!*dst)
		push_to_empty(dst, node_to_push);
	else
		push_to_non_empty(dst, node_to_push);
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (print)
		write(STDOUT_FILENO, "pb\n", 3);
}
