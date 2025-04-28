/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:18:54 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:22:05 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*create_node(t_list **list, int x, int y)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = *list;
	*list = new;
	return (new);
}

void	add_back(t_list **list, int x, int y)
{
	t_list	*temp;
	t_list	*new;

	temp = *list;
	if (*list == NULL)
	{
		create_node(list, x, y);
		return ;
	}
	new = ft_calloc(1, sizeof(t_list));
	if (new == NULL)
		return ;
	new->x = x;
	new->y = y;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	delate_first(t_list **list)
{
	t_list	*temp;

	if (*list == NULL)
		return ;
	temp = *list;
	*list = temp->next;
	free(temp);
}

void	clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}
