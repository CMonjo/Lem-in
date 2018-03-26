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
		if (tmp->type == START)
			my_printf("START\n");
		if (tmp->type == END)
			my_printf("END\n");
		my_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

int compare_positions(file_t *file, int x, int y)
{
	(void)file;
	(void)x;
	(void)y;
	// file_t *tmp = file;
	//
	// while (tmp != NULL) {
	// 	if (my_strcmp(tmp->name, name) == 1)
	// 		return (84);
	// 	tmp = tmp->next;
	// }
	return (0);
}

int compare_names(file_t *file, char *name)
{
	file_t *tmp = file;

	while (tmp != NULL) {
		if (my_strcmp(tmp->name, name) == 1)
			return (84);
		tmp = tmp->next;
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
