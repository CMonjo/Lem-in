/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "main.h"

void fill_anthill(anthill_t *anthill, char **input)
{
	char **info;
	int i = 2;

	anthill->room = malloc(sizeof(room_t) * 8);
	anthill->ants = my_getnbr(input[0]);
	for (; my_streqstr(input[i - 2], "##end") == 0; i++) {
		if (input[i][0] != '#') {
			info = str_to_array(input[i], ' ');
			anthill->room[i - 2].name = info[0];
			anthill->room[i - 2].x = my_getnbr(info[1]);
			anthill->room[i - 2].y = my_getnbr(info[2]);
		}
	} for (; input[i]; i++) {
		i = i;
		//printf("%s\n", input[i]);
	}
}

anthill_t *manage_input(void)
{
	char *file = my_read("input");
	char **input;
	anthill_t *anthill;

	if (!file)
		return (NULL);
	input = str_to_array(file, '\n');
	//if (!input || verif_file(input) == 84)
		//return (NULL);
	anthill = malloc(sizeof(anthill_t));
	if (!anthill)
		return (NULL);
	fill_anthill(anthill, input);
	return (anthill);
}
