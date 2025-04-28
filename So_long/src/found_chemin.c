/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:20:16 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:20:16 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_chemin_item(t_maps *m)
{
	int	i;

	i = 0;
	get_item_postion(m);
	while (i < m->item_count)
	{
		if (found_if_chemin_item(m, m->item_x[i], m->item_y[i]) == 0)
		{
			free(m->item_x);
			free(m->item_y);
			return (1);
		}
		i++;
	}
	return (0);
}

int	v_i(t_list *list, char **map, int n)
{
	t_list	*temp;

	temp = list;
	if (map[temp->y][temp->x + 1] != 'E' && n == 1)
		return (1);
	if (map[temp->y][temp->x - 1] != 'E' && n == 2)
		return (1);
	if (map[temp->y + 1][temp->x] != 'E' && n == 3)
		return (1);
	if (map[temp->y - 1][temp->x] != 'E' && n == 4)
		return (1);
	return (0);
}

int	found_if_chemin_item(t_maps *m, int target_x, int target_y)
{
	char	**map;
	t_list	*list;

	list = NULL;
	map = init_temp_map(m);
	create_node(&list, m->player_x, m->player_y);
	while (list != NULL)
	{
		if (list->x == target_x && list->y == target_y)
			return (free_map2(map), clear_list(&list), 1);
		if (map[list->y][list->x + 1] != '1' && v_i(list, map, 1) == 1)
			add_back(&list, list->x + 1, list->y);
		if (map[list->y][list->x - 1] != '1' && v_i(list, map, 2) == 1)
			add_back(&list, list->x - 1, list->y);
		if (map[list->y + 1][list->x] != '1' && v_i(list, map, 3) == 1)
			add_back(&list, list->x, list->y + 1);
		if (map[list->y - 1][list->x] != '1' && v_i(list, map, 4) == 1)
			add_back(&list, list->x, list->y - 1);
		map[list->y][list->x] = '1';
		delate_first(&list);
	}
	free_map2(map);
	clear_list(&list);
	return (0);
}
