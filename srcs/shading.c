/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:46:21 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/24 13:40:21 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	init_shadow(t_rt *rt, t_lights *lights, t_vect *dirvect, double *dist)
{
	t_ray	shadow_r;

	shadow_r.org = lights->pos;
	*dirvect = moins(rt->ray.hit, lights->pos);
	*dist = dot(*dirvect, *dirvect);
	shadow_r.dir = normalize(*dirvect);
	return (shadow_r);
}

int	shadow(t_rt *rt, t_lights *lights, t_obj *close)
{
	t_obj	*tmpo;
	t_var	v;
	t_ray	shadow_r;
	t_vect	dirvect;
	double	dist;

	tmpo = rt->obj;
	shadow_r = init_shadow(rt, lights, &dirvect, &dist);
	while (tmpo)
	{
		if (tmpo->neg_obj == 0)
			v.t = intersect(&tmpo, shadow_r) + 0.01;
		if (tmpo != close && v.t > 0)
		{
			if (dot(multi(shadow_r.dir, v.t), multi(shadow_r.dir, v.t)) < dist)
			{
				if (tmpo->refr == 1)
					return (-1);
				return (0);
			}
		}
		tmpo = tmpo->next;
	}
	return (1);
}

t_color	diffuspclr(t_ray ray, t_obj *close, t_lights *lights)
{
	double		dot1;
	t_vect		lightdir;
	t_vect		reflect;
	t_color		c;

	c = (t_color){0, 0, 0};
	lightdir = normalize(moins(lights->pos, ray.hit));
	dot1 = dot(close->normal, lightdir);
	if (dot1 > 0)
	{
		c = multi_tcolor(close->color, multi_color(lights->color, 1.0 / 255));
		c = multi_color(c, dot1 * lights->intensity / 100.0);
	}
	reflect = normalize(moins(lightdir, multi(close->normal, 2 * dot1)));
	dot1 = dot(reflect, normalize(moins(ray.hit, ray.org)));
	if (dot1 > 0)
		c = add_color(c, multi_color(lights->color, powf(dot1, 100)
					* lights->intensity / 100.0));
	return (c);
}
