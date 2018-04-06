/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

void display_anthill(window_t *w, anthill_t *a)
{
	for (int i = 0; a->rooms[i]; i++) {
		sfRenderWindow_drawRectangleShape(w->window, a->rooms[i], NULL);
	} for (int i = 0; a->tunnels[i]; i++) {
		sfRenderWindow_drawVertexArray(w->window, a->tunnels[i], NULL);
	}
}
