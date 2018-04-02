/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

void disp_path(list_t *path)
{
	list_t *_tmp = path;
	room_t *room = NULL;

	for (; _tmp != NULL; _tmp = _tmp->next) {
		if (room != NULL)
			my_printf(" -> ");
		room = (room_t*)_tmp->data;
		my_printf("%s", room->name);
	}
	my_printf("\n");
}

list_t *get_all_paths(list_t **paths, list_t *act, room_t *to, room_t *end)
{
	list_t *links = to->links;
	room_t *tmp_room = NULL;

	list_append(&act, to);
	my_printf("$act: ");
	disp_path(act);
	if (to == end) {
		my_printf("END found.\n");
		list_add(paths, act);
		return (*paths);
	}
	for (; links != NULL; links = links->next) {
		tmp_room = (room_t*)links->data;
		if (list_contain(act, tmp_room))
			continue;
		my_printf("$to: %s -> $link: %s\n", to->name, tmp_room->name);
		get_all_paths(paths, list_copy(act), tmp_room, end);
	}
	return (*paths);
}
