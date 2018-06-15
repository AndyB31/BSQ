/*
** EPITECH PROJECT, 2017
** allocation memorie
** File description:
** for malloc
*/

#include <stdlib.h>

//allocation of an 2d array
char **alloc_2d(int rows, int cols)
{
	char **res = malloc(sizeof(char *) * (rows + 1));

	for (int i = 0; i < rows; i++)
		res[i] = malloc(sizeof(char) * (cols + 1));
	return (res);
}