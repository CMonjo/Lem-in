/*
** EPITECH PROJECT, 2018
** PSU_lemin_2017
** File description:
** lemin header
*/

#ifndef __LEMIN_H__
	#define __LEMIN_H__

	#include <stdio.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <fcntl.h>
	#include "my.h"

	typedef struct connection_s	connects_t;
	typedef struct room_s		room_t;
	typedef struct pos_s		pos_t;

	struct connection_s {
		room_t		*room;
		connects_t	*next;
	};

	struct pos_s {
		int	x;
		int	y;
	};

	struct room_s {
		char		*name;
		pos_t		pos;
		connects_t	*links;
	};

	int connect_room_to_room(room_t *fromRoom, room_t *toRoom);
	room_t *create_room(char *name, pos_t pos);
	void create_map();
	int verif_file(char **file);

#endif
