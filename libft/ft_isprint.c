#include "libft.h"

/*
** Checks if character is printable (space to ~)
** Returns 1 if true, 0 otherwise
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
