#include "libft.h"

/*
** Outputs character to file descriptor
** Writes character c to given file descriptor
** No return value
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
