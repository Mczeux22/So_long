/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:20:01 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:20:01 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_x(t_maps *m)
{
	m->pos_player_x = m->player_x;
}

void	pos_y(t_maps *m)
{
	m->pos_player_y = m->player_y;
}

void	print_move(t_maps *m)
{
	m->count_move ++;
	ft_printf("%d\n", m->count_move);
}

void	play_game_2(int keycode, t_maps *m)
{
	if (keycode == 119)
	{
		move_up(m);
		if (m->player_y != m->pos_player_y)
			print_move(m);
	}
	else if (keycode == 115)
	{
		move_down(m);
		if (m->player_y != m->pos_player_y)
			print_move(m);
	}
}

void	play_game(int keycode, t_maps *m)
{
	pos_y(m);
	pos_x(m);
	if (keycode == 97)
	{
		move_left(m);
		if (m->player_x != m->pos_player_x)
			print_move(m);
	}
	else if (keycode == 100)
	{
		move_right(m);
		if (m->player_x != m->pos_player_x)
			print_move(m);
	}
	play_game_2(keycode, m);
}
