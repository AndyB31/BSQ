/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** header BSQ
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef BSQ
#define BSQ

//struct for the position of the biggest square
struct pos_sqrt {
	int x;
	int y;
	int scale;
};

//struct for the map
typedef struct map_info {
	int rows;
	int cols;
	char **map;
	int **i_map;
}map_t;

void map_fill(map_t *MAP, char *str);
int fs_get_number_from_first_line(char const *filepath, int *line);
void my_int_map(map_t *);
int map_len(char *pathname, map_t *);
char **alloc_2d(int, int);
void my_map(char *pathname, map_t *MAP);

#endif
