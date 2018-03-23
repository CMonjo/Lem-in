/*
** EPITECH PROJECT, 2017
** task03
** File description:
** read
*/

#include "../../include/lemin.h"

char *my_read(char *path)
{
	char *map = malloc(sizeof(char));
	char *buffer = malloc(sizeof(char) * 4096);
	int fd = open(path, O_RDONLY);
	int rd;

	if (!map || !buffer || fd < 0)
		return (NULL);
	rd = read(fd, buffer, 4094);
	map[0] = '\0';
	while (rd > 0) {
		buffer[rd] = '\0';
		map = my_strcat(map, buffer);
		if (!map)
			return (NULL);
		rd = read(fd, buffer, 4094);
	}
	close(fd);
	free(buffer);
	return (map);
}
