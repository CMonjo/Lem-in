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

void create_map(void)
{
	char *file = my_read("input");
	char **input;

	if (!file)
		return;
	input = my_str_split(file, '\n');
	if (!input || verif_file(input) == 84) {
		my_printf("Error verif file\n");
		return;
	}
	connect_rooms(input);
}
