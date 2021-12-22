#include "get_next_line.h"

int get_newline(char	*c)
{
	int i;

	i = 0;
	while (c[i] != '\n' && c[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	size_t			len;
	char			*buffer;
	static char		*line;

	line = ft_strdup("");
	buffer = ft_strdup("");
	if (!line)
		return NULL;
	while (get_newline(buffer))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return NULL; 
		len = read (fd, buffer, BUFFER_SIZE);
		if (len <= (size_t) get_newline(buffer))
		{	
			buffer = ft_substr(buffer, 0, get_newline(buffer));
			buffer[get_newline(buffer) + 1] = '\0';
		}
		line = ft_strjoin(line, buffer);
		line [ft_strlen(line) + 1] = '\n'; 
		line [ft_strlen(line) + 2] = '\0'; 
	}
	return (line);
}

int main ()
{
	int fd = open ("txt.txt", O_RDONLY);
	printf("[%s]",get_next_line(fd));
}


	// len_total = 0;
	// p = ft_strdup("");
	// if (!p)
	// 		return (NULL);
	// len_total = read (fd, p, sizeof (fd));
	// ptr = NULL;
	// len = 0;
	// while (++ptr)
	// {
	// 	ptr = malloc(sizeof(char) * BUFFER_SIZ);
	// 	if (!ptr)
	// 		return (NULL);
	// 	len = read (fd, ptr, (BUFFER_SIZE));

	// 	if (len != BUFFER_SIZE)
	// 		return (0); //error
	// 	if (len  (size_t) get_newline(ptr))
	// 	{	
	// 		ptr = ft_substr(ptr, 0, get_newline(ptr));
	// 		ptr[get_newline(ptr) + 1] = '\0';
	// 		break ;
	// 	}
	// }