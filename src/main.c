/*
** EPITECH PROJECT, 2017
** Project lemin
** File description:
** Main
*/

#include "../include/lemin.h"

void disp_path(list_t *path);

room_t	*test_map(room_t *end)
{
	room_t *pleurope1 = create_room("PL. DE L'EUROPE T1", (pos_t){0, 0});
	room_t *pleurope4 = create_room("PL. DE L'EUROPE T4", (pos_t){0, 0});
	room_t *rives3 = create_room("RIVES DU LEZ T3", (pos_t){0, 0});
	room_t *rives4 = create_room("RIVES DU LEZ T4", (pos_t){0, 0});
	room_t *rives1 = create_room("RIVES DU LEZ T1", (pos_t){0, 0});
	room_t *moulares1 = create_room("MOULARÈS (HÔTEL DE VILLE) T1", (pos_t){0, 0});
	room_t *moulares3 = create_room("MOULARÈS (HÔTEL DE VILLE) T3", (pos_t){0, 0});
	room_t *freche4 = create_room("GEORGES FRÊCHE - HÔTEL DE VILLE T4", (pos_t){0, 0});
	//room_t *portmarianne1 = create_room("PORT MARIANNE T1", (pos_t){0, 0});
	room_t *portmarianne3 = create_room("PORT MARIANNE T3", (pos_t){0, 0});

	//PL EUROPE
	connect_room_to_room(pleurope1, rives1);
	connect_room_to_room(pleurope1, pleurope4);
	connect_room_to_room(pleurope4, rives4);

	//RIVES
	connect_room_to_room(rives3, moulares3);
	connect_room_to_room(rives1, moulares1);
	connect_room_to_room(rives1, rives3);
	connect_room_to_room(rives1, rives4);
	connect_room_to_room(rives3, rives4);
	connect_room_to_room(rives4, freche4);

	//MOULARES
	connect_room_to_room(moulares3, portmarianne3);
	connect_room_to_room(moulares1, end);
	//connect_room_to_room(freche4, moulares1);
	//onnect_room_to_room(freche4, moulares3);
	connect_room_to_room(moulares1, moulares3);

	connect_room_to_room(portmarianne3, end);

	return (rives1);
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (84);
	// room_t *end = create_room("PORT MARIANNE T1", (pos_t){0, 0});
	create_map();
	// room_t *testmap = test_map(end);
	// list_t *pathsV2 = NULL;
	// list_t *paths = get_all_paths(&paths, NULL, testmap, end);
	// list_t *pathscpy = paths;
	//
	// if (paths == NULL)
	// 	my_printf("PATHS NULL\n");
	// my_printf("\n§§§$$$--$$$§§§\n[%s -> %s]\nFOUND PATHS :\n", testmap->name, end->name);
	// for (; pathscpy != NULL; pathscpy = pathscpy->next) {
	// 	my_printf(" • ");
	// 	disp_path((list_t*)pathscpy->data);
	// }
	// my_printf("\n----\nSHORTEST:\n\n • ");
	// list_t *shortest = get_shortest_available_path(paths);
	// disp_path(shortest);
	// ((room_t*)shortest->next->data)->occuped = 1;
	// my_printf("\n\nSET AS OCCUPED. NEXT SHORTEST:\n\n • ");
	// shortest = get_shortest_available_path(paths);
	// disp_path(shortest);
	// ((room_t*)shortest->next->data)->occuped = 1;
	// my_printf("\n\nSET AS OCCUPED. NEXT SHORTEST:\n\n • ");
	// shortest = get_shortest_available_path(paths);
	// disp_path(shortest);
	return (0);
}
