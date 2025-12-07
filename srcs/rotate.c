#include "push_swap.h"

void	rotate(t_stack **head)
{
	if (!head || !*head || stack_len(*head) < 2)
		return ;
	/* En una lista circular, rotar hacia adelante
	 * simplemente significa mover el puntero head al siguiente. */
	*head = (*head)->next;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(STDOUT_FILENO, "rr\n", 3);
}
