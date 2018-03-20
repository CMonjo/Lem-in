/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** input
*/

#include "lemin.h"

/* PSEUDO CODE DECRIVAnT LA GESTION D'ERREUR + GESTION D'ERREUR AVEC PRINTF */

// int verif_file(char **file)
// {
// 	if (file[0] != nombre_fourmis)
// 	if (file[1] != start)
// 	while (file[i] != end)
// 		if (file[i][j] != name && file[i][j + 1] != x && file[i][j + 2] != y)
// 	if (file[i + 1] != latest room)
//
// 	return (0);
// }

// int verif_room_propriety(char **file, int i)
// {
// 	int j = 0;
//
// 	for (;file[i][j] != ' '; j++) {
// 		printf("1er for : file[%d][%d] = %c\n", i, j, file[i][j]);
// 		if (file[i][j] == '\0')
// 			return (84);
// 	}
// 	j++;
// 	for (;file[i][j] != ' '; j++) {
// 		printf("2e for : file[%d][%d] = %c\n", i, j, file[i][j]);
// 		if (file[i][j] < '0' || file[i][j] > '9' || file[i][j] == '\0')
// 			return (84);
// 	}
// 	j++;
// 	for (;file[i][j] != ' ' && file[i][j] == '\0'; j++) {
// 		printf("3e for : file[%d][%d] = %c\n", i, j, file[i][j]);
// 		if (file[i][j] < '0' || file[i][j] > '9')
// 			return (84);
// 	}
// 	printf("%s\n", "fin de room propriety");
// 	return (0);
// }
//
// int verif_file(char **file)
// {
// 	int i = 1;
//
// 	printf("%s\n", "dans verif file");
// 	printf("file[0][0] = %c et file[1][1] = %c\n", file[0][0], file[0][1]);
// 	if ((file[0][0] < '0' || file[0][0] >'9') && (file[0][1] < '0' ||
// 	file[0][1] >'9'))
// 		return (84);
// 	printf("%s\n", "premiere condition passée");
// 	printf("file[1] = %s\n", file[1]);
// 	for (;my_strcmp(file[i], "##start") == 1 && file[i] != NULL; i++) {
// 		if (file[i][0] != '#' && verif_room_propriety(file, i) == 84)
// 			return (84);
// 	}
// 	printf("%s\n", "condition de start passé");
// 	for (; my_strcmp(file[i], "##end") == 1 && file[i] != NULL;
// 	i++) {
// 		printf("dans la boucle, file[%d] = %s\n", i, file[i]);
// 		if (file[i][0] != '#' && verif_room_propriety(file, i) == 84)
// 			return (84);
// 	}
// 	printf("%s\n", "condition d'end passé");
// 	i++;
// 	if (verif_room_propriety(file, i) == 84)
// 		return (84);
// 	printf("%s\n", "fin de verif file");
// 	return (0);
// }

int verif_room_propriety(char **file, int i)
{
	int j = 0;

	for (;file[i][j] != ' '; j++) {
		printf("1er for : file[%d][%d] = %c\n", i, j, file[i][j]);
		if (file[i][j] == '\0')
			return (84);
	}
	j++;
	for (;file[i][j] != ' '; j++) {
		printf("2e for : file[%d][%d] = %c\n", i, j, file[i][j]);
		if (file[i][j] < '0' || file[i][j] > '9' || file[i][j] == '\0')
			return (84);
	}
	j++;
	for (;file[i][j] != ' ' && file[i][j] == '\0'; j++) {
		printf("3e for : file[%d][%d] = %c\n", i, j, file[i][j]);
		if (file[i][j] < '0' || file[i][j] > '9')
			return (84);
	}
	printf("%s\n", "fin de room propriety");
	return (0);
}

int verif_file(char **file)
{
	int i = 1;

	printf("%s\n", "dans verif file");
	printf("file[0][0] = %c et file[1][1] = %c\n", file[0][0], file[0][1]);
	if ((file[0][0] < '0' || file[0][0] >'9') && (file[0][1] < '0' ||
	file[0][1] >'9'))
		return (84);
	for (; file[i] != NULL; i++) {
		if (file[i][0] != '#') {
			verif_room_propriety(file, i);
		}
	}
	return (0);
}
