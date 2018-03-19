/*
** EPITECH PROJECT, 2017
** strcat
** File description:
** task 2
*/

#include <stdlib.h>

int my_str_len(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}

char *my_strcat(char *str1, char *str2)
{
	int len = my_str_len(str1) + my_str_len(str2) + 1;
	char *dest = malloc(sizeof(char) * len);
	int i = 0;
	int j = 0;

	if (!dest)
		return (NULL);
	while (str1[i] != '\0') {
		dest[i] = str1[i];
		i ++;
	}
	while (str2[j] != '\0') {
		dest[i] = str2[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	free(str1);
	return (dest);
}
