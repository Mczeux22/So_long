/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:19:39 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:19:39 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free(char **str, size_t j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free (str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(size * count);
	if (str == NULL)
		return (NULL);
	ft_bzero (str, count * size);
	return ((void *)str);
}

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		printf("Node %d -> x: %d | y: %d\n", i, list->x, list->y);
		list = list->next;
		i++;
	}
}

void	free_map2(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_maps *m)
{
	int	i;

	i = 0;
	while (m->map[i] != NULL && i < 100)
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
}
