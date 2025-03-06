/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:08:08 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/06 19:30:25 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_initialisation(t_items *ini)
{
	ini->exit = 'E';
	ini->player = 'P';
	ini->collect = 'C';
	ini->wall = '1';
	ini->space = '0';
	ini->count_p = 0;
	ini->count_e = 0;
	ini->count_c = 0;
}

void	ft_setmap(t_data *data)
{
	// setmap avec les outils de la minilibX 
}