/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "lemin.h"
#include "graph.h"

graph_t graph(list_t *rooms, parse_t *parse, list_t *paths)
{
	graph_t *graph = malloc(sizeof(graph_t));

	graph->nb_ant = 10;
	graph->nb_rooms = 4;
	graph->nb_tunnel = 5;
	graph->rooms = malloc(sizeof(room_graph_t) * (graph->nb_rooms + 1));
	// graph->len = list_size(get_shortest_available_path(paths));
	graph->len = 3;
	for (int i = 0; i < graph->nb_rooms; i++) {
		graph->rooms[i].name = itoa(i);
		graph->rooms[i].x = i * 10;
		graph->rooms[i].y = i * 5;
	}
	graph->romms[graph->nb_rooms] = NULL;
	graph->connection = malloc(sizeof(int *) * graph->nb_rooms);
	for (int i = 0; i < graph->nb_rooms; i++)
		graph->nb_rooms[i] = malloc(sizeof(int) * 4);
	graph->connection[0] = {grap->rooms[0].x, grap->rooms[0].y, grap->rooms[1].x, grap->rooms[1].y};
	graph->connection[1] = {grap->rooms[1].x, grap->rooms[1].y, grap->rooms[2].x, grap->rooms[2].y};
	graph->connection[2] = {grap->rooms[2].x, grap->rooms[2].y, grap->rooms[3].x, grap->rooms[3].y};
	graph->connection[3] = {grap->rooms[3].x, grap->rooms[3].y, grap->rooms[1].x, grap->rooms[1].y};
	graph->connection[3] = {grap->rooms[2].x, grap->rooms[2].y, grap->rooms[0].x, grap->rooms[0].y};

	return (graph);
}
