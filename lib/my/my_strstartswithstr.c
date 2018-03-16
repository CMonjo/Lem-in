/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** advanced lib
*/

int	my_strlen(char *str);
#include <stdio.h>

int	my_strstartswithstr(char *str2, char *str1)
{
	int	len1 = my_strlen(str1);
	int	len2 = my_strlen(str2);
	int	index = 0;

	if (len1 > len2)
		return (0);
	while (index <= len2) {
		if (str1[index] == '\0')
			return (1);
		else if (str1[index] != str2[index])
			return (0);
		index++;
	}
	return (0);
}
