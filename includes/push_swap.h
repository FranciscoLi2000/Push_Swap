#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	long	value;				/* El número a ordenar */
	int			index;		/* Su posición actual en el stack (cero a n) */
	int			push_cost;	/* Costo total calculado para mover este nodo */
	bool			above_median;	/* ¿Está en la mitad superior o inferior? (Para decidir ra o rra) */
	bool			cheapest;	/* Flag para marcar el nodo más barato de mover */
	struct s_stack	*target_node;		/* Puntero al nodo \"objetivo\" en el otro stack */
	struct s_stack	*next;			/* Puntero al siguiente */
	struct s_stack  *prev;			/* Puntero al anterior (vital para rra/rrb) */
}	t_stack;

/* Gestión de Memoria y Lista (Libft extendida)
 * Estas funciones gestionan la estructura en sí misma, ignorando la lógica de ordenamiento. */
/* Inicialización y Utilidades */
/* void		stack_init(t_stack **a, char **argv, bool split_argc);	 Maneja input normal y \"string\" */
t_stack		*ft_stack_new(long value);
void		free_stack(t_stack **stack);
void		free_errors(t_stack **a);				/* Libera y muestra \"Error\" */
/* Manipulación de Nodos */
t_stack		*find_last(t_stack *stack);				/* Necesario para conectar el círculo */
t_stack		*find_min(t_stack *stack);				/* Encuentra el valor mínimo (útil para el ajuste final) */
t_stack		*find_max(t_stack *stack);				/* Encuentra el máximo */
int			stack_len(t_stack *stack);			/* Cuenta nodos */
void		append_node(t_stack **stack, int n);			/* Añade al final */
/* Las Operaciones Obligatorias (The Mechanics)
 * El subject es estricto aquí. Es recomendable tener una función genérica y \"wrappers\" que impriman la instrucción.
 * Esto te permite usar la lógica silenciosamente si quisieras simular movimientos futuros. */
/* Operaciones Genéricas (no imprimen, solo mueven punteros) */
void		push(t_stack **dst, t_stack **src);
void		swap(t_stack **head);
void		rotate(t_stack **head);
void		reverse_rotate(t_stack **head);
/* Operaciones Push_swap (imprimen y llaman a las genéricas) */
void		pa(t_stack **a, t_stack **b, bool print);
void		pb(t_stack **b, t_stack **a, bool print);
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b, bool print);
void		ra(t_stack **a, bool print);
void		rb(t_stack **b, bool print);
void		rr(t_stack **a, t_stack **b, bool print);
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b, bool print);
/* El Algoritmo: Greedy Sort con Cálculo de Costos
 * Este es el núcleo. En lugar de un algoritmo con nombre clásico (como QuickSort), usarás un enfoque heurístico: 
 * \"Mueve siempre el nodo que requiera menos operaciones totales para colocarse en su posición correcta\".
 * Fase A: Análisis y Preparación
 * Antes de mover nada, necesitamos actualizar los metadatos de los nodos. */
/* Actualización de estado */
void		current_index(t_stack *stack);			/* Actualiza index y above_median para todos */
void		set_target_a(t_stack *a, t_stack *b);		/* Para cada nodo en B, ¿cuál es su lugar en A? */
void		cost_analysis_a(t_stack *a, t_stack *b);	/* Calcula cuántos ra/rb/rra/rrb cuesta mover cada nodo */
void		set_cheapest(t_stack *stack);			/* Marca el nodo con el coste mínimo */
/* Fase B: Ejecución del Movimiento
 * Una vez identificado el nodo \"barato\", hay que mover ambos stacks para prepararle el sitio. */
/* Movimiento inteligente */
void		move_a_to_b(t_stack **a, t_stack **b);		/* Lógica principal para enviar a B (pre-sort) */
void		move_b_to_a(t_stack **a, t_stack **b);		/* Lógica principal para devolver a A (ordenado) */
/* Optimizador de rotación doble */
/* Si ambos stacks necesitan rotar en la misma dirección, usa rr o rrr */
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
/* Finalización */
/* Asegura que el número menor esté al principio del stack A al terminar */
void		min_on_top(t_stack **a);
/* Control Principal (Main Flow)
 * Funciones para manejar los casos pequeños (hardcodeados) vs el algoritmo general. */
/* Algoritmos de ordenamiento */
bool			stack_sorted(t_stack *stack);		/* Check si ya está ordenado */
void		sort_three(t_stack **a);			/* Caso base: 3 números */
void		sort_stacks(t_stack **a, t_stack **b);		/* El algoritmo Greedy completo */
/* Util functions */
void		check_input(char **argv);
long		ft_atol(const char *str);
void		check_overflow(long n, t_stack **a);
void		check_duplicates(t_stack *a);
void		rotate_b_to_top(t_stack **b, t_stack *cheapest_node);
void		rotate_a_to_target(t_stack **a, t_stack *target_node);
void		stack_init(t_stack **a, char **nums);
void		normalize_stack(t_stack *a);

#endif
