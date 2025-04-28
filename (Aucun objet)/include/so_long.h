/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:56:02 by Lopapon           #+#    #+#             */
/*   Updated: 2025/04/28 00:56:05 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdarg.h>
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

# ifndef S
#  define S 32
# endif

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}	t_list;

typedef struct s_maps
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**copie;
	int		largeur;
	int		hauteur;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		*item_x;
	int		*item_y;
	int		item_count;
	int		nb_case;
	int		check;
	int		count_move;
	int		pos_player_y;
	int		pos_player_x;
	void	*exit;
	void	*perso;
	void	*dol;
	void	*mur;
	void	*sol;
	void	*pers2;
}	t_maps;

int		ft_putchar(int c);
int		hexa(long n, int maj);
int		ft_putnbr(long n);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		adr_hexa(unsigned long n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int size);
int		ft_chr(char *str, int *nb_read);
char	*ft_read(int fd, int *nb_read, char *buf, char *stach);
char	*ft_get_line(char *stach, int size);
char	*ft_start_line(char *stach, int size);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		verif_file(char **av);
int		get_map(t_maps *m, char *av);
int		verif_charac(t_maps *m);
int		count_item(t_maps *m);
int		count_player(t_maps *m);
int		count_exit(t_maps *m);
int		get_size_map(t_maps *m);
int		verif_map(t_maps *m);
int		verif_mur(t_maps *m);
void	get_exit_postion(t_maps *m);
void	get_item_postion(t_maps *m);
void	get_player_postion(t_maps *m);
void	init_item_tab(t_maps *m);
size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**init_temp_map(t_maps *m);
t_list	*create_node(t_list **list, int x, int y);
void	add_back(t_list **list, int x, int y);
void	delate_first(t_list **list);
int		verif_chemin_exit(t_maps *m);
int		verif_chemin_item(t_maps *m);
int		found_if_chemin_item(t_maps *m, int target_x, int target_y);
int		found_if_chemin_exit(t_maps *m, int target_x, int target_y);
void	*ft_free(char **str, size_t j);
void	print_list(t_list *list);
void	clear_list(t_list **list);
int		init_window(t_maps *m);
int		close_window(int keycode, t_maps *m);
int		close_window_by_x(t_maps *m);
int		recup_image(t_maps *m);
int		make_map(t_maps *m);
void	make_map_second(t_maps *m);
void	make_map_first(t_maps *m);
void	play_game(int keycode, t_maps *m);
int		v_i(t_list *list, char **map, int n);
void	pos_x(t_maps *m);
void	print_move(t_maps *m);
void	pos_y(t_maps *m);
void	play_game_2(int keycode, t_maps *m);
void	move_left(t_maps *m);
void	move_right(t_maps *m);
void	move_up(t_maps *m);
void	move_down(t_maps *m);
int		verif_nb_charac(t_maps *m);
void	free_map(t_maps *m);
void	free_map2(char **map);
void	free_image(t_maps *m);
void	finish_game(t_maps *m);
void	free_image2(t_maps *m);
void	free_param(t_maps *m);

#endif