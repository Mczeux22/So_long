/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:30 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/20 16:03:16 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

void	draw_map(t_data *data)
{
	t_img_data	img_data;
	int			x;
	int			y;

    // Créer une image vide de la taille de la carte
    // img_data.img = mlx_new_image(data->mlx_ptr, data->width * 32, data->height * 32);
    // img_data.data = mlx_get_data_addr(img_data.img, &img_data.bpp, &img_data.size_line, &img_data.endian);

    // Parcourir la carte et dessiner les tuiles correspondantes
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == data->items.wall)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.wall.img, x * 32, y * 32);
			// else if (data->map[y][x] == data->items.player)
			//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.player_a1.img, x * 32, y * 32);
			else if (data->map[y][x] == data->items.collect)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.collectible.img, x * 32, y * 32);
			else if (data->map[y][x] == data->items.exit)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.exit.img, x * 32, y * 32);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.empty.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.player_a1.img, data->plapos.x * 32, data->plapos.y * 32);
    // Retourner l'image créée
    // return (img_data.img);
}
