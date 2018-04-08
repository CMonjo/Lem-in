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

	graph->nb_ant = parse->nb_ant;
	graph->nb_rooms = 4;
	graph->nb_tunnel = 5;
	// graph->len = list_size(get_shortest_available_path(paths));
	graph->len = 3;
	return (graph);
}
