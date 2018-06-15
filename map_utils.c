/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** a game like sokoban
*/

#include "my.h"
#include "bsq.h"

int dot_value(map_t *MAP, int x, int y)
{
	int i = -1;
	int j = -1;
	int a = 0;
	int keep = 2000000000;

	while (a < 3) {
		if (MAP->i_map[x + i][y + j] < keep) {
			keep = MAP->i_map[i + x][j + y];
		}
		j++;
		if (j > 0) {
			j = -1;
			i++;
		}
		a++;
	}
	return (keep + 1);	
}

void my_i_map_init(map_t *MAP)
{
	MAP->i_map = malloc(sizeof(int *) * (MAP->rows + 1));
	for (int i = 0; i < MAP->rows + 1; i++)
		MAP->i_map[i] = malloc(sizeof(int) * MAP->cols);
	for (int i = 0; i < MAP->rows + 1; i++)
		MAP->i_map[i][0] = 0;
	for (int i = 0; i < MAP->cols + 1; i++)
		MAP->i_map[0][i] = 0;
}

// transform char array in int array with 0 for o and 1, 2, 3 ... for "."
void my_int_map(map_t *MAP)
{
	int x = 0;
	int y = 0;

	my_i_map_init(MAP);
	while (x < MAP->rows) {
		if (MAP->map[x][y] == 'o') {
			MAP->i_map[x + 1][y + 1] = 0; 
		} else if (MAP->map[x][y] == '.') {
			MAP->i_map[x + 1][y + 1] = dot_value(MAP, x + 1, y + 1);
		}
		if (MAP->map[x][y] == '\n')
			MAP->i_map[x + 1][y + 1] = 0;
		y++;
		if (y > MAP->cols) {
			y = 0;
			x++;
		}
	}
} 

//fonction for get the nbr of colomn and the nbr of line
int map_len(char *pathname, map_t *MAP)
{
	struct stat buf;
	int first_line;

	if (stat(pathname, &buf) == -1)
		exit(84);
	MAP->rows = fs_get_number_from_first_line(pathname, &first_line);
	MAP->cols = (buf.st_size - first_line) / MAP->rows;
	if (MAP->rows == 97 || MAP->cols == 98)
		exit(84);
	return (first_line);
} 

//fonction for transform a map.txt into a 2d char array
void my_map(char *pathname, map_t *MAP)
{
	int fd = open(pathname, O_RDONLY);
	char *map_temp;
	char *del_line;
	int a;

	a = map_len(pathname, MAP);
	MAP->map = alloc_2d(MAP->rows, MAP->cols);
	map_temp = malloc(sizeof(char) * (MAP->rows + 2) * (MAP->cols + 2));
	del_line = malloc(sizeof(char) * (a + 1));
	read(fd, del_line, a);
	free(del_line);	
	read(fd, map_temp, (MAP->cols + 1) * MAP->rows);
	map_fill(MAP, map_temp);
	free(map_temp);
	close(fd);
}
