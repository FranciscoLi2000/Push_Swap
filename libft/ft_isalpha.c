#include "libft.h"

/*
** Checks if character is alphabetic (a-z or A-Z)
** Returns 1 if true, 0 otherwise
*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
