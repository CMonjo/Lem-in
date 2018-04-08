/*
** EPITECH PROJECT, 2017
** match
** File description:
** proto
*/

#include "graph.h"
#include "struct.h"

#ifndef _PROTO_H_
	#define _PROTO_H_

	#include <SFML/Graphics.h>
	#include <SFML/Audio.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include "struct.h"

	#define SCREEN_X 1600
	#define SCREEN_Y 900

	//GRAPH
	void set_window(window_t *window);
	window_t *init_window(void);
	void event_gestion(window_t *window);

	//ANTHILL
	anthill_t *create_anthill(graph_t *graph);
	void free_anthill(anthill_t *anthill);
	void display_anthill(window_t *w, anthill_t *a, graph_t *graph);

#endif
