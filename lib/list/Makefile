##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib maker :o
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME =	liblist.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
