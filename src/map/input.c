/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

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
			info = info;
			room = room;
		}
	}
}

void connect_rooms(char **input)
{
	int nbr_rooms = 0;
	room_t **room;
	int i;

	for (int j = 2; my_streqstr(input[j - 2], "##end") == 0; j++)
		nbr_rooms += (input[j][0] != '#') ? 1 : 0;
	room = malloc(sizeof(room_t *) * nbr_rooms);
	i = create_rooms(room, input);
	link_rooms(room, input, i);
}

void create_map(void)
{
	char *file = my_read("input");
	char **input;

	// if (!file)
	// 	return (NULL);
	input = str_to_array(file, '\n');
	if (!input || verif_file(input) == 84)
		/*return (NULL);*/return;
	connect_rooms(input);
}
