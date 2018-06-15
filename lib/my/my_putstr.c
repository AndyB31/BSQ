/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** put str one by one
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
