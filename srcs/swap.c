#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack		*first;
	t_stack		*second;
	t_stack		*last;

	if (!head || !*head || stack_len(*head) < 2)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	/* 1. Reenlazar el último nodo al segundo */
	last->next = second;
	second->prev = last;
	/* 2. Reenlazar el segundo nodo al primero */
	first->next = second->next;
	first->prev = second;
	/* 3. Reenlazar el resto al primero */
	first->next->prev = first;
	/* 4. Hacer que el segundo sea el nuevo head */
	second->next = first;
	*head = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(STDOUT_FILENO, "ss\n", 3);
}
