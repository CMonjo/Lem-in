/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

/*void print_link(file_t *file)
{
	file_t *tmp = file;

	while (tmp != NULL) {
		my_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	my_printf("\n");
}*/

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
	printf("i: %d\n", i);
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
		my_printf("COMP POS OF %s\n", room1->name);
		for (; tmp2 != NULL; tmp2 = tmp2->next) {
			room2 = (room_t*)tmp2->data;
			my_printf(" • WITH %s | ", room2->name);
			if (room2 != room1 && room1->pos.x == room2->pos.x &&
				room1->pos.y == room2->pos.y) {
					my_printf("KO : pos equal to %s\n", room1->name);
					return (84);
			}
			my_printf("OK\n");
		}
		tmp2 = rooms;
	}
	return (0);
	/*while (i != NULL) {
		j = i->next;
		while (j != NULL) {
			if (my_strcmp(i_to_a(i->pos.x),
			i_to_a(j->pos.x)) == 1 && my_strcmp(i_to_a(i->pos.y),
			i_to_a(j->pos.y)) == 1 &&
			i->name != j->name)
				return (84);
			j = j->next;
		}
		i = i->next;
	}
	return (0);*/
}

int compare_names(list_t *rooms)
{
	list_t *tmp1 = rooms;
	list_t *tmp2 = rooms;
	room_t *room1 = NULL;
	room_t *room2 = NULL;

	for (; tmp1 != NULL; tmp1 = tmp1->next) {
		room1 = (room_t*)tmp1->data;
		my_printf("COMP NAMES OF %s\n", room1->name);
		for (; tmp2 != NULL; tmp2 = tmp2->next) {
			room2 = (room_t*)tmp2->data;
			my_printf(" • WITH %s | ", room2->name);
			if (room2 != room1 && my_streqstr(room2->name, room1->name)) {
				my_printf("KO : name equal to %s\n", room1->name);
				return (84);
			}
			my_printf("OK\n");
		}
		tmp2 = rooms;
	}
	return (0);
}

/*int compare_names(file_t *file)
{
	file_t *i = file;
	file_t *j = file;
	int verif = 0;

	while (i != NULL) {
		j = i->next;
		while (j != NULL) {
			verif += my_strcmp(i->name, j->name);
			j = j->next;
		}
		i = i->next;
	}
	if (verif != 0)
		return (84);
	return (0);
}*/

/*void create_file_element(file_t **file, pos_t pos, char *name, int enum_type)
{
	file_t *new = malloc(sizeof(file_t));

	new->name = name;
	// FAIRE DANS LE .H LA DECLARATION DES VALEURS 0 1 2
	enum_type == 0 ? new->type = MIDDLE : 0;
	enum_type == 1 ? new->type = START : 0;
	enum_type == 2 ? new->type = END : 0;
	new->pos = pos;
	new->next = *file;
	*file = new;
}*/
