/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:12:56 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/31 20:3:29 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypress(int keycode, t_data *data)
{
	int	playerX = data->plapos.x;
	int	playerY = data->plapos.y;

	ft_linux_echap(keycode, data);
	if (keycode == 119)
		playerY -= 1;
	else if (keycode == 115)
		playerY += 1;
	else if (keycode == 97)
		playerX -= 1;
	else if (keycode == 100)
		playerX += 1;

	// Gestion des collisions
	if (data->map[playerY][playerX] == data->items.wall)
	{
		ft_printf("Error: Collision with wall at (%d, %d)\n", playerX, playerY);
		return (0);
	}
	else if (data->map[playerY][playerX] == data->items.collect)
	{
		data->map[playerY][playerX] = data->items.space;
		data->items.count_c--;
	}
	else if (data->map[playerY][playerX] == data->items.exit)
	{
		if (data->items.count_c == 0)
			exit(0);
	}
	data->plapos.x = playerX;
	data->plapos.y = playerY;
		
	// img_creator(data);
	// draw_map(data);
	ft_printf("Moves: %d\n", data->move_count);
	ft_printf("Player position: (%d, %d)\n", data->plapos.x, data->plapos.y);
	return (0);
}