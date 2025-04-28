/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:19:56 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:19:56 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_exit_postion(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'E')
			{
				m->exit_x = j;
				m->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_player_postion(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'P')
			{
				m->player_x = j;
				m->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_item_postion(t_maps *m)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	init_item_tab(m);
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
			{
				m->item_x[pos] = j;
				m->item_y[pos] = i;
				pos++;
			}
			j++;
		}
		i++;
	}
}

void	init_item_tab(t_maps *m)
{
	m->item_x = ft_calloc(m->item_count, sizeof(int));
	if (m->item_x == NULL)
		return ;
	m->item_y = ft_calloc(m->item_count, sizeof(int));
	if (m->item_y == NULL)
	{
		free (m->item_x);
		return ;
	}
}
