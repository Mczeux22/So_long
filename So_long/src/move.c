/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:20:31 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:21:35 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_maps *m)
{
	if (m->map[m->player_y][m->player_x - 1] != '1'
		&& m->map[m->player_y][m->player_x - 1] != 'E')
	{
		if (m->map[m->player_y][m->player_x - 1] == '0')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_x --;
			m->map[m->player_y][m->player_x] = 'P';
		}
		else if (m->map[m->player_y][m->player_x - 1] == 'C')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_x --;
			m->map[m->player_y][m->player_x] = 'P';
			m->check ++;
		}
	}
	else if (m->map[m->player_y][m->player_x - 1] == 'E'
		&& m->check == m->item_count)
	{
		m->map[m->player_y][m->player_x] = '0';
		m->player_x --;
		m->map[m->player_y][m->player_x] = 'P';
		finish_game(m);
	}
}

void	move_right(t_maps *m)
{
	if (m->map[m->player_y][m->player_x + 1] != '1'
		&& m->map[m->player_y][m->player_x + 1] != 'E')
	{
		if (m->map[m->player_y][m->player_x + 1] == '0')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_x ++;
			m->map[m->player_y][m->player_x] = 'P';
		}
		else if (m->map[m->player_y][m->player_x + 1] == 'C')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_x ++;
			m->map[m->player_y][m->player_x] = 'P';
			m->check ++;
		}
	}
	else if (m->map[m->player_y][m->player_x + 1] == 'E'
		&& m->check == m->item_count)
	{
		m->map[m->player_y][m->player_x] = '0';
		m->player_x ++;
		m->map[m->player_y][m->player_x] = 'P';
		finish_game(m);
	}
}

void	move_up(t_maps *m)
{
	if (m->map[m->player_y - 1][m->player_x] != '1'
		&& m->map[m->player_y - 1][m->player_x] != 'E')
	{
		if (m->map[m->player_y - 1][m->player_x] == '0')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_y --;
			m->map[m->player_y][m->player_x] = 'P';
		}
		else if (m->map[m->player_y - 1][m->player_x] == 'C')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_y --;
			m->map[m->player_y][m->player_x] = 'P';
			m->check ++;
		}
	}
	else if (m->map[m->player_y - 1][m->player_x] == 'E'
		&& m->check == m->item_count)
	{
		m->map[m->player_y][m->player_x] = '0';
		m->player_y --;
		m->map[m->player_y][m->player_x] = 'P';
		finish_game(m);
	}
}

void	move_down(t_maps *m)
{
	if (m->map[m->player_y + 1][m->player_x] != '1'
		&& m->map[m->player_y + 1][m->player_x] != 'E')
	{
		if (m->map[m->player_y + 1][m->player_x] == '0')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_y ++;
			m->map[m->player_y][m->player_x] = 'P';
		}
		else if (m->map[m->player_y + 1][m->player_x] == 'C')
		{
			m->map[m->player_y][m->player_x] = '0';
			m->player_y ++;
			m->map[m->player_y][m->player_x] = 'P';
			m->check ++;
		}
	}
	else if (m->map[m->player_y + 1][m->player_x] == 'E'
		&& m->check == m->item_count)
	{
		m->map[m->player_y][m->player_x] = '0';
		m->player_y ++;
		m->map[m->player_y][m->player_x] = 'P';
		finish_game(m);
	}
}
