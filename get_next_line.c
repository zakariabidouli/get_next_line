#include "get_next_line.h"

int get_newline(char	*c)
{
	int i;

	i = 0;
	while (c[i] != '\n' || c[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	size_t			len;
	size_t			len_total;
	char			*ptr;
	char			*p;
	static size_t	BUFFER_SIZE;

	len_total = 0;
	len_total = read (fd, p, sizeof (fd));
	p = malloc ((sizeof(char)) * (len_total + 1));
	if (!p)
			return (NULL);
	ptr = NULL;
	len = 0;
	while (++ptr)
	{
		len = read (fd, ptr, BUFFER_SIZE);
		if (len != BUFFER_SIZE)
			return (0); //error
		ptr = malloc((sizeof(char)) * (len + 1));
		if (!ptr)
			return (NULL);
		if (len != (size_t) get_newline(ptr))
		{	
			ptr = ft_substr(ptr, 0, get_newline(ptr));
			ptr[get_newline(ptr) + 1] = '\0';
			break ;
		}
	}
	p = ft_strjoin(p, ptr); 
	return (ptr);
}

int main ()
{
	int fd = open ("txt.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}