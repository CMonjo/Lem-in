/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

int check_nb_type(parse_t *parse, char **input, int i)
{
	my_strcmp(input[i], "##start") == 1 ?
	parse->start += 1, parse->type = 1 : 0;
	my_strcmp(input[i], "##end") == 1 ?
	parse->end += 1, parse->type = 2 : 0;
	for (; parse->type != 0 && input[i][0] == '#' && input[i + 1] != NULL
	&& my_strcmp(input[i + 1], "##start") == 0 &&
	my_strcmp(input[i + 1], "##end") == 0; i++);
	if  (parse->type != 0 && (my_strcmp(input[i], "##start") == 1
	|| my_strcmp(input[i], "##end") == 1))
		return (84);
	return (0);
}

int check_dash(char **input, int i)
{
	if (input[i][0] == '#')
		return (0);
	for (int j = 0; input[i][j] != '\0'; j++) {
		if (input[i][j] == '-')
			return (1);
	}
	return (0);
}

int parsing_file_input(file_t **file, parse_t *parse, char **input, int begin)
{
	int status = 0;

	for (int i = begin; input[i] != NULL; i++) {
		if (input[i][0] == '#')
			parse->type = 0;
		if (check_nb_type(parse, input, i) == 84)
			return (84);
		check_dash(input, i) == 1 ? status = 1 : 0;
		if (status == 0 && input[i][0] != '#') {
			if (verif_room_name(file, parse, input, i) == 84)
				return (84);
		}
		else if (status == 1 && input[i][0] != '#') {
		 	if (compare_connections(*file, input, i) == 84)
				return (84);
			// IL SE PEUT QU'IL N'Y AI PAS DE RETURN 84 A FAIRE
			// POUR LES CONNEXIONS
			//compare_connections(*file, input, i);
		}
	}
	if (parse->start != 1 || parse->end != 1)
		return (84);
	return (0);
}

int verif_file(file_t **file, parse_t *parse, char **input)
{
	int i = 0;

	for (i = 0; input[i][0] == '#'; i++) {
		if (my_strcmp(input[i], "##start") == 1 ||
		my_strcmp(input[i], "##end") == 1)
			break;
	}
	parse->nb_ant = my_getnbr(input[i]);
	if (parse->nb_ant <= 0 || my_str_isnum(input[i]) == 1 ||
	parsing_file_input(file, parse, input, ++i) == 84
	|| compare_names(*file) == 84)
		return (84);
	printf("1\n");
	print_link(*file);
	return (0);
}
