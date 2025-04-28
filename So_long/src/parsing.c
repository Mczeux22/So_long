/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:19:31 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:21:24 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(t_maps *m, char *av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (free(m), perror("error open file\n"), 1);
	m->map = ft_calloc(1000, sizeof(char *));
	if (m->map == NULL)
		return (free(m), perror("error malloc map\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		m->map[i++] = line;
		if (i >= 100)
			break ;
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}

int	verif_nb_charac(t_maps *m)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (m->map[i][j])
		j++;
	count = j;
	i++;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
			j++;
		if (count != j)
			return (1);
		i++;
	}
	return (0);
}

int	verif_mur(t_maps *m)
{
	int	i;

	i = 0;
	while (i < (m->largeur - 1))
	{
		if (m->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < (m->largeur -1))
	{
		if (m->map[m->hauteur - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < (m->hauteur -1))
	{
		if (m->map[i][0] != '1' || m->map[i][m->largeur - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	verif_file(char **av)
{
	int	size;

	size = ft_strlen(av[1]) - 1;
	if (av[1][size] != 'r')
		return (1);
	if (av[1][size - 1] != 'e')
		return (1);
	if (av[1][size - 2] != 'b')
		return (1);
	if (av[1][size - 3] != '.')
		return (1);
	return (0);
}

int	verif_map(t_maps *m)
{
	m->count_move = 0;
	m->check = 0;
	if (verif_charac(m) == 1)
		return (perror("Error\nWrong character\n"), 1);
	if (count_item(m) < 1)
		return (perror("Error\nMissing item\n"), 1);
	if (count_player(m) != 1)
		return (perror("Error\nNumber of player\n"), 1);
	if (count_exit(m) != 1)
		return (perror("Error\nNumber of exit\n"), 1);
	if (get_size_map(m) == 1)
		return (perror("Error\nMap carrée\n"), 1);
	if (verif_nb_charac(m) == 1)
		return (perror("Error\nMauvaise dimensions map\n"), 1);
	if (verif_mur(m) == 1)
		return (1);
	if (verif_chemin_exit(m) == 1)
		return (perror("Error\nChemin de sortie\n"), 1);
	if (verif_chemin_item(m) == 1)
		return (perror("Error\nChemin item\n"), 1);
	return (0);
}
