#include "libft.h"

/*
** Outputs string with newline to file descriptor
** Writes string s followed by newline to given file descriptor
** No return value
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
