/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** struct inits
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

room_t *create_room(char *name, pos_t pos)
{
	room_t *room = (room_t*)malloc(sizeof(room_t));

	if (room == NULL)
		return (NULL);
	room->name = name;
	room->pos = pos;
	room->links = NULL;
	room->nblinks = 0;
	room->occuped = 0;
	return (room);
}

int	connect_room_to_room(room_t *fromRoom, room_t *toRoom)
{
	connects_t *link = (connects_t*)malloc(sizeof(connects_t));

	if (link == NULL)
		return (0);
	link->next = fromRoom->links;
	link->room = toRoom;
	fromRoom->links = link;
	fromRoom->nblinks += 1;
	if (connect_room_to_room(toRoom, fromRoom))
		return (1);
	else
		return (0);
}
