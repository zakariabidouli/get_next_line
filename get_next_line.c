#include "get_next_line.h"

int get_newline(int fd)
{
	int i;
	char c;

	i = 0;
	while ( c == )
		if (c == "\n")
			return(0);
		i++;
	}
	return (i);
}

char *get_next_line(int fd)
{
	static int 	count;
	int it;
	int len;
	char *ptr;
	
	count = 0;
	while (++count)
	{
		len = get_newline(fd);
		ptr = malloc((sizeof(char)) * (len + 2));
		if (!ptr)
			return (NULL);
		it = 0;
		substr()
	}
	return (ptr);
}