#include <stdio.h>

int	ft_count_word(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;

	while (*s == c)
		s++;
	while(*s)
	{
		count++;
		while(*s == c)
			s++;
		while(*s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;

	buff = malloc(sizeof(char *) * ft_count_word(s, c));
}
