#include "get_next_line.h"


char *get_next_line(int fd)
{
	size_t			len;
	char			*buffer;
	static char		*line;

	line = ft_strdup("");
	while(1)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return NULL; 
		len = read (fd, buffer, BUFFER_SIZE);
		buffer = ft_strchr(buffer, '\n');
		if (buffer)
		{
			line = ft_strjoin(line, buffer);
			line [ft_strlen(line) + 2] = '\0'; 
		}
		else 
			break;
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