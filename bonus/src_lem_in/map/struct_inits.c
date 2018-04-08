/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** struct inits
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

room_t *create_room(char *name, pos_t pos, type_t type)
{
	room_t *room = (room_t*)malloc(sizeof(room_t));

	if (room == NULL)
		return (NULL);
	room->name = name;
	room->pos = pos;
	room->links = NULL;
	room->nblinks = 0;
	room->occuped = 0;
	room->type = type;
	return (room);
}

int	connect_room_to_room(room_t *from, room_t *to)
{
	list_add(&from->links, to);
	list_add(&to->links, from);
	return (0);
}

/*int	connect_room_to_room(room_t *from_room, room_t *to_room)
{
	connects_t *link = (connects_t*)malloc(sizeof(connects_t));

	if (link == NULL)
		return (0);
	link->next = from_room->links;
	link->room = to_room;
	from_room->links = link;
	from_room->nblinks += 1;
	if (connect_room_to_room(to_room, from_room))
		return (1);
	else
		return (0);
}*/
