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

	vertex1.position.x += size + 10 / 2;
	vertex1.position.y += size + 10;
	vertex2.position.x += size + 10 / 2;
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

	size = (x / SCREEN_X) + 1;
	if (size < (y / SCREEN_Y) + 1)
		size = (y / SCREEN_Y) + 1;
	return (size);
}

anthill_t *create_anthill(void)
{
	anthill_t *anthill = malloc(sizeof(anthill_t));
	float size = anthill_size();

	anthill->ants = 10;
	anthill->texture = sfTexture_createFromFile("img/ant.png", NULL);
	anthill->sprite = sfSprite_create();
	sfSprite_setTexture(anthill->sprite, anthill->texture, sfTrue);
	sfSprite_setScale(anthill->sprite, (sfVector2f){1 / size, 1 / size});
	anthill->rooms = malloc(sizeof(sfRectangleShape *) * 6);
	anthill->rooms[0] = create_room(20, 100, 10 / size);
	anthill->rooms[1] = create_room(200, 800, 10 / size);
	anthill->rooms[2] = create_room(1300, 550, 10 / size);
	anthill->rooms[3] = create_room(900, 300, 10 / size);
	anthill->rooms[4] = create_room(450, 450, 10 / size);
	anthill->rooms[5] = NULL;
	anthill->tunnels = malloc(sizeof(sfVertexArray *) * 2);
	anthill->tunnels[0] = create_tunnels((sfVector2f){20, 100},
	(sfVector2f){200, 800}, size);
	anthill->tunnels[1] = NULL;

	sfSprite_setPosition(anthill->sprite, (sfVector2f){20 - 12, 100 - 12});

	return (anthill);
}
