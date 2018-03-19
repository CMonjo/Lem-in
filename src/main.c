/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "main.h"

int main(int ac, char **av)
{
	anthill_t *anthill;

	(void)av;
	if (ac != 1)
		return (84);
	anthill = manage_input();
	if (!anthill)
		return (84);
	free_anthill(anthill);
	return (0);
}
