/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

void free_anthill(anthill_t *anthill)
{
	for (int i = 0; anthill->rooms[i]; i++)
		sfRectangleShape_destroy(anthill->rooms[i]);
	for (int i = 0; anthill->tunnels[i]; i++)
		sfVertexArray_destroy(anthill->tunnels[i]);
	free(anthill);
}