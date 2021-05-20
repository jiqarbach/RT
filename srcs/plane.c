/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:36:08 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 16:34:28 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	plan_slice(t_obj *pln, double t)
{
	int	is;

	if (!pln->slice.x && !pln->slice.y && !pln->slice.z)
		is = 0;
	else
		is = 1;
	if (is == 1 && dot(moins(pln->pos_slice, pln->hit), pln->slice) <= 0.0)
		return (-1);
	return (t);
}

double	limeted_plan(t_obj *pln, t_ray r, double t)
{
	t_vect		hit;

	hit = moins(pln->hit, pln->center);
	if (t == -1)
		return (-1);
	if ((hit.y > pln->center.y + pln->size / 2
			|| hit.y < pln->center.y - pln->size / 2) && pln->v.y == 0)
		return (-1);
	if ((hit.x > pln->center.x + pln->size / 2
			|| hit.x < pln->center.x - pln->size / 2) && pln->v.x == 0)
		return (-1);
	if ((hit.z > pln->center.z + pln->size / 2
			|| hit.z < pln->center.z - pln->size / 2) && pln->v.z == 0)
		return (-1);
	return (t);
}

double	planiter(t_obj **plan, t_ray ray)
{
	double	nomi;
	double	dinomi;
	double	t;

	nomi = dot(moins(ray.org, (*plan)->center), (*plan)->v);
	dinomi = dot(ray.dir, (*plan)->v);
	if ((dinomi == 0) || (nomi <= 0 && dinomi < 0) || (nomi >= 0
			&& dinomi > 0))
		return (-1);
	t = -nomi / dinomi;
	if (t < 0)
		return (-1);
	(*plan)->hit = plus(ray.org, multi(ray.dir, t));
	(*plan)->normal = normalize((*plan)->v);
	if (dot((*plan)->normal, ray.dir) > 0)
		(*plan)->normal = multi((*plan)->v, -1);
	negative_objc(*plan);
	t = plan_slice(*plan, t);
	if ((*plan)->size != 0)
		t = limeted_plan(*plan, ray, t);
	return (t);
}
