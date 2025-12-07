#include "push_swap.h"

static char	**split_single_arg(t_stack **a, char *str)
{
	char	**split_args;

	if (!str || !*str)
		free_errors(a);
	split_args = ft_split(str, ' ');
	if (!split_args)
		free_errors(a);
	return (split_args);
}

/* 1. Manejo de Argumentos
 *  No hay argumentos, salir silenciosamente
 * 2. Inicialización de Pilas y Validación de Input
 *  Llama a stack_init, que se encarga de:
 *   a) check_input (Formato)
 *   b) check_overflow (Rango de INT)
 *   c) append_node (Construir la pila A)
 *   d) check_duplicates (Duplicados)
 *  Si hay un error, free_errors(&a) se llama internamente y el programa termina.
 * 3. Chequeo de Pila ya Ordenada
 * 4. Normalización de Datos
 *  Reemplaza los valores reales por índices de 1 a N.
 * 5. Ejecución del Algoritmo
 *  La función maestra que elige la estrategia:
 *   - sort_three o sort_small (si N <= 5)
 *   - move_a_to_b + Greedy (si N > 5)
 * 6. Limpieza de Memoria */

static void	handle_input_and_init(int argc, char **argv, t_stack **a)
{
	char	**nums;
	char	**to_free;
	int		i;

	to_free = NULL;
	if (argc == 2)
	{
		nums = split_single_arg(a, argv[1]);
		to_free = nums;
	}
	else
		nums = argv + 1;
	stack_init(a, nums);
	if (to_free)
	{
		i = 0;
		while (to_free[i])
			free(to_free[i++]);
		free(to_free);
	}
}

static void	execute_sorting_logic(t_stack **a, t_stack **b)
{
	if (stack_sorted(*a))
	{
		free_stack(a);
		return ;
	}
	if (*a)
	{
		normalize_stack(*a);
		sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	/* 1. Chequeo de caso base */
	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	/* 2. Inicialización (maneja validación, split y free */
	handle_input_and_init(argc, argv, &a);
	/* 3. Ejecución del algoritmo y chequeo final */
	execute_sorting_logic(&a, &b);
	/* 4. Limpieza final (si free_stack no fue llamado en execute_sorting_logic) */
	free_stack(&a);
	return (0);
}
