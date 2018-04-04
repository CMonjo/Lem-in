/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** line tools error handling
*/

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
