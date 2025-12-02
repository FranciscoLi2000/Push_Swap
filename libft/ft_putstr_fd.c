#include "libft.h"

/*
** Outputs string to file descriptor
** Writes string s to given file descriptor
** No return value
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
