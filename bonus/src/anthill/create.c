/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"
#include "graph.h"

sfRectangleShape *create_room(int x, int y, float size)
{
	sfRectangleShape *room = sfRectangleShape_create();

	sfRectangleShape_setPosition(room, (sfVector2f){x, y});
	sfRectangleShape_setSize(room, (sfVector2f){size, size});
	sfRectangleShape_setFillColor(room, sfWhite);
	sfRectangleShape_setOutlineColor(room, sfBlack);
	sfRectangleShape_setOutlineThickness(room, size * 0.1);
	return (room);
}

sfVertexArray *create_tunnels(sfVector2f point1, sfVector2f point2, float size)
{
	sfVertexArray *line = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfBlack};
	sfVertex vertex2 = {.position = point2, .color = sfBlack};

	vertex1.position.x += size * 10 / 2;
	vertex1.position.y += size * 10 / 2;
	vertex2.position.x += size * 10 / 2;
	vertex2.position.y += size * 10 / 2;
	sfVertexArray_append(line, vertex1);
	sfVertexArray_append(line, vertex2);
	sfVertexArray_setPrimitiveType(line, sfLinesStrip);
	return (line);
}

float anthill_size(rooms_graph_t *rooms, int nb_rooms)
{
	int x = 0;
	int y = 0;
	float size;

	for (int i = 0; i < nb_rooms; i++) {
		(x < rooms[i].x) ? x = rooms[i].x : 0;
		(y < rooms[i].y) ? y = rooms[i].y : 0;
	}
	size = (x / SCREEN_X) + 1;
	if (size < (y / SCREEN_Y) + 1)
		size = (y / SCREEN_Y) + 1;
	return (size);
}

anthill_t *create_anthill(graph_t *g)
{
	anthill_t *a = malloc(sizeof(anthill_t));
	a->size = anthill_size(g->rooms, g->nb_rooms);

	a->ants = g->nb_ant;
	a->len = g->len;
	a->texture = sfTexture_createFromFile("img/ant.png", NULL);
	a->sprite = sfSprite_create();
	sfSprite_setTexture(a->sprite, a->texture, sfTrue);
	sfSprite_setScale(a->sprite, (sfVector2f){1 / a->size, 1 / a->size});
	a->rooms = malloc(sizeof(sfRectangleShape *) * (g->nb_rooms + 1));
	for (int i = 0; i < g->nb_rooms; i++)
		a->rooms[i] = create_room
		(g->rooms[i].x, g->rooms[i].y, 10 / a->size);
	a->rooms[g->nb_rooms] = NULL;
	a->tunnels = malloc(sizeof(sfVertexArray *) * (g->nb_tunnel + 1));
	for (int i = 0; i < g->nb_tunnel; i++)
		a->tunnels[i] = create_tunnels((sfVector2f)
		{g->tunnels[i][0], g->tunnels[i][1]},
		(sfVector2f){g->tunnels[i][2], g->tunnels[i][3]}, a->size);
	a->tunnels[g->nb_tunnel] = NULL;
	a->moves = g->moves;
	return (a);
}
