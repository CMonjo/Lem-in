/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

void display_ant(anthill_t *a)
{
	static int turn = 0;

	if (turn < anthill->ants) {
		sfSprite_setPosition(anthill->sprite, FIRST_POS);
		sfRenderWindow_drawSprite(w->window, a->sprite, NULL);
	} if (turn >= anthill->len) {
		sfSprite_setPosition(anthill->sprite, LAST_POS);
		sfRenderWindow_drawSprite(w->window, a->sprite, NULL);
	}
	for (int i = 0; i < anthill->move[turn]->moves[i]; i++) {
		sfSprite_setPosition(anthill->sprite, ACTUAL_POS);
		sfRenderWindow_drawSprite(w->window, a->sprite, NULL);
	}
	turn++;
}

void display_anthill(window_t *w, anthill_t *a)
{
	for (int i = 0; a->tunnels[i]; i++) {
		sfRenderWindow_drawVertexArray(w->window, a->tunnels[i], NULL);
	} for (int i = 0; a->rooms[i]; i++) {
		sfRenderWindow_drawRectangleShape(w->window, a->rooms[i], NULL);
	} for (int i = 0; i < a->ants; i++) {
		display_ant(a);
	}
}
