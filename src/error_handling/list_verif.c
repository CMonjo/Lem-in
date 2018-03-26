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
		printf("%s\n", tmp->name);
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

void create_file_element_file(file_t **file, pos_t pos, char *name)
{
	file_t *new = malloc(sizeof(file_t));

	new->name = name;
	new->pos = pos;
	new->next = *file;
	*file = new;
}
