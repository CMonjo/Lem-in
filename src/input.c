/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "main.h"

int input_error(char *file)
{
	char **input = str_to_array(file, '\n');

	if (!input)
		return (84);
	free(file);
	free(input);
	return (0);
}

void fill_anthill(anthill_t *anthill)
{
	char **input = str_to_array(file, '\n');

	anthill->ants = my_getnbr(input[0]);
}

anthill_t *manage_input(void)
{
	char *file = my_read("input");
	anthill_t *anthill;

	if (!file || input_error(file) == 84)
		return (NULL);
	anthill = malloc(sizeof(anthill_t));
	if (!anthill)
		return (NULL);
	fill_anthill(anthill);
	return (anthill);
}
