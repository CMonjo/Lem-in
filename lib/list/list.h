/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** linkedlist header
*/

#ifndef __LIST_LIB_H__
#define __LIST_LIB_H__

#include <stdlib.h>

typedef struct list_s list_t;
typedef struct intlist_s intlist_t;

struct list_s {
	void *data;
	list_t *next;
};

struct intlist_s {
	int	value;
	intlist_t *next;
};

//Add
int	add_list(list_t **list, void *data);
int	add_int_list(intlist_t **list, int value);

//Append
int	append_list(list_t	**list, void *data);
int	append_int_list(intlist_t **list, int value);


#endif /* LIST_LIB_H_ */
