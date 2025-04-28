/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:55:56 by Lopapon           #+#    #+#             */
/*   Updated: 2025/04/28 00:55:56 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image2(t_maps *m)
{
	if (m->perso)
	{
		mlx_destroy_image(m->mlx, m->perso);
		m->perso = NULL;
	}
	if (m->pers2)
	{
		mlx_destroy_image(m->mlx, m->pers2);
		m->pers2 = NULL;
	}
	if (m->exit)
	{
		mlx_destroy_image(m->mlx, m->exit);
		m->exit = NULL;
	}
}

void	free_image(t_maps *m)
{
	if (m->mur)
	{
		mlx_destroy_image(m->mlx, m->mur);
		m->mur = NULL;
	}
	if (m->sol)
	{
		mlx_destroy_image(m->mlx, m->sol);
		m->sol = NULL;
	}
	if (m->dol)
	{
		mlx_destroy_image(m->mlx, m->dol);
		m->dol = NULL;
	}
	free_image2(m);
}

int	close_window(int keycode, t_maps *m)
{
	if (keycode == 65307)
		return (finish_game(m), 0);
	play_game(keycode, m);
	mlx_clear_window(m->mlx, m->win);
	make_map(m);
	return (0);
}

void	finish_game(t_maps *m)
{
	mlx_destroy_window(m->mlx, m->win);
	free_image(m);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	free(m->item_x);
	free(m->item_y);
	free_map(m);
	free(m);
	exit(0);
}

int	init_window(t_maps *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (free_param(m), 1);
	m->win = mlx_new_window(m->mlx, m->largeur * 32,
			m->hauteur * 32, "So_long");
	if (!m->win)
		return (free(m->mlx), free_param(m), 1);
	recup_image(m);
	make_map(m);
	pos_y(m);
	pos_x(m);
	mlx_key_hook(m->win, close_window, m);
	mlx_hook(m->win, 17, 0, close_window_by_x, m);
	mlx_loop(m->mlx);
	return (0);
}
