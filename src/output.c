/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "lemin.h"
#include "my.h"

char **stock_path(list_t *path, int len)
{
	list_t *_tmp = path->next;
	room_t *room = NULL;
	char **path_array = malloc(sizeof(char *) * len);

	for (int i = 0; _tmp != NULL; _tmp = _tmp->next, i++) {
		room = (room_t*)_tmp->data;
		path_array[i] = malloc(sizeof(char) *
		(my_strlen(room->name) + 1));
		for (int j = 0; room->name[j] != '\0'; j++)
			path_array[i][j] = room->name[j];
		path_array[i][my_strlen(room->name)] = '\0';

	}
	path_array[len - 1] = NULL;
	return (path_array);
}

void display_output_path(list_t *list_path, int len, int nbr_ants)
{
	char **path = stock_path(list_path, len);
	int max = nbr_ants < len - 1 ? nbr_ants : len - 1;
	int first_ant = 0;
	int first_room = 0;

	my_printf("#moves\n");
	for (int i = 0; i < (nbr_ants + len - 2); i++) {
		for (int j = 0, ant = first_ant, room = first_room;
		j < max && j <= i && ant < nbr_ants; j++, ant++, room--) {
			my_printf("P%d-%s", ant + 1, path[room]);
			(j + 1 < max && j + 1 <= i && ant + 1 < nbr_ants) ?
			my_putchar(' ') : 0;
		}
		(i >= len - 2) ? first_ant++ : 0;
		(first_room < len - 2) ? first_room++ : 0;
		my_putchar('\n');
	}
	for (int i = 0; path[i]; i++)
		free(path[i]);
	free(path);
}

void display_ant_rooms_tunnels(list_t *rooms, parse_t *parse)
{
	room_t *room = NULL;
	connection_t *co_room = NULL;
	list_t *check = NULL;

	my_printf("#number_of_ants\n%d\n", parse->nb_ant);
	rooms != NULL ? my_printf("#rooms\n") : 0;
	for (list_t *tmp = rooms; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		room->type == START ? my_printf("##start\n") : 0;
		room->type == END ? my_printf("##end\n") : 0;
		my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
	}
	check = parse->connect;
	check != NULL ? my_printf("#tunnels\n") : 0;
	for (list_t *tmp = parse->connect; tmp != NULL; tmp = tmp->next) {
		co_room = (connection_t*)tmp->data;
		if (co_room == NULL)
			break;
		my_printf("%s-%s\n", co_room->from_room, co_room->to_room);
	}
}

void display_output(list_t *rooms, parse_t *parse, list_t *paths, list_t *path)
{
	if (parse->nb_ant > 0)
		display_ant_rooms_tunnels(rooms, parse);
	if (paths != NULL && parse->error_parse == 0)
		display_output_path(path,
			list_size(path), parse->nb_ant);
	parse->error_parse = parse->error_parse == 1 ? 84 : 0;
}
