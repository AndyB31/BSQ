##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## my_printf libmy builder
##

NAME	=	libmy.a

SRC	=	*.c

all:	$(NAME) clean

$(NAME):	$(SRC)
	gcc -c $(SRC) -I../../include/
	ar -rc $(NAME) *.o

re:	fclean all

clean:
	rm -f *.o *~ \#*\#

fclean:	clean
	rm -f $(NAME)
