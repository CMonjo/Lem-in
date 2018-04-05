/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "../include/lemin.h"
#include "../include/my.h"

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
			(j + 1 < max && j + 1 <= i) ? my_putchar(' ') : 0;
		}
		(i >= len - 2) ? first_ant++ : 0;
		(first_room < len - 2) ? first_room++ : 0;
		my_putchar('\n');
	}
	for (int i = 0; path[i]; i++)
		free(path[i]);
	free(path);
}

void display_rooms(list_t *tmp)
{
	room_t *room = NULL;
	if (tmp)
		display_rooms(tmp->next);
	printf("1\n");
	room = (room_t*)tmp->data;
	printf("2\n");
	if (room->type == MIDDLE)
		my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
}

void display_output(list_t *rooms, parse_t *parse)
{
	room_t *room = NULL;
	list_t *tmp_mid = rooms;

	my_printf("#number_of_ants\n%d\n", parse->nb_ant);
	my_printf("#rooms\n##start\n");
	for (list_t *tmp = rooms; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == START) {
			my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
			room = NULL;
			break;
		}
	}
	for (list_t *tmp = rooms; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == END) {
			my_printf("##end\n%s %d %d\n", room->name, room->pos.x, room->pos.y);
			room = NULL;
			break;
		}
	}
	for (list_t *tmp = rooms; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (room->type == MIDDLE)
			my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
	}
	//display_rooms(tmp_mid);
	// for (; tmp_mid != NULL; tmp_mid = tmp_mid->next) {
	// 	room = (room_t*)tmp_mid->data;
	//
	// }
	my_printf("#tunnels\n");
}
