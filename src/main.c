/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "../include/lemin.h"

void disp_path(list_t *path);

parse_t *init_parse(void)
{
	parse_t *parse = malloc(sizeof(parse_t));

	parse->start = 0;
	parse->end = 0;
	parse->type = 0;
	return (parse);
}

int main(int ac, char **av)
{
	list_t *rooms = NULL;
	parse_t *parse = NULL;
	room_t *start = NULL;
	room_t *end = NULL;
	list_t *paths = NULL;
	list_t *pathscpy = NULL;

	(void)av;
	if (ac != 1)
		return (84);
	parse = init_parse();
	if (create_map(&rooms, parse) == 84)
		return (84);
	start = get_start_room(rooms);
	end = get_end_room(rooms);
	get_all_paths(&paths, NULL, start, end);
	if (paths == NULL)
		return (84);
	pathscpy = paths;
	// my_printf("\n§§§$$$--$$$§§§\n[%s -> %s]\nFOUND PATHS :\n", start->name, end->name);
	// for (; pathscpy != NULL; pathscpy = pathscpy->next) {
	// 	my_printf(" • ");
	// 	disp_path((list_t*)pathscpy->data);
	// }
	my_printf("\nSHORTEST:\n • ");
	list_t *shortest = get_shortest_available_path(paths);
	disp_path(shortest);
	((room_t*)shortest->next->data)->occuped = 1;
	// my_printf("\n\nSET AS OCCUPED. NEXT SHORTEST:\n\n • ");
	shortest = get_shortest_available_path(paths);
	// disp_path(shortest);
	((room_t*)shortest->next->data)->occuped = 1;
	my_printf("\n\nSET AS OCCUPED. NEXT SHORTEST:\n\n • ");
	shortest = get_shortest_available_path(paths);
	disp_path(shortest);
	my_printf("\n\n");
	display_output(rooms, parse);
	return (0);
}
