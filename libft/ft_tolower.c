#include "libft.h"

/*
** Converts uppercase letter to lowercase
** If c is uppercase, returns lowercase equivalent
** Otherwise returns c unchanged
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
