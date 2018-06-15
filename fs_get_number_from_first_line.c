/*
** EPITECH PROJECT, 2017
** bootstrap_bsq
** File description:
** fsopen
*/

#include "bsq.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fs_size_first_line(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char tmp[2];
	int i = 0;

	while (read(fd, tmp, 1) != 0) {
		i++;
		if (tmp[0] == '\n')
			break;
	}
	close(fd);
	return (i);
}

int fs_get_number_from_first_line(char const *filepath, int *line)
{
	int size = fs_size_first_line(filepath);
	char buffer[size + 1];
	int fd = open(filepath, O_RDONLY);
	int i = 0;
	int n = 0;

	*line = size;
	read(fd, buffer, size);
	if (size > 9)
		return (-1);
	if (size == 9 && buffer[0] > '2')
		return (-1);
	while (i < size - 1) {
		if (buffer[i] > '9' || buffer[i] < '0')
			return (-1);
		n = n * 10 + (buffer[i] - 48);
		i++;
	}
	close(fd);
	return (n);
}
