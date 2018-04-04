/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** room tools
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

room_t *get_start_room(list_t *map)
{
	list_t *tmp = map;
	room_t *room = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == START)
			return (room);
	}
	return (NULL);
}

room_t *get_end_room(list_t *map)
{
	list_t *tmp = map;
	room_t *room = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == END)
			return (room);
	}
	return (NULL);
}
