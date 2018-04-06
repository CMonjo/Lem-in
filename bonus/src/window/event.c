/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** event
*/

#include "proto.h"

void event_gestion(window_t *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		window->event = event;
	}
	sfRenderWindow_clear(window->window, sfWhite);
}
