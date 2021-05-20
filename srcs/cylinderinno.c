/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinderinno.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:50:39 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/27 09:50:45 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	cyldintr(t_obj **cyld, t_ray ray)
{
	t_vect	v;
	t_vect	oc;
	t_math	calc;
	t_sol	sol;

	oc = moins(ray.org, (*cyld)->center);
	v = normalize((*cyld)->v);
	v = normalize(rotation_xyz(v, (*cyld)->rot));
	calc.a = dot(ray.dir, ray.dir) - dot(ray.dir, v) * dot(ray.dir, v);
	calc.b = 2 * (dot(ray.dir, oc) - dot(ray.dir, v) * dot(oc, v));
	calc.c = dot(oc, oc) - dot(oc, v) * dot(oc, v)
		- ((*cyld)->radius * (*cyld)->radius);
	calc.delta = (calc.b * calc.b) - (4 * calc.a * calc.c);
	sol = check_min_max(calc);
	(*cyld)->normal = normalize(normcyld(&ray, *cyld, sol.tmin));
	(*cyld)->hit = plus(ray.org, multi(ray.dir, sol.tmin));
	negative_objc(*cyld);
	if ((*cyld)->size != 0)
		return (limeted_cly(*cyld, ray, sol));
	return (sol.tmin);
}

t_vect	normcyld(t_ray *ray, t_obj *obj, double t)
{
	double	m;
	t_vect	v;
	t_vect	oc;
	t_vect	norm;

	v = normalize(obj->v);
	v = normalize(rotation_xyz(v, obj->rot));
	ray->hit = plus(ray->org, multi(ray->dir, t));
	obj->hit = ray->hit;
	oc = moins(ray->org, obj->center);
	m = dot(ray->dir, v) * t + dot(oc, v);
	norm = moins(moins(ray->hit, obj->center), multi(v, m));
	if (dot(norm, ray->dir) > 0)
		norm = multi(norm, -1.0);
	return (norm);
}
