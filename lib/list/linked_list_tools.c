/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** linked list add
*/

#include "list.h"

int	add_list(list_t **list, void *data)
{
	list_t *head = (list_t*)malloc(sizeof(list_t));

	head->data = data;
	head->next = *list;
	*list = head;
	return (0);
}

int	append_list(list_t	**list, void *data)
{
	list_t *_tmp = *list;
	list_t *end = (list_t*)malloc(sizeof(list_t));

	end->data = data;
	end->next = NULL;
	if (_tmp == NULL) {
		*list = end;
		return (0);
	}
	for (; _tmp != NULL; _tmp = _tmp->next) {
		if (_tmp->next == NULL) {
			_tmp->next = end;
			break;
		}
	}
	return (0);
}
