/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:29:06 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/31 20:23:280 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Could not open file %s\n", argv[1]);
		return (1);
	}
	ft_initialisation(&data.items);
	ft_setmap(&data);
	if (!map_parseur(&data, fd))
	{
		ft_printf("Error: Invalid map\n");
		close(fd);
		return (1);
	}
	close(fd);
	map_validation(&data);
	ft_printf("Player found at (%d, %d)\n", data.plapos.x, data.plapos.y);

    // Vérification des règles du jeu (chemin valide, collectibles, etc.)
    // if (!map_validation(&data))
    // {
    //     ft_printf("Error: No valid path between player and exit.\n");
    //     ft_free(&data);
    //     return (1);
    // }

    // Initialisation + fenêtre + images
    ft_window(&data, data.width * 32, data.height * 32, "So_long");
    load_images(&data);
	if (check_load_images(&data))
	{
		ft_printf("Error: Failed to load images.\n");
		ft_free(&data);
		return (1);
	}
    // Appel initial supprimé
    // draw_map(&data);

    // Redessiner à chaque "loop frame"
    mlx_loop_hook(data.mlx_ptr, draw_map, &data);

    // Gestion fermeture et touches
    mlx_hook(data.mlx_win, 17, 0, ft_window_close, &data);
    mlx_key_hook(data.mlx_win, keypress, &data);
    mlx_loop(data.mlx_ptr);

    // Libération des ressources
    ft_free(&data);
    return (0);
}
