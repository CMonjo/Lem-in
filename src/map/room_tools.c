/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** room tools
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

room_t	*get_first_unused_room_from_room(room_t *from_room)
{
	connects_t *_tmp = from_room->links;

	while (_tmp != NULL) {
		if (!_tmp->room->occuped)
			return (_tmp->room);
		_tmp = _tmp->next;
	}
	return (NULL);
}
