##
## EPITECH PROJECT, 2017
## Project =pname=
## File description:
## Build =pname= binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/ -g3

LIB	=	-L./lib/my/ -lmy -L./lib/list -llist

SRC	=	src/main.c				\
		src/input.c				\
		src/error_handling/file_verif.c		\
		src/error_handling/verif_name_x_y.c	\
		src/error_handling/list_verif.c		\
		src/error_handling/line_tools.c		\
		src/map/struct_inits.c			\
		src/map/room_tools.c			\
		src/map/pathfinding.c			\
		src/output/path.c

OBJ	=	$(SRC:.c=.o)

MAKE_LIBLIST	=	make -C./lib/list

MAKE_LIBMY	=	make -C./lib/my

NAME	=	lem_in

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBMY)
	$(MAKE_LIBLIST)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE_LIBMY) clean
	$(MAKE_LIBLIST) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBMY) fclean
	$(MAKE_LIBLIST) fclean

re: fclean all
