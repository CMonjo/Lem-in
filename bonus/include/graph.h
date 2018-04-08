/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** lemin header
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef _GRAPH_H_
#define _GRAPH_H_

	typedef struct rooms_graph_s {
		char *name;
		int x;
		int y;
	} rooms_graph_t;

	typedef struct graph_s {
		int nb_ant;
		int nb_rooms;
		int nb_tunnel;
		int len;
		int **tunnels;
		sfVector2f pos_start;
		sfVector2f pos_end;
		rooms_graph_t *rooms;
		char ***moves;
	} graph_t;

	graph_t *create_graph(void);
#endif
