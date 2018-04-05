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

int compare_connections(list_t *rooms, char **input, int in)
{
	list_t *tmp = rooms;
	room_t *room = NULL;
	char **connect = my_str_split(input[in], '-');
	int i = 0;

	for (;connect[i] != NULL; i++);
	if (i != 2)
		return (84);
	if (my_strcmp(connect[0], connect[1]) == 1)
		return (0);
	for (i = 0; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (my_strcmp(connect[0], room->name) == 1 ||
		my_strcmp(connect[1], room->name) == 1)
			i += 1;
	}
	if (i == 2)
		connect_rooms_from_name(rooms, connect[0], connect[1]);
	return (0);
}

int compare_positions(list_t *rooms)
{
	list_t *tmp1 = rooms;
	list_t *tmp2 = rooms;
	room_t *room1 = NULL;
	room_t *room2 = NULL;

	for (; tmp1 != NULL; tmp1 = tmp1->next) {
		room1 = (room_t*)tmp1->data;
		for (; tmp2 != NULL; tmp2 = tmp2->next) {
			room2 = (room_t*)tmp2->data;
			if (room2 != room1 && room1->pos.x == room2->pos.x &&
				room1->pos.y == room2->pos.y)
					return (84);
		}
		tmp2 = rooms;
	}
	return (0);
}

int compare_names(list_t *rooms)
{
	list_t *tmp1 = rooms;
	list_t *tmp2 = rooms;
	room_t *room1 = NULL;
	room_t *room2 = NULL;

	for (; tmp1 != NULL; tmp1 = tmp1->next) {
		room1 = (room_t*)tmp1->data;
		for (; tmp2 != NULL; tmp2 = tmp2->next) {
			room2 = (room_t*)tmp2->data;
			if (room2 != room1 &&
				my_streqstr(room2->name, room1->name))
				return (84);
		}
		tmp2 = rooms;
	}
	return (0);
}
