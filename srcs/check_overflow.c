#include "push_swap.h"

void	check_overflow(long n, t_stack **a)
{
	if (n > 2147483647L || n < (-2147483647L - 1))
		free_errors(a);
}
