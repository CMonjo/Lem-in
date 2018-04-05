/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../include/lemin.h"
#include "../include/my.h"
#include "../include/list.h"

void display_output(list_t *rooms, parse_t *parse)
{
	list_t *tmp = rooms;
	room_t *room = NULL;

	my_printf("#number_of_ants\n%d\n", parse->nb_ant);
	my_printf("#rooms\n##start\n");
	for (;tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == START)
			my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
		if (room->type == END)
			my_printf("##end\n%s %d %d\n", room->name, room->pos.x, room->pos.y);
	}
}

int create_map(list_t **rooms, parse_t *parse)
{
	char *gnl = my_read();
	char **input = NULL;

	if (!gnl)
		return (84);
	input = my_str_split(gnl, '\n');
	if (!input || verif_file(rooms, parse, input) == 84)
		return (84);
	return (0);
}
