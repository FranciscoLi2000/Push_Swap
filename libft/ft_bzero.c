#include "libft.h"

/*
** Zeroes memory area
** Writes n zero bytes to string s
** Uses ft_memset for implementation
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
