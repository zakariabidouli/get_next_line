#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int 	count;
	char c;
	char *ptr;
	
	count = 0;
	while (++count)
	{
		c = read(fd, sizeof(char), 1);
		if(c == "\n" || !c)
			break;
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[count] = c; 
	}
	return (ptr);
}