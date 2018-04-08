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

int create_map(list_t **rooms, parse_t *parse)
{
	char *gnl = my_read();
	char **input = NULL;

	if (!gnl)
		return (84);
	input = my_str_split(gnl, '\n');
	if (!input || verif_file(rooms, parse, input) == 84)
		return (84);
	return (0);
}

// int main(int ac, char **av)
// {
// 	list_t *rooms = NULL;
// 	parse_t *parse = NULL;
// 	room_t *start = NULL;
// 	room_t *end = NULL;
// 	list_t *paths = NULL;
//
// 	(void)av;
// 	if (ac != 1)
// 		return (84);
// 	parse = init_parse();
// 	if (create_map(&rooms, parse) == 84)
// 		return (84);
// 	start = get_start_room(rooms);
// 	end = get_end_room(rooms);
// 	get_all_paths(&paths, NULL, start, end);
// 	if (paths == NULL)
// 		return (84);
// 	list_t *shortest = get_shortest_available_path(paths);
// 	display_output_path(shortest, list_size(shortest), parse->nb_ant);
// 	graph(rooms, start, parse, paths);
// 	return (0);
// }
