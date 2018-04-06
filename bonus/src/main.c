/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

void free_window(window_t *window)
{
	sfRenderWindow_destroy(window->window);
	sfTexture_destroy(window->texture);
	sfSprite_destroy(window->sprite);
	sfClock_destroy(window->clock);
	free(window);
}

int main(int ac, char **av)
{
	window_t *window = init_window();
	anthill_t *anthill = create_anthill();

	if (!window || ac != ac || av != av)
		return (84);
	while (sfRenderWindow_isOpen(window->window)) {
		event_gestion(window);
		display_anthill(window, anthill);
		sfRenderWindow_display(window->window);
	}
	free_window(window);
	return (0);
}
