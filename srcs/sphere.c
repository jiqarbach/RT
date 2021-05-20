/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:52:19 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/27 09:52:22 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	limeted_sph(t_obj *sph, t_ray r, t_sol sol)
{
	t_vect	sly;
	int		is;

	sly = sph->slice;
	if (!sly.x && !sly.y && !sly.z)
		is = 0;
	else
		is = 1;
	if (is == 1 && dot(moins(sph->pos_slice, sph->hit), sly) <= 0.0)
	{
		sph->hit = plus(r.org, multi(r.dir, sol.tmax));
		if (sol.tmax > 0 && dot(moins(sph->pos_slice, sph->hit), sly) > 0.0)
		{
			sph->normal = normalize(multi(sph->normal, -1));
			return (sol.tmax);
		}
		return (-1);
	}
	return (sol.tmin);
}

double	sphrintr(t_obj **sphere, t_ray ray)
{
	t_vect	oc;
	t_math	calc;
	t_sol	sol;

	oc = moins(ray.org, (*sphere)->center);
	calc.a = dot(ray.dir, ray.dir);
	calc.b = 2 * dot(ray.dir, oc);
	calc.c = dot(oc, oc) - ((*sphere)->radius * (*sphere)->radius);
	calc.delta = (calc.b * calc.b) - (4 * calc.a * calc.c);
	sol = check_min_max(calc);
	(*sphere)->hit = plus(ray.org, multi(ray.dir, sol.tmin));
	(*sphere)->normal = normalize(moins((*sphere)->hit, (*sphere)->center));
	negative_objc(*sphere);
	sol.tmin = limeted_sph(*sphere, ray, sol);
	return (sol.tmin);
}

t_vect	normsphr(t_ray *ray, t_obj *obj, double t)
{
	t_vect	norm;

	ray->hit = plus(ray->org, multi(ray->dir, t));
	obj->hit = ray->hit;
	norm = moins(ray->hit, obj->center);
	return (normalize(norm));
}
