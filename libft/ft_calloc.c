#include "libft.h"

/*
** Allocates and zeroes memory
** Allocates count * size bytes, initializes to zero
** Returns pointer to allocated memory, NULL on failure
** Caller must free returned memory
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
