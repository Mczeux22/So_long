/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_exit_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:20:23 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 12:39:12 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_exit_path(t_maps *m)
{
	if (found_exit(m, m->exit_x, m->exit_y) == 0)
		return (1);
	else
		return (0);
}

char	**init_temp_map(t_maps *m)
{
	char	**copie;
	int		i;
	int		j;

	i = 0;
	copie = ft_calloc(m->hauteur + 1, sizeof(char *));
	if (copie == NULL)
		return (NULL);
	while (i < m->hauteur)
	{
		j = 0;
		copie[i] = ft_calloc(m->largeur + 1, sizeof(char));
		if (copie[i] == NULL)
			return (ft_free(copie, j), NULL);
		while (j < m->largeur && m->map[i][j] != '\n')
		{
			copie[i][j] = m->map[i][j];
			j++;
		}
		i++;
	}
	return (copie);
}

int	found_exit(t_maps *m, int target_x, int target_y)
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
		if (map[list->y][list->x + 1] != '1')
			add_back(&list, list->x + 1, list->y);
		if (map[list->y][list->x - 1] != '1')
			add_back(&list, list->x - 1, list->y);
		if (map[list->y + 1][list->x] != '1')
			add_back(&list, list->x, list->y + 1);
		if (map[list->y - 1][list->x] != '1')
			add_back(&list, list->x, list->y - 1);
		map[list->y][list->x] = '1';
		delate_first(&list);
	}
	free_map2(map);
	clear_list(&list);
	return (0);
}
