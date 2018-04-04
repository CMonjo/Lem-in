/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

void print_link(file_t *file)
{
	file_t *tmp = file;

	while (tmp != NULL) {
		my_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	my_printf("\n");
}

int compare_connections(file_t *file, char **input, int in)
{
	file_t *tmp = file;
	char **connect = my_str_split(input[in], '-');
	int i = 0;

	for (;connect[i] != NULL; i++);
	if (i != 2)
		return (84);
	if (my_strcmp(connect[0], connect[1]) == 1)
		return (0);
	for (i = 0; tmp != NULL; tmp = tmp->next)
		if (my_strcmp(connect[0], tmp->name) == 1 ||
		my_strcmp(connect[1], tmp->name) == 1)
			i += 1;
	//printf("i: %d\n", i);
	//if (i == 2)
		//add in list la connexion
	return (0);
}

int compare_positions(file_t *file)
{
	file_t *i = file;
	file_t *j = file;

	while (i != NULL) {
		j = i->next;
		while (j != NULL) {
			if (my_strcmp(i_to_a(i->pos.x),
			i_to_a(j->pos.x)) == 1 && my_strcmp(i_to_a(i->pos.y),
			i_to_a(j->pos.y)) == 1 &&
			i->name != j->name)
				return (84);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int compare_names(file_t *file)
{
	file_t *i = file;
	file_t *j = file;
	int verif = 0;

	while (i != NULL) {
		j = i->next;
		while (j != NULL) {
			verif += my_strcmp(i->name, j->name);
			j = j->next;
		}
		i = i->next;
	}
	if (verif != 0)
		return (84);
	return (0);
}

void create_file_element(file_t **file, pos_t pos, char *name, int enum_type)
{
	file_t *new = malloc(sizeof(file_t));

	new->name = name;
	// FAIRE DANS LE .H LA DECLARATION DES VALEURS 0 1 2
	enum_type == 0 ? new->type = MIDDLE : 0;
	enum_type == 1 ? new->type = START : 0;
	enum_type == 2 ? new->type = END : 0;
	new->pos = pos;
	new->next = *file;
	*file = new;
}
