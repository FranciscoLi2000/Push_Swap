#include "push_swap.h"

static int	is_valid_digit(char c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-');
}

void	check_input(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			free_errors(NULL);
		while (argv[i][j])
		{
			if (!is_valid_digit(argv[i][j]))
				free_errors(NULL);
			j++;
		}
		i++;
	}
}
