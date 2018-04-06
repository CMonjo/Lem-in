/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "proto.h"

void set_window(window_t *window)
{
	sfRenderWindow_setFramerateLimit(window->window, 60);
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
}

window_t *init_window(void)
{
	window_t *window = malloc(sizeof(window_t));

	window->mode = (sfVideoMode){SCREEN_X, SCREEN_Y, 32};
	window->window = sfRenderWindow_create(window->mode,"Matches",\
	sfClose | sfResize, NULL);
	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
	window->sprite = sfSprite_create();
	window->clock = sfClock_create();
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = 0;
	set_window(window);
	return (window);
}
