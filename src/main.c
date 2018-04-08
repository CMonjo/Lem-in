/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "../include/lemin.h"

parse_t *init_parse(void)
{
	parse_t *parse = malloc(sizeof(parse_t));

	if (!parse)
		return (NULL);
	parse->start = 0;
	parse->end = 0;
	parse->type = 0;
	parse->error_parse = 0;
	parse->status = 0;
	return (parse);
}

int create_map(list_t **rooms, parse_t *parse, char **av)
{
	char *gnl = my_read();
	char **input = NULL;

	(void)av;
	if (gnl == NULL || gnl[0] == '\0' || gnl[0] == '\n')
		return (84);
	input = my_str_split(gnl, '\n');
	if (input == NULL || input[0][0] == '\0'
	|| verif_file(rooms, parse, input) == 84)
		return (84);
	return (0);
}

int main(int ac, char **av)
{
	list_t *rooms = NULL;
	parse_t *parse = NULL;
	room_t *start = NULL;
	room_t *end = NULL;
	list_t *paths = NULL;
	list_t *shortest = NULL;

	if (ac != 1)
		return (84);
	parse = init_parse();
	if (create_map(&rooms, parse, av) == 84)
		return (84);
	start = get_start_room(rooms);
	end = get_end_room(rooms);
	if (end != NULL && start != NULL) {
		get_all_paths(&paths, NULL, start, end);
		shortest = get_shortest_available_path(paths);
	}
	display_output(rooms, parse, paths, shortest);
	return (parse->error_parse);
}
