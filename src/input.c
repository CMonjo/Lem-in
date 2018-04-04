/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../include/lemin.h"

int create_rooms(room_t **room, char **input)
{
	int i = 1;
	char **info = str_to_array(input[i], ' ');

	for (int j = 0; input[i][0] == '#' ||
	(input[i][0] != '#' && info[1] && info[2]); i++) {
		if (input[i][0] != '#') {
			room[j] = create_room(info[0],
			(pos_t){my_getnbr(info[1]), my_getnbr(info[2])});
			j++;
		}
		info = str_to_array(input[i + 1], ' ');
	}
	return (i);
}

void link_rooms(room_t **room, char **input, int i)
{
	char **info;

	for (; input[i + 1]; i++) {
		if (input[i][0] != '#') {
			info = str_to_array(input[i], '-');
			(void)info;
			(void)room;
		}
	}
}

int count_rooms(char **input)
{
	int i = 1;
	char **info = str_to_array(input[i], ' ');
	int rooms = 0;

	for (; input[i][0] == '#' ||
	(input[i][0] != '#' && info[1] && info[2]); i++) {
		if (input[i][0] != '#')
		rooms += 1;
		info = str_to_array(input[i + 1], ' ');
	}
	return (rooms);
}

void connect_rooms(char **input)
{
	room_t **room;
	int i;

	room = malloc(sizeof(room_t *) * count_rooms(input));
	i = create_rooms(room, input);
	link_rooms(room, input, i);
}

void display_output(file_t *file, parse_t *parse)
{
	file_t *tmp = file;

	my_printf("#number_of_ants\n%d\n", parse->nb_ant);
	my_printf("#rooms\n##start\n");
	for (;tmp != NULL; tmp = tmp->next) {
		if (tmp->type == START)
			my_printf("%s %d %d\n", tmp->name, tmp->pos.x, tmp->pos.y);
		if (tmp->type == END)
			my_printf("##end\n%s %d %d\n", tmp->name, tmp->pos.x, tmp->pos.y);
	}
}

int create_map(void)
{
	file_t *file = malloc(sizeof(file_t));
	parse_t *parse = malloc(sizeof(parse_t));
	char *gnl = my_read();
	char **input;

	file = NULL;
	parse->start = 0;
	parse->end = 0;
	parse->type = 0;
	if (!gnl)
		return (84);
	input = my_str_split(gnl, '\n');
	if (!input || verif_file(&file, parse, input) == 84)
		return (84);
	connect_rooms(input);
	display_output(file, parse);
	return (0);
}
