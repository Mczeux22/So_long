/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:12:56 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/21 14:33:27 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypress(int keycode, t_pos *pos, t_data *data)
{
	if (keycode == 119)
		pos->plapos.y -= 10;
	if (keycode == 115)
		pos->playpos.y += 10;
	if (keycode == 97)
		pos->playpos.x -= 10;
	if (keycode == 100)
		pos->playpos.x += 10;
	
}