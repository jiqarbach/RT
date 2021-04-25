/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:37:40 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/23 15:38:08 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	comp(double x, double y, double z)
{
	if (x < y)
		return (y);
	if (x > z)
		return (z);
	return (x);
}

int	light_direct(t_rt rt, t_ray ray)
{
	double	cutoff;
	double	outcutoff;
	double	theta;
	double	intensity;

	cutoff = cos(rt.light->angle * M_PI / 180);
	outcutoff = cos((rt.light->angle + 3) * M_PI / 180);
	theta = dot(rt.light->to_light.direction, normalize(rt.light->center));
	intensity = comp((theta - outcutoff) / cutoff - outcutoff, 0.0, 1.0);
	return (intensity);
}
