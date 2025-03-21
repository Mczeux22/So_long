/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:50:51 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/21 12:11:52 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_map(int fd) // lecture de la map
{
	
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
int	map_parseur() // parse la map pour voir les informations
{
	
}

