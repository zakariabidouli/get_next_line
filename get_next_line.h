
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
ssize_t read(int fd, void *buf, size_t count);