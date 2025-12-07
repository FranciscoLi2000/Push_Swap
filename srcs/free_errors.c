#include "push_swap.h"

void	free_errors(t_stack **a)
{
	free_stack(a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
