/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:18:22 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/27 18:18:13 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

typedef struct data_s
{
	void	*mlx_ptr; // fonction minilibx
	void	*mlx_win; //fonction minilibx
	int		width; // largeur de la fenetre
	int		height; // hauteur de la fenetre
	int		move_count; // permettra de stocker les pas
	char	**map; //permet de stocker en memoire la map
	t_items	items; // nombre de collectible
	t_pos	plapos; // position du joueur sur la map
	t_img	image; // permet l'ajout d'image qu projet
}	t_data;

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct items_s
{
	char	exit;
	char	player;
	char	collect;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_items;

typedef struct s_imgs
{
	t_img_xpm	empty;
	t_img_xpm	player_a1;
	t_img_xpm	player_a2;
	t_img_xpm	wall;
	t_img_xpm	collectible;
	t_img_xpm	exit;
}	t_imgs;

typedef struct s_img_data
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_data;


//fonction affichage ouverture fermeture de la fenetre
void	ft_window(t_data *data, int width, int height, char *title);
int		ft_linux_echap(int keycode, t_data *data);
int		ft_macos_echap(int keycode, t_data *data);
int		ft_window_close(t_data *data);

//Fonction verification de validité de la map
void	collect_check(t_data *data);
void	exit_check(t_items *data, t_data *datamap);
void	wall_check(t_items *data, t_data *datamap);
void	player_check(t_items *data, t_data *datamap);
void	map_validation(t_data *data);

//Fonction d'initialisation des structures
void	ft_initialisation(t_items *ini);
void	ft_setmap(t_data *data);

//Fonctions de lecture de la map
char	ft_free(t_data *data); //vide la memoire
int		map_parseur(t_data *data, int fd); //collecte les data
char	*get_map(int fd); // lecture de la map

//Fonction de deplacement du joueur
int		keypress(int keycode, t_pos *pos, t_data *data);

//fonctions affichage

#endif