/*
** EPITECH PROJECT, 2017
** task03
** File description:
** read
*/

#include "../../include/lemin.h"

char *my_read(void)
{
	char *map = malloc(sizeof(char));
	char *buffer = malloc(sizeof(char) * 4096);
	int rd;

	if (!map || !buffer)
		return (NULL);
	rd = read(0, buffer, 4094);
	map[0] = '\0';
	while (rd > 0) {
		buffer[rd] = '\0';
		map = my_strcat(map, buffer);
		if (!map)
			return (NULL);
		rd = read(0, buffer, 4094);
	}
	free(buffer);
	return (map);
}
