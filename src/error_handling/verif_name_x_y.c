/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

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

int verif_room_name(file_t **file, parse_t *parse, char **input, int i)
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
	if (x == -1 || y == -1 || name == NULL || str_num_and_alpha(name) == 1)
		return (84);
	//printf("parse %d\n", parse->type);
	create_file_element(file, (pos_t){x, y}, name, parse->type);
	return (0);
}
