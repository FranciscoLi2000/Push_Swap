#include "libft.h"

/*
** Checks if character is valid ASCII (0-127)
** Returns 1 if true, 0 otherwise
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
