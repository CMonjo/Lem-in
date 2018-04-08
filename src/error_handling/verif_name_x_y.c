/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

int move_j(char **input, int i, int j)
{
	for (; input[i][j] != ' ' && input[i][j] != '\0'; j++);
	for (; input[i][j] == ' '; j++);
	return (j);
}

char *recup_name(char **input, int i, int j, char *name)
{
	for (; input[i][j] != ' '; j++) {
		name[j] = input[i][j];
		if (input[i][j] == '\0')
			return (NULL);
	}
	name[j] = '\0';
	return (name);
}

int recup_x(char **input, int i, int j)
{
	char *xa = malloc(sizeof(char) * 1000);
	int f = 0;

	for (; input[i][j] != ' '; j++) {
		xa[f] = input[i][j];
		if (input[i][j] < '0' || input[i][j] > '9')
			return (-1);
		f++;
	}
	xa[f] = '\0';
	return (my_getnbr(xa));
}

int recup_y(char **input, int i, int j)
{
	char *ya = malloc(sizeof(char) * 1000);
	int f = 0;

	for (;input[i][j] != ' ' && input[i][j] != '\0'; j++) {
		ya[f] = input[i][j];
		if (input[i][j] < '0' || input[i][j] > '9')
			return (-1);
		f++;
	}
	ya[f] = '\0';
	return (my_getnbr(ya));
}

int verif_room_name(list_t **rooms, parse_t *parse, char **input, int i)
{
	char *name = malloc(sizeof(char) * (my_strlen(input[i]) + 1));
	int x = 0;
	int y = 0;
	int j = 0;

	j = 0;
	name = recup_name(input, i, j, name);
	j = move_j(input, i, j);
	x = recup_x(input, i, j);
	j = move_j(input, i, j);
	y = recup_y(input, i, j);
	if (x == -1 || y == -1 || name == NULL || str_num_and_alpha(name) == 1
	|| compare_names(*rooms, name) == 84 ||
	compare_positions(*rooms, x, y) == 84) {
		parse->error_parse = 1;
		return (84);
	}
	list_append(rooms, create_room(name, (pos_t){x, y}, parse->type));
	return (0);
}
