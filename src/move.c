/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:12:56 by loicpapon         #+#    #+#             */
/*   Updated: 2025/03/21 18:00:12 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypress(int keycode, t_pos *pos, t_data *data)
{
	if (keycode == 119)
		data->plapos.y -= 10;
	if (keycode == 115)
		data->plapos.y += 10;
	if (keycode == 97)
		data->plapos.x -= 10;
	if (keycode == 100)
		data->plapos.x += 10;
	
}