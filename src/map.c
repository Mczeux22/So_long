/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:50:51 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/21 13:48:30 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_map(int fd) // lecture de la map
{
	char	*line;
	char	*map;
	char	*temp;

	line = get_next_line(fd);
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (line != NULL)
	{
		temp = ft_strjoin(map, line);
		free(map);
		free(line);
		if (!temp)
			return (NULL);
		map = temp;
	}
	return (map);
}

char	ft_free(t_data *data) // permet de liberer les mallocs de getmap
{
	static int	i = 0;

	while (data->map[i] != NULL)
	{
		free (data->map[i]);
		i++;
	}
	free (data->map);
	data->map = NULL;
	return (1);
}

int	map_parseur(t_data *data, int fd)
{
	char	*map_str;
	int		x;
	int		y;

	map_str = get_map(fd);
	if (!map_str)
		return (0);

	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (!data->map)
		return (0);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->items.wall)
				;
			else if (data->map[y][x] == data->items.player)
			{
				data->plapos.x = x;
				data->plapos.y = y;
			}
			else if (data->map[y][x] == data->items.collect)
				data->items.collect++;
			x++;
		}
		y++;
	}
	return (1);
}
