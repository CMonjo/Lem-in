/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** lemin header
*/

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
		int **connection;
		rooms_graph_t *rooms;
	} graph_t;

	graph_t *create_graph(void);
#endif
