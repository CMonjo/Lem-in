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
		my_printf("%s, x = %d et y = %d\n", tmp->name, tmp->pos.x, tmp->pos.y);
		tmp = tmp->next;
	}
}

int compare_connexions(file_t *file, char **input)
{
	int i = 0;

	//CAST FILE
	(void)file;
	for (int a = 0;  a == 0 && input[i] != NULL; i++) {
		for (int j = 0; input[i][j] != '\0'; j++) {
			input[i][j] == '-' ? a = 1 : 0;
		}
		a == 1 ? i -= 1 : 0;
	}
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
			i->name != j->name) {
				my_printf("Error same pos\n");
				return (84);
			}
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
	if (verif != 0) {
		my_printf("Error same name\n");
		return (84);
	}
	return (0);
}

void create_file_element(file_t **file, pos_t pos, char *name, int enum_type)
{
	file_t *new = malloc(sizeof(file_t));

	new->name = name;
	enum_type == 0 ? new->type = MIDDLE : 0;
	enum_type == 1 ? new->type = START : 0;
	enum_type == 2 ? new->type = END : 0;
	new->pos = pos;
	new->next = *file;
	*file = new;
}
