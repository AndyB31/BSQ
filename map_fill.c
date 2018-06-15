/*
** EPITECH PROJECT, 2017
** map fill
** File description:
** fill the map from char * to char **
*/

#include "bsq.h"
#include "my.h"

void map_fill(map_t *MAP, char *str)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < MAP->cols * MAP->rows; i++) {
		MAP->map[x][y++] = str[i];
		if (str[i] == '\n') {
			x++;
			y = 0;
		} else if (str[i] != 'o' && str[i] != '.')
			exit(84);
	}
}
