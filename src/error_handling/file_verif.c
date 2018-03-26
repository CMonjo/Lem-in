/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

int parsing_file_input(file_t **file, char **input)
{
	int i = 1;
	int start = 0;
	int end = 0;

	for (i = 1; input[i] != NULL; i++) {
		if (input[i][0] == '#') {
			start += my_strcmp(input[i], "##start") == 1 ? 1 : 0;
			end += my_strcmp(input[i], "##end") == 1 ? 1 : 0;
			// STOCKER SI TROUVER
		}
		else if (verif_room_name(file, input, i) == 84)
			return (84);
	}
	if (start != 1 || end != 1)
		return (84);
	return (0);
}

int verif_file(char **input)
{
	file_t *file = malloc(sizeof(file_t));
	int parsing = 0;

	file = NULL;
	if (my_str_isnum(input[0]) == 1)
		return (84);
	parsing_file_input(&file, input);
	if (parsing == 84)
		return (84);
	// if (compare_names(file, "salut") == 84 || parsing == 84/* || compare_positions(file, 12, 12) == 84*/)
	// 	return (84);
	print_link(file);
	return (0);
}
