/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "lemin.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (84);
	create_map();
	return (0);
}
