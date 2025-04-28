/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:18:45 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:22:08 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_param(t_maps *m)
{
	free(m->item_x);
	free(m->item_y);
	free_map(m);
	free(m);
}

int	close_window_by_x(t_maps *m)
{
	return (finish_game(m), 0);
}

int	main(int ac, char **av)
{
	t_maps	*m;

	if (ac < 2)
		return (write(2, "missing file\n", 13), 0);
	if (ac > 2)
		return (write(2, "so much files\n", 14), 0);
	if (verif_file(av) == 1)
		return (perror("invalid file\n"), 0);
	m = malloc(sizeof(t_maps));
	if (m == NULL)
		return (perror("Error malloc struct\n"), 0);
	if (get_map(m, av[1]) == 1)
		return (0);
	if (verif_map(m) == 1)
		return (free_map2(m->map), free(m), 0);
	init_window(m);
}
