/*
** EPITECH PROJECT, 2018
** PSU_lemin_2017
** File description:
** lemin header
*/

#ifndef __LEMIN_H__
#define __LEMIN_H__

#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "list.h"

typedef struct connection_s	connects_t;
typedef struct room_s		room_t;
typedef struct pos_s		pos_t;
typedef struct path_s		path_t;
typedef struct file_s		file_t;
typedef enum type_s		type_t;

enum type_s {
	START,
	MIDDLE,
	END
};

struct connection_s {
	room_t		*room;
	connects_t	*next;
};

struct pos_s {
	int	x;
	int	y;
};

struct room_s {
	int		occuped;
	char		*name;
	pos_t		pos;
	int		nblinks;
	connects_t	*links;
};

struct file_s {
	char	*name;
	type_t type;
	pos_t	pos;
	file_t	*next;
};

struct path_s {
	room_t	*room;
	path_t	*next;
};

void create_map(void);
void connect_rooms(char **input);
int count_rooms(char **input);
void link_rooms(room_t **room, char **input, int i);
int create_rooms(room_t **room, char **input);
path_t	*get_path_between(room_t *src, room_t *dest);
int move_j(char **input, int i, int j);
char *recup_name(char **input, int i, int j, char *name);
int recup_x(char **input, int i, int j);
int recup_y(char **input, int i, int j);
int verif_room_name(file_t **file, char **input, int i, int enum_type);
room_t *create_room(char *name, pos_t pos);
int	connect_room_to_room(room_t *from_room, room_t *to_room);
room_t	*get_first_unused_room_from_room(room_t *from_room);
int parsing_file_input(file_t **file, char **input);
void create_file_element(file_t **file, pos_t pos, char *name, int enum_type);
int compare_names(file_t *file);
int compare_positions(file_t *file);
void print_link(file_t *file);
int verif_file(char **input);

#endif /* LEMIN_H_ */
