/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:56:21 by yataji            #+#    #+#             */
/*   Updated: 2021/04/24 11:49:19 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	cone_slice(t_obj *cone, t_ray r, t_sol sol, t_vect sly)
{
	cone->hit = plus(r.org, multi(r.dir, sol.tmax));
	if (sol.tmax > 0 && dot(moins(cone->pos_slice, cone->hit), sly) > 0.0)
	{
		cone->normal = normalize(multi(cone->normal, -1));
		return (sol.tmax);
	}
	return (-1);
}

double	lim_cone_y(t_obj *cone, t_vect hit, double tmax, t_ray r)
{
	t_vect		hit2;

	if (hit.y >= cone->center.y + cone->size / 2
		|| hit.y <= cone->center.y - cone->size / 2)
	{
		cone->hit = plus(r.org, multi(r.dir, tmax));
		hit2 = moins(cone->hit, cone->center);
		cone->normal = multi(cone->normal, -1);
		if (hit2.y >= cone->center.y + cone->size / 2
			|| hit2.y <= cone->center.y - cone->size / 2)
			return (-1);
	}
	return (tmax);
}

double	lim_cone_x(t_obj *cone, t_vect hit, double tmax, t_ray r)
{
	t_vect		hit2;

	if (hit.x >= cone->center.x + cone->size / 2
		|| hit.x <= cone->center.x - cone->size / 2)
	{
		cone->hit = plus(r.org, multi(r.dir, tmax));
		hit2 = moins(cone->hit, cone->center);
		cone->normal = multi(cone->normal, -1);
		if (hit2.x >= cone->center.x + cone->size / 2
			|| hit2.x <= cone->center.x - cone->size / 2)
			return (-1);
	}
	return (tmax);
}

double	lim_cone_z(t_obj *cone, t_vect hit, double tmax, t_ray r)
{
	t_vect	hit2;

	if (hit.z >= cone->center.z + cone->size / 2
		|| hit.z <= cone->center.z - cone->size / 2)
	{
		cone->hit = plus(r.org, multi(r.dir, tmax));
		hit2 = moins(cone->hit, cone->center);
		cone->normal = multi(cone->normal, -1);
		if (hit2.z >= cone->center.z + cone->size / 2
			|| hit2.z <= cone->center.z - cone->size / 2)
			return (-1);
	}
	return (tmax);
}

double	limeted_cone(t_obj *cone, t_ray r, t_sol sol)
{
	t_vect	up;
	t_vect	hit;
	int		is;

	if (!cone->slice.x && !cone->slice.y && !cone->slice.z)
		is = 0;
	else
		is = 1;
	if (is == 1 && dot(moins(cone->pos_slice, cone->hit), cone->slice) <= 0.0)
		return (cone_slice(cone, r, sol, cone->slice));
	hit = moins(cone->hit, cone->center);
	if (cone->v.y == 1)
		return (lim_cone_y(cone, hit, sol.tmax, r));
	if (cone->v.x == 1)
		return (lim_cone_x(cone, hit, sol.tmax, r));
	if (cone->v.z == 1)
		return (lim_cone_z(cone, hit, sol.tmax, r));
	return (sol.tmin);
}
