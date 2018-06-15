##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## my_printf libmy builder
##

NAME	=	bsq

SRC	=	bsq.c \
		fs_get_number_from_first_line.c \
		alloc_2d.c \
		map_utils.c \
		map_fill.c

OBJ 	=	$(SRC:.c=.o)

OBJ_GDB 	=	GDB_$(SRC:.c=.o)

all:	$(NAME)

$(OBJ):
	gcc -c $(SRC) -Wall -W -Wextra -pedantic -L./lib/my -lmy -I./include/

$(OBJ_GDB):
	gcc -c $(SRC) -Wall -W -Wextra -pedantic -L./lib/my -lmy -I./include/ -g3

$(NAME):	$(OBJ)
	make re -C./lib/my/
	gcc $(OBJ) -Wall -W -Wextra -pedantic -L./lib/my -lmy -I./include/ -o $(NAME)

GDB:		$(OBJ_GDB)
	make re -C./lib/my/
	gcc $(OBJ_GDB) -Wall -W -Wextra -pedantic -L./lib/my -lmy -I./include/ -o $(NAME)_GDB -g3	

re:	fclean all

clean:
	rm -f $(OBJ) *~ \#*\#
	rm -f $(OBJ_GDB) *~ \#*\#

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)_GDB
	rm -f $(NAME)
