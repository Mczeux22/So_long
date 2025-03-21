/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:29 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/21 13:06:38 by loicpapon        ###   ########.fr       */
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

	y = 0;
	while (x < datamap->width)
	{
		if (datamap->map[0][x] != 1 ||
				datamap->map[datamap->height - 1][x] != '1')
		{
			ft_printf("Error wall");
			exit(EXIT_FAILURE);
		}
		y = 0;
		while (y > datamap->height)
		{
        if (datamap->map[y][0] != '1' ||
				datamap->map[y][datamap->width - 1] != '1')
			{
				ft_printf("Map border wrong");
				exit(EXIT_FAILURE);
			}
			y++;
		}
	}
}

void	player_check(t_items *data, t_data *datamap)
{
	int	x;
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	while (y < datamap->width)
	{
		x = 0;
		while (x < datamap->height)
		{
			if (datamap->map[y][x] == data->player)
				player_count++;
			if (datamap->map[y][x] == data->wall)
				exit(ft_printf("Error player on wall"));
			x++;
		}
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
	exit_check(&data->items, data);
	wall_check(&data->items, data);
	player_check(&data->items, data);
	ft_printf("✅ Map validée avec succès !\n");
}
