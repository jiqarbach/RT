/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:05:50 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:11 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_2d_i	plane_uv(t_obj *obj, t_2d_i size, t_vect hit)
{
	double	u;
	double	v;
	t_2d_i	uv;
	t_vect	u_axis;
	t_vect	v_axis;

	u_axis = (t_vect){obj->normal.y, obj->normal.z, -obj->normal.x};
	v_axis = crosspro(u_axis, obj->normal);
	u = dot(hit, u_axis) * 0.05;
	v = dot(hit, v_axis) * 0.05;
	u = u - floor(u);
	v = v - floor(v);
	uv.i = (int)(u * (size.i - 1));
	uv.j = (int)(v * (size.j - 1));
	return (uv);
}

int	ft_clamp(int value, int min, int max)
{
	if (value <= min)
		return (min);
	if (value >= max)
		return (max);
	return (value);
}

t_2d_i	sphere_uv(t_obj *obj, t_2d_i size, t_vect hit)
{
	t_vect	p;
	double	phi;
	double	u;
	double	v;
	t_2d_i	uv;

	p = normalize(moins(hit, obj->center));
	phi = acos(dot((t_vect){0, 1, 0}, p));
	if (atan2(p.z, p.x) < 0)
		u = 0 - atan2(p.z, p.x) / (2 * M_PI);
	if (atan2(p.z, p.x) >= 0)
		u = 1 - atan2(p.z, p.x) / (2 * M_PI);
	v = phi / M_PI;
	uv.i = (int)(size.i * u);
	uv.j = (int)(size.j * v);
	uv.i = ft_clamp((int)(size.i * u) % size.i, 0, size.i - 1);
	uv.j = ft_clamp((int)(size.j * v) % size.j, 0, size.j - 1);
	return (uv);
}

t_2d_i	uv_mapping_cyl_cone(t_obj *obj, t_2d_i size, t_vect hit)
{
	 t_vect	p;
	 double	theta;
	 double	u;
	 double	v;
	 t_2d_i	uv;

	p = moins(hit, obj->center);
	theta = atan2(p.z, p.x);
	if (theta < 0)
		u = 0 - theta / (2 * M_PI);
	if (theta >= 0)
		u = 1 - theta / (2 * M_PI);
	v = p.y / -10;
	v = v - floor(v);
	uv.i = ft_clamp((int)(size.i * u) % size.i, 0, size.i - 1);
	uv.j = ft_clamp((int)(size.j * v) % size.j, 0, size.j - 1);
	return (uv);
}

t_2d_i	get_uv(t_obj *obj, t_2d_i size, t_vect hit)
{
	t_2d_i	uv;

	if (obj->type == SPHERE)
		uv = sphere_uv(obj, size, hit);
	if (obj->type == CYLINDER || obj->type == CONE)
		uv = uv_mapping_cyl_cone(obj, size, hit);
	if (obj->type == PLANE)
		uv = plane_uv(obj, size, hit);
	return (uv);
}
