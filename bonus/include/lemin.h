/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
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
	typedef struct connection_s	connection_t;
	typedef struct parse_s	parse_t;
	typedef enum type_s	type_t;

	enum type_s {
		START = 1,
		MIDDLE = 0,
		END = 2
	};

	struct pos_s {
		int x;
		int y;
	};

	struct room_s {
		int occuped;
		char *name;
		int nblinks;
		type_t type;
		pos_t pos;
		list_t *links;
	};

	struct connection_s {
		char *to_room;
		char *from_room;
	};

	struct parse_s {
		int nb_ant;
		int start;
		int end;
		int type;
		list_t *connect;
	};

	struct path_s {
		list_t *rooms;
		int nbrooms;
	};

	//ROOM GETTER
	room_t *get_start_room(list_t *map);
	room_t *get_end_room(list_t *map);
	path_t	*get_path_between(room_t *src, room_t *dest);
	list_t *get_shortest_available_path(list_t *paths);

	//ROOM CONNECT
	int connect_room_to_room(room_t *from_room, room_t *to_room);
	int compare_positions(list_t *rooms);

	//PATHFINDING
	int get_all_paths(list_t **paths, list_t *act, room_t *to, room_t *end);
	list_t *get_shortest_available_path(list_t *paths);

	//FILL INPUT
	int create_map(list_t **rooms, parse_t *parse);
	room_t *create_room(char *name, pos_t pos, type_t type);

	//ERROR HANDLING
	int verif_file(list_t **, parse_t *parse, char **input);
	int parsing_file_input(list_t **, parse_t *parse, char **input, int begin);
	int compare_connects(list_t *rooms, parse_t *parse, char **input, int in);
	int compare_connections(list_t *rooms, parse_t *parse, char **input, int in);
	int verif_room_name(list_t **, parse_t *parse, char **input, int i);
	int compare_names(list_t *);

	//LINE TOOLS
	int line_is_comment(char *line);
	char *my_clear_str(char *str);
	char *my_improved_strcat(char *dest, char *src);
	room_t *get_room_from_name(list_t *rooms, char *name);
	int check_dash(char **input, int i);

	//OUTPUT
	void display_output_path(list_t *list_path, int len, int ants);
	void display_output(list_t *rooms, parse_t *parse);
#endif /* LEMIN_H_ */
