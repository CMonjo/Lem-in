/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/System/Vector2.h>
	#include <SFML/Audio.h>
	#include <ncurses.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <math.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <fcntl.h>
	#include "my.h"
	#include "printf.h"

	typedef struct room_s {
		char *name;
		int x;
		int y;
	} room_t;

	typedef struct anthill_s {
		int ants;
		room_t *room;
		char **tunnels;
	} anthill_t;

	anthill_t *manage_input();
	int verif_file(anthill_t *anthill, char **file);
#endif
