/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:05:44 by yataji            #+#    #+#             */
/*   Updated: 2021/04/02 20:25:00 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	rot_x(t_vect v, double angle)
{
	double	delta;
	t_vect	result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x;
	result.y = v.y * cos(delta) - v.z * sin(delta);
	result.z = v.y * sin(delta) + v.z * cos(delta);
	return (result);
}

t_vect	rot_y(t_vect v, double angle)
{
	double	delta;
	t_vect	result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) + v.z * sin(delta);
	result.y = v.y;
	result.z = v.z * cos(delta) - v.x * sin(delta);
	return (result);
}

t_vect	rot_z(t_vect v, double angle)
{
	double	delta;
	t_vect	result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) - v.y * sin(delta);
	result.y = v.x * sin(delta) + v.y * cos(delta);
	result.z = v.z;
	return (result);
}

t_vect	rotation_xyz(t_vect v, t_vect a)
{
	t_vect	result;

	if (!a.x && !a.y && !a.z)
		return (v);
	result = rot_x(v, a.x);
	result = rot_y(result, a.y);
	result = rot_z(result, a.z);
	return (result);
}
