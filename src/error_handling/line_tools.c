/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** line tools error handling
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

int check_dash(char *input)
{
	if (input == NULL || input[0] == '#' || input[0] == '\n' || input[0] == '\0')
		return (0);
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '-')
			return (1);
	}
	return (0);
}

char *my_clear_str(char *str)
{
	char *cleaned = NULL;
	char littlestr[2] = "\0";
	int	tmp = 0;

	for (int i = 0; str != NULL && str[i] != '\0'; i++) {
		if ((str[i] == ' ' || str[i] == '\t') && !tmp)
			continue;
		if (tmp == 0)
			tmp = 1;
		littlestr[0] = str[i];
		cleaned = my_improved_strcat(cleaned, littlestr);
	}
	return (cleaned);
}

int	line_is_comment(char *line)
{
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ' || line[i] == '\t')
			continue;
		if (line[i] == '#')
			return (1);
		else
			break;
	}
	return (0);
}

room_t *get_room_from_name(list_t *rooms, char *name)
{
	list_t *tmp = rooms;
	room_t *room = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		room = (room_t*)tmp->data;
		if (my_streqstr(name, room->name))
			return (room);
	}
	return (NULL);
}
