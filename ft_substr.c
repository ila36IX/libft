#include "libft.h"

static int	alloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	if (!s)
		return (-1);
	size = 0;
	while (s[size])
		size++;
	if (size <= start)
		return (-1);
	if (size - start > len)
		return (len);
	else
		return (size - start + 1);

}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;
	int	alloc_s;

	alloc_s = alloc_size(s, start, len);
	if (alloc_s <= 0)
		return (ft_strdup(""));
	buff = malloc(sizeof(char) * alloc_s);
	if (!buff)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		buff[i++] = s[start++];
	buff[i] = '\0';
	return (buff);
}