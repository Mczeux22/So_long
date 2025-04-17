/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:29 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/17 19:16:42 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	collect_check(t_data *data)
{
	int	x;
	int	y;
	int	collect_count;

	y = 0;
	collect_count = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == data->items.collect)
				collect_count++;
			x++;
		}
		y++;
	}
	if (collect_count == 0)
	{
		ft_printf("Error: No collectibles found on the map.\n");
		exit(EXIT_FAILURE);
	}
}

void	exit_check(t_items *data, t_data *datamap)
{
	int	x;
	int	y;
	int	exit_count;

	y = 0;
	exit_count = 0;
	while (y < datamap->height)
	{
		x = 0;
		while (x < datamap->width)
		{
			if (datamap->map[y][x] == data->exit)
				exit_count++;
			x++;
		}
		y++;
	}
	if (exit_count == 0 || exit_count > 1)
	{
		ft_printf("Error : Exit wrong\n");
		exit(EXIT_FAILURE);
	}
}

void	wall_check(t_items *data, t_data *datamap)
{
	int	x;
	int	y;

	x = 0;
	while (x < datamap->width)
	{
		if (datamap->map[0][x] != data->wall ||
				datamap->map[datamap->height - 1][x] != data->wall)
		{
			ft_printf("Error: check wall %d\n", x);
			exit(EXIT_FAILURE);
		}
		x++;
	}
	y = 0;
	while (y < datamap->height)
	{
		if (datamap->map[y][0] != data->wall ||
				datamap->map[y][datamap->width - 1] != data->wall)
		{
			ft_printf("Error: Left or right wall is incorrect at row %d\n", y);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	player_check(t_data *data, t_data *datamap)
{
	int	x;
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	while (y < datamap->height)
	{
		x = 0;
		while (x < datamap->width)
		{
			ft_printf("%c", datamap->map[y][x]);
			// ft_printf("x = %d, y = %d\n", x, y);
			if (datamap->map[y][x] == data->items.player)
			{
				player_count++;
				data->plapos.x = x;
				data->plapos.y = y;
				// ft_printf("Player found at (%d, %d)\n", x, y);
			}
			// if (datamap->map[y][x] == data->items.wall)
			// 	exit(ft_printf("Error player on wall"));
			x++;
		}
		ft_printf("\n");
		y++;
	}
	if (player_count == 0 || player_count > 1)
	{
		ft_printf("Error : player wrong\n");
		exit(EXIT_FAILURE);
	}
}

void	map_validation(t_data *data)
{
	collect_check(data);
	ft_printf("✅ Collectibles validés avec succès !\n");
	exit_check(&data->items, data);
	ft_printf("✅ Sortie validée avec succès !\n");
	wall_check(&data->items, data);
	ft_printf("✅ Murs validés avec succès !\n");
	player_check(data, data);
	ft_printf("✅ Map validée avec succès !\n");
}
