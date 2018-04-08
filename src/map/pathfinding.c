/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

int is_path_occuped(list_t *path, int size)
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
	list_t *tmppath = NULL;
	int size = -1;
	int tmpsize = 0;

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

int get_all_paths(list_t **paths, list_t *act, room_t *to, room_t *end)
{
	list_t *links = to->links;
	room_t *tmp_room = NULL;

	list_append(&act, to);
	if (to == end) {
		list_add(paths, act);
		return (0);
	}
	for (; links != NULL; links = links->next) {
		tmp_room = (room_t*)links->data;
		if (list_contain(act, tmp_room))
			continue;
		get_all_paths(paths, list_copy(act), tmp_room, end);
	}
	return (0);
}
