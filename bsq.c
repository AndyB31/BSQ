/*
** EPITECH PROJECT, 2017
** BSQ_main
** File description:
** the main file of bsq
*/

#include "bsq.h"
#include "my.h"

//condition for test if x or y is in the square
int condition(int x, int y, struct pos_sqrt *pos)
{
	if (!(x >= pos->x - pos->scale && x < pos->x))
		return (0);
	if (!(y >= pos->y - pos->scale && y < pos->y))
		return (0);
	return (1);
}

//find in a int map the biggest int
void find_big_square(map_t *MAP, struct pos_sqrt *pos)
{
	int x = 1;
	int y = 1;
	
	pos->scale = 0;
	while (x < MAP->rows + 1) {
		if (MAP->i_map[x][y] > pos->scale) {
			pos->scale = MAP->i_map[x][y];
			pos->x = x;
			pos->y = y;
		}
		y++;
		if (y > MAP->cols) {
			y = 1;
			x++;
		}
	}
}

//free all the malloc ressources
void free_all(struct pos_sqrt *pos, map_t *MAP, char *result)
{
	free(result);
	free(pos);
	free(MAP);
}

//fill a string for print the result with one write;
void my_fill_result(map_t *MAP, struct pos_sqrt *pos, char *result)
{
	int x = 0;
	int y = 0;
	int i = 0;

	while (x < MAP->rows) {
		if (condition(x, y, pos) == 1) {
			result[i] = 'x';
		} else
			result[i] = MAP->map[x][y];	
		y++;
		i++;
		if (y >= MAP->cols) {
			y = 0;
			x++;
		}
	}
	result[i] = '\0';
}

int main(int ac, char **av)
{
	map_t *MAP = malloc(sizeof(map_t));
	struct pos_sqrt *pos = malloc(sizeof(struct pos_sqrt) * 2);
	char *result;

	if (ac != 2) {
		write(2, "error: bad number of arguments", 31);
		return (84);
	}
	my_map(av[1], MAP);
	my_int_map(MAP);
	find_big_square(MAP, pos);
	result = malloc(sizeof(char) * (MAP->cols + 1) * (MAP->rows + 1));
	if (result == NULL)
		return (84);
	my_fill_result(MAP, pos, result);
	write(1, result, my_strlen(result));
	free(MAP);
	free(pos);
	return (0);
}
