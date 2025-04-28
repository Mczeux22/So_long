/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:29:32 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:30:55 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h" // MiniLibX pour la gestion graphique
# include "libft.h" // Votre bibliothèque personnelle

// Taille des cases (probablement définie dans votre projet)
# define S 32

// Structure pour représenter un nœud de liste chaînée
typedef struct s_list
{
    int				x;
    int				y;
    struct s_list	*next;
}	t_list;

// Structure principale contenant toutes les données du jeu
typedef struct s_maps
{
    char	**map;         // Carte du jeu
    int		largeur;       // Largeur de la carte
    int		hauteur;       // Hauteur de la carte
    int		nb_case;       // Nombre total de cases
    int		item_count;    // Nombre de collectibles
    int		count_move;    // Nombre de déplacements du joueur
    int		check;         // Collectibles ramassés
    int		player_x;      // Position X du joueur
    int		player_y;      // Position Y du joueur
    int		pos_player_x;  // Position précédente X du joueur
    int		pos_player_y;  // Position précédente Y du joueur
    int		exit_x;        // Position X de la sortie
    int		exit_y;        // Position Y de la sortie
    int		*item_x;       // Tableau des positions X des collectibles
    int		*item_y;       // Tableau des positions Y des collectibles
    void	*mlx;          // Pointeur MiniLibX
    void	*win;          // Fenêtre MiniLibX
    void	*mur;          // Image pour les murs
    void	*sol;          // Image pour le sol
    void	*dol;          // Image pour les collectibles
    void	*perso;        // Image pour le joueur
    void	*pers2;        // Image alternative pour le joueur
    void	*exit;         // Image pour la sortie
}	t_maps;

// Prototypes des fonctions

// main.c
void	free_param(t_maps *m);
int		close_window_by_x(t_maps *m);

// parsing.c
int		get_map(t_maps *m, char *av);
int		verif_nb_charac(t_maps *m);
int		verif_mur(t_maps *m);
int		verif_file(char **av);
int		verif_map(t_maps *m);

// utils.c
void	*ft_free(char **str, size_t j);
void	*ft_calloc(size_t count, size_t size);
void	print_list(t_list *list);
void	free_map2(char **map);
void	free_map(t_maps *m);

// list.c
t_list	*create_node(t_list **list, int x, int y);
void	add_back(t_list **list, int x, int y);
void	delate_first(t_list **list);
void	clear_list(t_list **list);

// info_map.c
int		verif_charac(t_maps *m);
int		count_item(t_maps *m);
int		count_player(t_maps *m);
int		count_exit(t_maps *m);
int		get_size_map(t_maps *m);

// image.c
int		recup_image(t_maps *m);
void	make_map_first(t_maps *m);
void	make_map_second(t_maps *m);
void	make_map_third(t_maps *m);
int		make_map(t_maps *m);

// game.c
void	pos_x(t_maps *m);
void	pos_y(t_maps *m);
void	print_move(t_maps *m);
void	play_game_2(int keycode, t_maps *m);
void	play_game(int keycode, t_maps *m);

// do_move.c
void	move_left(t_maps *m);
void	move_right(t_maps *m);
void	move_up(t_maps *m);
void	move_down(t_maps *m);

// found_chemin.c
int		verif_chemin_item(t_maps *m);
int		found_if_chemin_item(t_maps *m, int target_x, int target_y);

// found_chemin_exit.c
int		verif_chemin_exit(t_maps *m);
int		found_if_chemin_exit(t_maps *m, int target_x, int target_y);

// get_all_position.c
void	get_exit_postion(t_maps *m);
void	get_player_postion(t_maps *m);
void	get_item_postion(t_maps *m);
void	init_item_tab(t_maps *m);

#endif