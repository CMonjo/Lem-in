/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

int connect_rooms_from_name(list_t *rooms, char *name1, char *name2)
{
	room_t *room1 = get_room_from_name(rooms, name1);
	room_t *room2 = get_room_from_name(rooms, name2);

	connect_room_to_room(room1, room2);
	return (0);
}

connection_t *add_connection_to_list(char *from, char *to)
{
	connection_t *connection = malloc(sizeof(connection_t));

	connection->from_room = from;
	connection->to_room = to;
	return (connection);
}

int compare_connections(list_t *rooms, parse_t *parse, char **input, int in)
{
	list_t *tmp = rooms;
	room_t *room = NULL;
	connection_t *connection = NULL;
	char **connect = my_str_split(input[in], '-');
	int i = 0;

	for (;connect[i] != NULL; i++);
	if (i != 2) {
		parse->error_parse = 1;
		return (84);
	}
	for (i = 0; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (my_strcmp(connect[0], room->name) == 1 || my_strcmp(connect[1], room->name) == 1)
			i += 1;
	}
	if (i == 2 || my_strcmp(connect[0], connect[1]) == 1) {
		connect_rooms_from_name(rooms, connect[0], connect[1]);
		connection = add_connection_to_list(connect[0], connect[1]);
		list_append(&parse->connect, connection);
		return (0);
	}
	parse->error_parse = 1;
	return (84);
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
