/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

int str_num_and_alpha(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z'
		&& str[i] >= 'A') || (str[i] < 58 && str[i] > 47))
			i += 1;
		else
			return (1);
	}
	return (0);
}
