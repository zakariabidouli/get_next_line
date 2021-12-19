#include "get_next_line.h"

int get_newline(char*	c)
{
	int i;

	i = 0;
	while (c[i] != '\n' || c[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	int it;
	int end;
	int start;
	int len;
	char *ptr;
	char *p;
	static size_t BUFFER_SIZE;

	it = 0;
	end = 0;
	start = 0;
	while (++ptr)
	{
		len = read (fd, ptr, BUFFER_SIZE);
		if (len != BUFFER_SIZE)
			return (0); //error
		ptr = malloc((sizeof(char)) * (len + 1));
		if (!ptr)
			return (NULL);
		if (get_newline(ptr))
			end = get_newline(ptr);
		// else
		// 	ptr = ft_substr(ptr, 0, end); 
	}
	return (ptr);
}


int main ()
{
	int x;
	int fd = open ("txt.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}