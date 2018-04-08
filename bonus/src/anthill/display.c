/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"
#include "graph.h"

int my_strcmp(char const *s1, char const *s2)
{
	int cnt = 0;

	while (s1[cnt] != '\0' && s2[cnt] != '\0' && s1[cnt] == s2[cnt])
		cnt ++;
	return (s1[cnt] - s2[cnt]);
}

sfVector2f get_room_pos(graph_t *graph, char *move)
{
	sfVector2f pos = (sfVector2f){0, 0};

	for (int i = 0; i < graph->nb_rooms; i++) {
		if (my_strcmp(move, graph->rooms[i].name) == 0)
			pos = (sfVector2f){graph->rooms[i].x,
			graph->rooms[i].y};
	}
	return (pos);
}

void display_ant(anthill_t *anthill, graph_t *graph, window_t *w, int pass)
{
	static int turn = 0;
	sfVector2f pos;

	if (turn < anthill->ants) {
		pos = (sfVector2f){graph->pos_start.x - 10 * anthill->size,
		graph->pos_start.y - 10 * anthill->size};
		sfSprite_setPosition(anthill->sprite, pos);
		sfRenderWindow_drawSprite(w->window, anthill->sprite, NULL);
	} if (turn >= anthill->len) {
		pos = (sfVector2f){graph->pos_end.x - 10 * anthill->size,
		graph->pos_end.y - 10 * anthill->size};
		sfSprite_setPosition(anthill->sprite, pos);
		sfRenderWindow_drawSprite(w->window, anthill->sprite, NULL);
	}
	for (int i = 0; anthill->moves[turn][i]; i++) {
		pos = get_room_pos(graph, anthill->moves[turn][i]);
		sfSprite_setPosition(anthill->sprite, pos);
		sfRenderWindow_drawSprite(w->window, anthill->sprite, NULL);
	}
	if (pass == 1)
		turn++;
}

void display_anthill(window_t *w, anthill_t *a, graph_t *graph)
{
	for (int i = 0; a->tunnels[i]; i++) {
		sfRenderWindow_drawVertexArray(w->window, a->tunnels[i], NULL);
	} for (int i = 0; a->rooms[i]; i++) {
		sfRenderWindow_drawRectangleShape(w->window, a->rooms[i], NULL);
	}
	for (int i = 0; i < a->ants; i++) {
		if (w->seconds >= 1) {
			display_ant(a, graph, w, 1);
			sfClock_restart(w->clock);
			w->seconds = 0;
		} else
			display_ant(a, graph, w, 0);
	}
}
