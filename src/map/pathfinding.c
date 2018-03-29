/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

path_t *init_path(room_t *start)
{
	path_t *path = (path_t*)malloc(sizeof(path_t));

	path->rooms = NULL;
	list_append(&path->rooms, start);
	path->nbrooms = path->rooms == NULL ? 0 : 1;
	return (path);
}

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

/*list_t *get_all_path(room_t *start, room_t *end, list_t *analyzed)
{
	list_t *paths = NULL;
	//path_t *tmp_path = init_path(start);
	list_t *links = start->links;
	room_t *tmp_room = NULL;

	for (; start != end && links != NULL; links = links->next) {
		tmp_room = (room_t*)links->data;
		if (list_contain(analyzed, tmp_room) || tmp_room == NULL)
			continue;
		list_add(&analyzed, tmp_room);
		//list_append(&tmp_path->rooms, tmp_room);
		list_append(&paths, get_all_path(tmp_room, end, analyzed));
	}
	return (paths);
}*/
