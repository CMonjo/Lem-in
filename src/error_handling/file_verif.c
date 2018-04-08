/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

int check_nb_type(parse_t *parse, char **input, int i)
{
	my_strcmp(input[i], "##start") == 1 ?
	parse->start += 1, parse->type = 1 : 0;
	my_strcmp(input[i], "##end") == 1 ?
	parse->end += 1, parse->type = 2 : 0;
	for (; parse->type != 0 && input[i][0] == '#' && input[i + 1]
	!= NULL && my_strcmp(input[i + 1], "##start") == 0
	&& my_strcmp(input[i + 1], "##end") == 0; i++);
	if  (parse->type != 0 && (my_strcmp(input[i], "##start") == 1
	|| my_strcmp(input[i], "##end") == 1))
		return (84);
	if (parse->end > 1 || parse->start > 1)
		return (84);
	return (i);
}

int parsing_file_input(list_t **rooms, parse_t *parse, char **input, int begin)
{
	int status = 0;

	for (int i = begin; input[i] != NULL && parse->error_parse != 1; i++, parse->type = 0) {
		if ((i = check_nb_type(parse, input, i)) == 84)
			return (84);
		check_dash(input[i]) == 1 ? status = 1 : 0;
		if (status == 0 && input[i][0] != '#') {
			if (verif_room_name(rooms, parse, input, i) == 84) {
				parse->error_parse = 1;
				break;
			}
		}
		else if (status == 1 && input[i][0] != '#') {
		 	if (compare_connections(*rooms, parse, input, i) == 84) {
				parse->error_parse = 1;
				break;
			}
		}
	}
	if (parse->start != 1 || parse->end != 1)
		return (84);
	return (0);
}

int verif_file(list_t **rooms, parse_t *parse, char **input)
{
	int i = 0;

	parse->connect = NULL;
	for (int clear = 0; input[clear] != NULL; clear++)
		input[clear] = my_clear_str(input[clear]);
	for (i = 0; input[i][0] == '#'; i++) {
		if (my_strcmp(input[i], "##start") == 1 ||
		my_strcmp(input[i], "##end") == 1)
			break;
	}
	parse->nb_ant = my_getnbr(input[i]);
	if (parse->nb_ant <= 0 || my_str_isnum(input[i]) == 1 || parsing_file_input(rooms, parse, input, ++i) == 84)
		return (1);
	return (0);
}
