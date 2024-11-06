#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	*ft_memmove(void *dest, const void *src, size_t n);
int	ft_isalpha(int c);
int	ft_isprint(int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);

