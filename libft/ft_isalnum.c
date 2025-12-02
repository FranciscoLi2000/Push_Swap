#include "libft.h"

/*
** Checks if character is alphanumeric (a-z, A-Z, or 0-9)
** Returns 1 if true, 0 otherwise
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
