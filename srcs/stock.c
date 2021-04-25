/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:48:53 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/07 14:53:03 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	checkcolorvalue(char **value)
{
	t_color	abs;

	abs = stk(value);
	if (abs.x < 0)
		abs.x = 0;
	if (abs.y < 0)
		abs.y = 0;
	if (abs.z < 0)
		abs.z = 0;
	if (abs.x > 255)
		abs.x = 255;
	if (abs.y > 255)
		abs.y = 255;
	if (abs.z > 255)
		abs.z = 255;
	return (abs);
}

t_vect	stk(char **value)
{
	t_vect	new;

	new.x = ft_atoi(value[1]);
	new.y = ft_atoi(value[2]);
	new.z = ft_atoi(value[3]);
	return (new);
}
