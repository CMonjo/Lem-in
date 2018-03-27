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
}

int compare_positions(file_t *file)
{
	(void)file;
	// file_t *tmp = file;
	//
	// while (tmp != NULL) {
	// 	if (my_strcmp(tmp->name, name) == 1)
	// 		return (84);
	// 	tmp = tmp->next;
	// }
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
