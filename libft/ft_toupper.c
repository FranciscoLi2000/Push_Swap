#include "libft.h"

/*
** Converts lowercase letter to uppercase
** If c is lowercase, returns uppercase equivalent
** Otherwise returns c unchanged
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
