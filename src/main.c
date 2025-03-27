/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:29:06 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/27 17:29:34 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
    t_data	data;
    int		fd;

    // Vérification des arguments
    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }

    // Ouverture du fichier de la carte
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: Could not open file %s\n", argv[1]);
        return (1);
    }

    // Initialisation des structures
    ft_initialisation(&data.items);
    ft_setmap(&data);

    // Lecture et validation de la carte
    if (!map_parseur(&data, fd))
    {
        ft_printf("Error: Invalid map\n");
        close(fd);
        return (1);
    }
    close(fd);

    // Vérification des règles du jeu (chemin valide, collectibles, etc.)
    if (!is_path_valid(&data))
    {
        ft_printf("Error: No valid path between player and exit.\n");
        ft_free(&data);
        return (1);
    }

    // Création de la fenêtre et chargement des images
    ft_window(&data, data.width * 32, data.height * 32, "So_long");
    load_images(&data);

    // Dessin initial de la carte
    draw_map(&data);

    // Gestion des événements (clavier, fermeture de la fenêtre)
    mlx_hook(data.mlx_win, 17, 0, ft_window_close, &data); // Fermeture de la fenêtre
    mlx_key_hook(data.mlx_win, keypress, &data);           // Gestion des touches
    mlx_loop(data.mlx_ptr);                                // Boucle principale de la MiniLibX

    // Libération des ressources
    ft_free(&data);
    return (0);
}
