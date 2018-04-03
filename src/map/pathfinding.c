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

int	is_path_occuped(list_t *path, int size)
{
	room_t *room = NULL;
	int occuped = 0;

	if (size >= 1) {
		room = (room_t*)path->next->data;
		occuped = room->occuped;
	}
	return (occuped);
}

list_t *get_shortest_available_path(list_t *paths)
{
	list_t *tmp = paths;
	list_t *path = NULL;
	int size = -1;
	int tmpsize = 0;
	list_t *tmppath = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		tmppath = (list_t*)tmp->data;
		tmpsize = list_size(tmppath);
		if ((size == -1 || tmpsize < size) && tmpsize > 0 &&
			!is_path_occuped(tmppath, tmpsize)) {
				size = tmpsize;
				path = tmppath;
			}
	}
	return (path);
}

list_t *get_all_paths(list_t **paths, list_t *act, room_t *to, room_t *end)
{
	list_t *links = to->links;
	room_t *tmp_room = NULL;

	list_append(&act, to);
	disp_path(act);
	if (to == end) {
		list_add(paths, act);
		return (*paths);
	}
	for (; links != NULL; links = links->next) {
		tmp_room = (room_t*)links->data;
		if (list_contain(act, tmp_room))
			continue;
		get_all_paths(paths, list_copy(act), tmp_room, end);
	}
	return (*paths);
}
