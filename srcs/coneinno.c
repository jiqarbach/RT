/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coneinno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:28:51 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/24 11:58:26 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	negative_objc(t_obj *obj)
{
	if (obj->neg_obj == 1)
	{
		obj->color = (t_vect){0, 0, 0};
		obj->normal = (t_vect){0, 0, 0};
		obj->texture = ft_strdup(".");
	}
}

double	coneintr(t_obj **cone, t_ray ray)
{
	t_vect	v;
	t_vect	oc;
	t_math	calc;
	t_sol	sol;
	double	k;

	oc = moins(ray.org, (*cone)->center);
	v = normalize((*cone)->v);
	v = rotation_xyz(v, (*cone)->rot);
	k = (*cone)->angle * M_PI / 180.0;
	k = tan(k / 2.0);
	calc.a = dot(ray.dir, ray.dir) - (1 + k * k)
		* dot(ray.dir, v) * dot(ray.dir, v);
	calc.b = 2 * (dot(ray.dir, oc) - (1 + k * k)
			* dot(ray.dir, v) * dot(oc, v));
	calc.c = dot(oc, oc) - (1 + k * k) * dot(oc, v) * dot(oc, v);
	calc.delta = (calc.b * calc.b) - (4 * calc.a * calc.c);
	sol = check_min_max(calc);
	(*cone)->normal = normalize(normcone(&ray, *cone, sol.tmin));
	(*cone)->hit = plus(ray.org, multi(ray.dir, sol.tmin));
	negative_objc(*cone);
	if ((*cone)->size != 0)
		sol.tmin = limeted_cone(*cone, ray, sol);
	return (sol.tmin);
}

t_vect	normcone(t_ray *ray, t_obj *obj, double t)
{
	double	k;
	double	m;
	t_vect	v;
	t_vect	oc;
	t_vect	norm;

	k = obj->angle * M_PI / 180.0;
	k = tan(k / 2.0);
	v = normalize(obj->v);
	v = rotation_xyz(v, obj->rot);
	ray->hit = plus(ray->org, multi(ray->dir, t));
	oc = moins(ray->org, obj->center);
	m = dot(ray->dir, v) * t + dot(oc, v);
	norm = moins(moins(ray->hit, obj->center), multi(v, (1 + k * k) * m));
	if (dot(norm, ray->dir) > 0)
		norm = multi(norm, -1.0);
	return (norm);
}
