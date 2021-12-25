#include "get_next_line.h"

char *get_line(char	*buff, int	len)
{
	char *line;
	line = malloc (sizeof(char) * (len + 2));
	if (! line)
		return NULL;
	line = ft_strjoin(line, buff);
	line [len + 1] = '\0'; 
	return(line);
}

char *get_next_line(int fd)
{
	size_t		len;
	int			i;
	char		*buffer;
	static char	*line;

	i = 0;
	while(1)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return NULL; 
		len = read (fd, buffer, BUFFER_SIZE);
		i +=  len;
		buffer = ft_substr (buffer, 0, ft_strchr(buffer, '\n'));
		if ((size_t)ft_strlen(buffer) != len)
				break;
	}
	line = get_line (buffer, i);
	return (line);
}

int main ()
{
	int fd = open ("txt.txt", O_RDONLY);
	printf("[%s]\n",get_next_line(fd));
	printf("[%s]\n",get_next_line(fd));
	printf("[%s]\n",get_next_line(fd));
	printf("[%s]\n",get_next_line(fd));

}
