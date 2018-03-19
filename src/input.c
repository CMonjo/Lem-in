/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "main.h"

int fill_rooms(room_t *room, char **input)
{
	char **info;
	int i = 2;

	for (int j = 0; my_streqstr(input[i - 2], "##end") == 0; i++, j++) {
		if (input[i][0] != '#') {
			info = str_to_array(input[i], ' ');
			room[j] = create_room(info[0],
			(pos_t){my_getnbr(info[1]), my_getnbr(info[2])});
		}
	}
	return (i);
}

void fill_tunnels(room_t *room, char **input, int i)
{
	char **info;

	for (; input[i + 1]; i++) {
		if (input[i][0] != '#') {
			info = str_to_array(input[i], '-');
		}
	}
}

void fill_anthill(room_t *room, char **input)
{
	int ants = my_getnbr(input[0]);
	int nbr_rooms = 0;
	room_t **room;
	int i;

	for (int j = 2; my_streqstr(input[j - 2], "##end") == 0; j++)
		nbr_rooms += (input[j][0] != '#') ? 1 : 0;
	room = malloc(sizeof(room_t *) * nbr_rooms);
	i = fill_rooms(room, input);
	fill_tunnels(room, input, i);
}

anthill_t *manage_input(void)
{
	char *file = my_read("input");
	char **input;

	if (!file)
		return (NULL);
	input = str_to_array(file, '\n');
	if (!input || verif_file(input) == 84)
		return (NULL);
	fill_anthill(input);
	return (anthill);
}
