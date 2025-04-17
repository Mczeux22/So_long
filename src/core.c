/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:08:08 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/31 20:09:28 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_initialisation(t_items *ini)
{
	ini->exit = 'E';
	ini->player = 'P';
	ini->collect = 'C';
	ini->wall = '1';
	ini->space = '0';
	ini->count_p = 0;
	ini->count_e = 0;
	ini->count_c = 0;
}

void	ft_setmap(t_data *data)
{
	data->width = 0;
	data->height = 0;
	data->move_count = 0;
	data->map = NULL;
}

void	load_images(t_data *data)
{
	int	width;
	int	height;

	data->imgs.empty.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/empty.xpm",
			&data->imgs.empty.width, &data->imgs.empty.height);
	data->imgs.player_a1.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/player_a1.xpm",
			&data->imgs.player_a1.width, &data->imgs.player_a1.height);
	data->imgs.player_a2.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/player_a2.xpm",
			&data->imgs.player_a2.width, &data->imgs.player_a2.height);
	data->imgs.wall.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/wall.xpm",
			&data->imgs.wall.width, &data->imgs.wall.height);
	data->imgs.collectible.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/collectible.xpm",
			&data->imgs.collectible.width, &data->imgs.collectible.height);
	data->imgs.exit.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "images/exit.xpm",
			&data->imgs.exit.width, &data->imgs.exit.height);
}

int	check_load_images(t_data *data)
{
	if (!data->imgs.empty.img || !data->imgs.player_a1.img
		|| !data->imgs.player_a2.img || !data->imgs.wall.img
		|| !data->imgs.collectible.img || !data->imgs.exit.img)
	{
		ft_printf("Error: Failed to load images.\n");
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}
