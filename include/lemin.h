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

typedef struct room_s	room_t;
typedef struct pos_s	pos_t;
typedef struct path_s	path_t;
typedef struct file_s	file_t;
typedef struct parse_s	parse_t;
typedef enum type_s		type_t;

enum type_s {
	START=1,
	MIDDLE=0,
	END=2
};

struct pos_s {
	int	x;
	int	y;
};

struct room_s {
	int		occuped;
	char		*name;
	int		nblinks;
	type_t	type;
	pos_t	pos;
	list_t	*links;
};

struct file_s {
	room_t *room;
	char	*name;
	type_t type;
	pos_t	pos;
	file_t	*next;
};

struct parse_s {
	int nb_ant;
	int start;
	int end;
	int type;
};

struct path_s {
	list_t	*rooms;
	int nbrooms;
};

//MAP
room_t *create_room(char *name, pos_t pos, type_t type);

//ROOM GETTER
room_t *get_start_room(list_t *map);
room_t *get_end_room(list_t *map);

//PATHFINDING
list_t *get_all_paths(list_t **paths, list_t *act, room_t *to, room_t *end);
list_t *get_shortest_available_path(list_t *paths);

//ERROR HANDLING
//main parsing
int create_map(list_t **rooms, parse_t *parse);

//line tools
int	line_is_comment(char *line);
char *my_clear_str(char *str);
char *my_improved_strcat(char *dest, char *src);
room_t *get_room_from_name(list_t *rooms, char *name);
int check_dash(char **input, int i);

int compare_connections(list_t *rooms, char **input, int in);
list_t *get_shortest_available_path(list_t *paths);

int compare_connexions(file_t *file, char **);
void connect_rooms(char **input);
int count_rooms(char **input);
void link_rooms(room_t **room, char **input, int i);
int create_rooms(room_t **room, char **input);
path_t	*get_path_between(room_t *src, room_t *dest);
int move_j(char **input, int i, int j);
char *recup_name(char **input, int i, int j, char *name);
int recup_x(char **input, int i, int j);
int recup_y(char **input, int i, int j);
int verif_room_name(list_t **, parse_t *parse, char **input, int i);
int connect_room_to_room(room_t *from_room, room_t *to_room);
int parsing_file_input(list_t **, parse_t *parse, char **input, int begin);
void create_file_element(list_t **, pos_t pos, char *name, int enum_type);
int compare_names(list_t *);
int compare_positions(list_t *rooms);
void print_link(list_t *);
int verif_file(list_t **, parse_t *parse, char **input);
void display_output(list_t *rooms, parse_t *parse);

//OUTPUT
void display_output_path(list_t *list_path, int len, int ants);

#endif /* LEMIN_H_ */
