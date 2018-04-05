/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** path finding
*/

#include "../../include/lemin.h"
#include "../../include/my.h"

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
