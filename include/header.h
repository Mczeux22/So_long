/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:18:22 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/06 19:27:37 by loicpapon        ###   ########.fr       */
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

typedef struct img_s
{
	// a completer lors de l'ajout des images pour permettre la gestion de la map
} t_img;

#endif