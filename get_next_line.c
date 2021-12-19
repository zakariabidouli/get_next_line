#include "get_next_line.h"
#include <fcntl.h>
int get_newline(char	c)
{
	int i;

	i = 0;
	while (c != '\n')
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	int it;
	int i;
	int len;
	char *ptr;
	static size_t BUFFER_SIZE;

	it = 0;
	while (++it)
	{
		len = read (fd, ptr, BUFFER_SIZE);
		ptr = malloc((sizeof(char)) * (len+ 1));
		if (!ptr)
			return (NULL);
		while (ptr[len])
		{
			i = get_newline(ptr[len]);
			if (!i)
				len--;
			else
				ptr[i + 1] = '\0'; 
		}
	}
	return (ptr);
}


int main ()
{
	int x;
	int fd = open ("txt.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}