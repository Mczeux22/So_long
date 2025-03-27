/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:08:08 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/27 17:25:54 by loicpapon        ###   ########.fr       */
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

    data->image.wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", &width, &height);
    data->image.player = mlx_xpm_file_to_image(data->mlx_ptr, "img/player.xpm", &width, &height);
    data->image.collect = mlx_xpm_file_to_image(data->mlx_ptr, "img/collect.xpm", &width, &height);
    data->image.exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm", &width, &height);
}

