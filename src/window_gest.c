/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:36 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/27 15:23:51 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_window(t_data *data, int width, int height, char *title)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error\n");
		exit (1);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->mlx_win)
	{
		ft_printf("Error\n");
		exit (1);
	}
}

int	ft_linux_echap(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit (0);
	}
	return (0);
}

int	ft_window_close(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
	return (0);
}
