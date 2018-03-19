/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "main.h"

int input_error(void)
{
	char *file = my_read("input");
	char **input;

	if (!file)
		return (84);
	input = str_to_array(file, '\n');
	if (!input)
		return (84);
	free(file);
	free(input);
	return (0);
}

anthill_t *manage_input(void)
{
	anthill_t *anthill;

	if (input_error() == 84)
		return (NULL);
	anthill = malloc(sizeof(anthill_t));
	if (!anthill)
		return (NULL);

	return (anthill);
}
