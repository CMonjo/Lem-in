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

typedef struct connection_s	connects_t;
typedef struct room_s		room_t;
typedef struct pos_s		pos_t;

struct connection_s {
	room_t		*room;
	connects_t	*next;
};

struct room_s {
	char			*name;
	pos_t		pos;
	connects_t	*links;
};

struct pos_s {
	int	x;
	int	y;
};

typedef struct room_s {
	char *name;
	pos_t pos;
} room_t;

#endif /* LEMIN_H_ */
