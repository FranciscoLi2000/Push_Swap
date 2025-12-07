#include "push_swap.h"

t_stack		*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	/* En una lista circular, el último nodo siempre es el 'prev' del primer nodo (stack). */
	return (stack->prev);
}
