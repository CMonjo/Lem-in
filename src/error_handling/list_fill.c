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

int fill_connection(list_t *rooms, parse_t *parse, char **connect, int i)
{
	connection_t *connection = NULL;

	if (i == 2 || my_strcmp(connect[0], connect[1]) == 1) {
		connect_rooms_from_name(rooms, connect[0], connect[1]);
		connection = add_connection_to_list(connect[0], connect[1]);
		list_append(&parse->connect, connection);
		return (0);
	} else {
		parse->error_parse = 1;
		return (84);
	}
	return (0);
}
