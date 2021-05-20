/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraploid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:32:04 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/25 16:01:54 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	parapinter(t_obj **para, t_ray ray)
{
	t_math	math;
	t_sol	sol;
	t_vect	x;
	double	m;

	x = moins(ray.org, (*para)->center);
	math.a = dot(ray.dir, ray.dir) - pow(dot(ray.dir, (*para)->v), 2);
	math.b = 2 * (dot(ray.dir, x) - dot(ray.dir, (*para)->v)
			* (dot(x, (*para)->v) + 2 * (*para)->angle));
	math.c = dot(x, x) - dot(x, (*para)->v) * (dot(x, (*para)->v) + 4 *\
				(*para)->angle);
	math.delta = math.b * math.b - 4 * math.a * math.c;
	sol = check_min_max(math);
	(*para)->hit = plus(ray.org, multi(ray.dir, sol.tmin));
	m = dot(moins((*para)->hit, (*para)->center), (*para)->v);
	(*para)->normal = normalize(moins(moins((*para)->hit, (*para)->center),
				multi((*para)->v, m + (*para)->angle)));
	return (sol.tmin);
}
