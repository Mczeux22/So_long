/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:42:03 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 12:42:03 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	recup_image(t_maps *m)
{
	int	k;
	int	j;

	k = 32;
	j = 32;
	m->mur = mlx_xpm_file_to_image(m->mlx, "./xpm/wall.xpm", &k, &j);
	m->sol = mlx_xpm_file_to_image(m->mlx, "./xpm/empty.xpm", &k, &j);
	m->dol = mlx_xpm_file_to_image(m->mlx, "./xpm/collectible.xpm", &k, &j);
	m->perso = mlx_xpm_file_to_image(m->mlx, "./xpm/player_a1.xpm", &k, &j);
	m->pers2 = mlx_xpm_file_to_image(m->mlx, "./xpm/player_a2.xpm", &k, &j);
	m->exit = mlx_xpm_file_to_image(m->mlx, "./xpm/exit.xpm", &k, &j);
	if (!m->sol || !m->mur || !m->dol || !m->perso || !m->exit || !m->pers2)
		return (perror("Erreur chargement image\n"), 1);
	return (0);
}

void	make_map_third(t_maps *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->hauteur)
	{
		x = 0;
		while (x < m->largeur)
		{
			if (m->map[y][x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->dol, x * S, y * S);
			if (m->map[y][x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->pers2, x * S, y * S);
			if (m->map[y][x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->exit, x * S, y * S);
			x++;
		}
		y++;
	}
}

void	make_map_second(t_maps *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->hauteur)
	{
		x = 0;
		while (x < m->largeur)
		{
			if (m->map[y][x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->dol, x * S, y * S);
			if (m->map[y][x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->perso, x * S, y * S);
			if (m->map[y][x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->exit, x * S, y * S);
			x++;
		}
		y++;
	}
}

void	make_map_first(t_maps *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->hauteur)
	{
		x = 0;
		while (x < m->largeur)
		{
			if (m->map[y][x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->mur, x * S, y * S);
			else
				mlx_put_image_to_window(m->mlx, m->win, m->sol, x * S, y * S);
			x++;
		}
		y++;
	}
}

int	make_map(t_maps *m)
{
	int		j;

	j = 0;
	while (j < m->item_count)
	{
		if (m->player_y == m->item_y[j] && m->player_x == m->item_x[j])
		{
			make_map_first(m);
			make_map_third(m);
			return (0);
		}
		j++;
	}
	make_map_first(m);
	make_map_second(m);
	return (0);
}
