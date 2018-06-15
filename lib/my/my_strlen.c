/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** lenght of a strinf
*/

int my_strlen(char const *str)
{
	int f = 0;

	while (str[f] != '\0') {
		f = 1 + f;
	}
	return (f);
}
