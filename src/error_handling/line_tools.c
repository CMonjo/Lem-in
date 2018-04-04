/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** line tools error handling
*/

#include "../../include/lemin.h"
#include "../../include/my.h"
#include "../../include/list.h"

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
	my_printf("$line: %s\n", line);
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ' || line[i] == '\t')
			continue;
		if (line[i] == '#') {
			my_printf("IS COMMENT\n");
			return (1);
		} else {
			my_printf("ISN'T COMMENT\n");
			break;
		}
	}
	return (0);
}
