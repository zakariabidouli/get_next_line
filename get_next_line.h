
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd);
ssize_t read(int fd, void *buf, size_t count);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(const	char	*str);
char	*ft_strdup(char	*src);

#endif