#include "libft.h"

/*
** Applies function to each character with index
** Creates new string from applying f to each char of s
** f receives character index and character itself
** Returns newly allocated string, NULL on malloc failure
** Caller must free returned string
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
