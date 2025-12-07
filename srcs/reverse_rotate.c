#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	if (!head || !*head || stack_len(*head) < 2)
		return ;
	/* En una lista circular, rotar hacia atrás
	 * simplemente significa mover el puntero head al anterior (prev). */
	*head = (*head)->prev;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(STDOUT_FILENO, "rrr\n", 4);
}
