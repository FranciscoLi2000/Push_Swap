#include "libft.h"

/*
** Calculates length of string
** Iterates until null terminator found
** Returns number of characters before null terminator
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
