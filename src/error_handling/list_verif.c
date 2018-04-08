/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

int compare_connections(list_t *rooms, parse_t *parse, char *input, int i)
{
	list_t *tmp = rooms;
	room_t *room = NULL;
	char **connect = my_str_split(input, '-');

	for (;connect[i] != NULL; i++);
	if (i != 2) {
		parse->error_parse = 1;
		return (84);
	}
	for (i = 0; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (my_strcmp(connect[0], room->name) == 1
		|| my_strcmp(connect[1], room->name) == 1)
			i += 1;
	}
	return (fill_connection(rooms, parse, connect, i));
}

int compare_positions(list_t *rooms, int x, int y )
{
	list_t *tmp = rooms;
	room_t *room = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->pos.x == x && room->pos.y == y)
			return (84);
	}
	return (0);
}

int compare_names(list_t *rooms, char *name)
{
	list_t *tmp = rooms;
	room_t *room = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (my_streqstr(room->name, name))
			return (84);
	}
	return (0);
}
