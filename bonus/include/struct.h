/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef _STRUCT_H_
	#define _STRUCT_H_

	typedef struct window_s {
		sfRenderWindow *window;
		sfVideoMode mode;
		sfSprite *sprite;
		sfTexture *texture;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		float seconds;
	} window_t;

	typedef struct anthill_s {
		sfRectangleShape **rooms;
		sfVertexArray **tunnels;
		int ants;
		sfSprite *sprite;
		sfTexture *texture;
	} anthill_t;
#endif
