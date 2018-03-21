##
## EPITECH PROJECT, 2017
## Project =pname=
## File description:
## Build =pname= binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/ -g3

LIB	=	-L lib/my/ -lmy

SRC	=	src/main.c			\
		src/map/input.c			\
		src/map/error_handling.c	\
		src/map/struct_inits.c		\
		src/map/verif_name_x_y.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
