/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include <stdlib.h>
#include "graph.h"

// graph_t graph(list_t *rooms, parse_t *parse, list_t *paths)

graph_t *create_graph(void)
{
	graph_t *graph = malloc(sizeof(graph_t));

	graph->nb_ant = 10;
	graph->nb_rooms = 4;
	graph->nb_tunnel = 5;
	graph->rooms = malloc(sizeof(rooms_graph_t) * graph->nb_rooms);
	graph->len = 3;
	for (int i = 0; i < graph->nb_rooms; i++) {
		graph->rooms[i].name = "A";
		graph->rooms[i].x = rand() % 1600;
		graph->rooms[i].y = rand() % 900;
	}
	graph->pos_start = (sfVector2f){graph->rooms[0].x, graph->rooms[0].y};
	graph->pos_end = (sfVector2f){graph->rooms[3].x, graph->rooms[3].y};
	graph->tunnels = malloc(sizeof(int *) * graph->nb_tunnel);
	for (int i = 0; i < graph->nb_tunnel; i++)
		graph->tunnels[i] = malloc(sizeof(int) * 5);
	graph->tunnels[0][0] = graph->rooms[0].x;
	graph->tunnels[0][1] = graph->rooms[0].y;
	graph->tunnels[0][2] = graph->rooms[1].x;
	graph->tunnels[0][3] = graph->rooms[1].y;
	graph->tunnels[1][0] = graph->rooms[1].x;
	graph->tunnels[1][1] = graph->rooms[1].y;
	graph->tunnels[1][2] = graph->rooms[2].x;
	graph->tunnels[1][3] = graph->rooms[2].y;
	graph->tunnels[2][0] = graph->rooms[2].x;
	graph->tunnels[2][1] = graph->rooms[2].y;
	graph->tunnels[2][2] = graph->rooms[3].x;
	graph->tunnels[2][3] = graph->rooms[3].y;
	graph->tunnels[3][0] = graph->rooms[0].x;
	graph->tunnels[3][1] = graph->rooms[0].y;
	graph->tunnels[3][2] = graph->rooms[3].x;
	graph->tunnels[3][3] = graph->rooms[3].y;
	graph->tunnels[4][0] = graph->rooms[1].x;
	graph->tunnels[4][1] = graph->rooms[1].y;
	graph->tunnels[4][2] = graph->rooms[3].x;
	graph->tunnels[4][3] = graph->rooms[3].y;
	return (graph);
}
