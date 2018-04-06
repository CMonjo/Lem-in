/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

sfRectangleShape *create_room(int x, int y, float size)
{
	sfRectangleShape *room = sfRectangleShape_create();
	sfColor fill = (sfColor){139, 108, 66, 255};
	sfColor outline = (sfColor){91, 60, 17, 255};

	sfRectangleShape_setPosition(room, (sfVector2f){x, y});
	sfRectangleShape_setSize(room, (sfVector2f){size, size});
	sfRectangleShape_setFillColor(room, fill);
	sfRectangleShape_setOutlineColor(room, outline);
	sfRectangleShape_setOutlineThickness(room, size * 0.1);
	return (room);
}

sfVertexArray *create_tunnels(sfVector2f point1, sfVector2f point2, float size)
{
	sfVertexArray *line = sfVertexArray_create();
	sfColor color = (sfColor){91, 60, 17, 255};
	sfVertex vertex1 = {.position = point1, .color = color};
	sfVertex vertex2 = {.position = point2, .color = color};

	vertex1.position.x += size;
	vertex1.position.y += size;
	sfVertexArray_append(line, vertex1);
	sfVertexArray_append(line, vertex2);
	sfVertexArray_setPrimitiveType(line, sfLinesStrip);
	return (line);
}

float anthill_size(void)
{
	int x = 1000;
	int y = 10;
	float size;

	size = 50 / ((x / SCREEN_X) + 1);
	if (size > 50 / ((y / SCREEN_Y) + 1))
		size = 50 / ((y / SCREEN_Y) + 1);
	return (size);
}

anthill_t *create_anthill(void)
{
	anthill_t *anthill = malloc(sizeof(anthill_t));
	float size = anthill_size();

	anthill->rooms = malloc(sizeof(sfRectangleShape *) * 6);
	anthill->rooms[0] = create_room(20, 100, size);
	anthill->rooms[1] = create_room(200, 800, size);
	anthill->rooms[2] = create_room(1300, 550, size);
	anthill->rooms[3] = create_room(900, 300, size);
	anthill->rooms[4] = create_room(450, 450, size);
	anthill->rooms[5] = NULL;
	anthill->tunnels = malloc(sizeof(sfVertexArray *) * 2);
	anthill->tunnels[0] = create_tunnels((sfVector2f){20, 100},
	(sfVector2f){200, 800}, size);
	anthill->tunnels[1] = NULL;
	return (anthill);
}
