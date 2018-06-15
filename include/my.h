/*
** EPITECH PROJECT, 2017
** my
** File description:
** all the declaration
*/

#include <stdlib.h>
#include <stdio.h>

#ifndef VAR
#define VAR

int my_printf(char *format, ...);
char *int_to_octastr(unsigned long number, int len);
int my_print_str(char *);
int power(int i);
int longlen(unsigned long number);
void hexaprint(unsigned long number, char maj);
void octaprint(unsigned long number);
void binprint(unsigned long number);
void my_put_pt(void *pt);
int my_testneg(char *str, int i);
char *init(char *str);
char *my_replace(char *str, int i, int max, int res);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_unbr(unsigned int nb);
int my_put_lnbr(long nb);
int my_put_lunbr(unsigned long nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_get_nbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_shownem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strbcat(char *dest, char const *src, int nb);

typedef struct arg arg;
struct arg
{
	int id;
	char flag;
	arg *next;
};

#endif
