/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:19:04 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:22:03 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_charac(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] != '0' && m->map[i][j] != '1'
				&& m->map[i][j] != 'C' && m->map[i][j] != 'E'
				&& m->map[i][j] != 'P' && m->map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_item(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	m->item_count = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				m->item_count++;
			j++;
		}
		i++;
	}
	return (m->item_count);
}

int	count_player(t_maps *m)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	get_player_postion(m);
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_exit(t_maps *m)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	get_exit_postion(m);
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	get_size_map(t_maps *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m->hauteur = 0;
	while (m->map[i][j] != '\n')
		j++;
	m->largeur = j;
	while (m->map[i])
		i++;
	m->hauteur = i;
	m->nb_case = m->hauteur * m->largeur;
	if (m->hauteur == m->largeur)
		return (1);
	else
		return (0);
}
