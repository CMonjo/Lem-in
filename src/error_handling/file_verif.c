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
	int enum_type = 0;

	for (i = 1; input[i] != NULL; i++, enum_type = 0) {
		my_strcmp(input[i], "##start") == 1 ? start += 1, enum_type = 1 : 0;
		my_strcmp(input[i], "##end") == 1 ? end += 1, enum_type = 2 : 0;
		for(; enum_type != 0 && input[i][0] == '#' && input[i] != NULL && my_strcmp(input[i], "##start") == 0 && my_strcmp(input[i], "##end") == 0; i++);
		if (enum_type != 0 && (my_strcmp(input[i + 1], "##start") == 1 || my_strcmp(input[i + 1], "##end") == 1)) {
			printf("double end ou start\n" );
			return (84);
		}
		if (input[i][0] != '#' && verif_room_name(file, input, i, enum_type) == 84)
			return (84);
	}
	if (start != 1 || end != 1) {
		printf("sort\n");
		return (84);
	}
	return (0);
}

int verif_file(char **input)
{
	file_t *file = malloc(sizeof(file_t));

	file = NULL;
	if (my_str_isnum(input[0]) == 1)
		return (84);
	if (parsing_file_input(&file, input) == 84)
		return (84);
	if (compare_names(file, "salut") == 84/* || compare_positions(file, 12, 12) == 84*/)
		return (84);
	print_link(file);
	return (0);
}
