/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:29:06 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/19 15:53:56 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	t_data	data;

	ft_window(&data, 800, 600, "So_long");
	mlx_hook(data.mlx_win, 17, 0, ft_window_close, &data);
	mlx_key_hook(data.mlx_win, ft_linux_echap, &data);
	mlx_key_hook(data.mlx_win, ft_macos_echap, &data);
	mlx_loop(data.mlx_ptr);
	ft_initialisation(&data.items);
	return (0);
}
