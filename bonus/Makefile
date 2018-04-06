##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

CC		=	gcc

SRC		= 	./src/main.c		\
			./src/window/event.c	\
			./src/window/init.c	\
			./src/anthill/create.c	\
			./src/anthill/display.c	\
			./src/anthill/free.c


OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -g3 -I ./include

LIB		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

NAME		=	bonus

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
